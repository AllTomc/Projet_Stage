#!/bin/bash

# Vérifier si un argument a été passé
if [ -z "$1" ]; then
  echo "Erreur : aucun fichier spécifié."
  echo "Usage : $0 <nom_du_fichier.chrpp>"
  exit 1
fi

# Variables
SOURCE_FILE=$1            # Le fichier source passé en argument
BASE_NAME=$(basename "$SOURCE_FILE" .chrpp)   # Nom sans extension
BUILD_DIR="build"         # Dossier de construction
BIN_DIR="bin"             # Dossier pour l'exécutable
INSTALL_DIR="./ext/chrpp/build"
#INSTALL_DIR="./ext/chrpp"
# Créer les répertoires nécessaires s'ils n'existent pas
mkdir -p "$BUILD_DIR"
mkdir -p "$BIN_DIR"

# Prétraiter le fichier CHR++ en utilisant chrppc
echo "Prétraitement du fichier $SOURCE_FILE avec chrppc..."
#"$INSTALL_DIR/usr/local/bin/chrppc" "$SOURCE_FILE" --stdout > "$BUILD_DIR/$BASE_NAME.cpp"
"$INSTALL_DIR/chrppc/chrppc"   "$SOURCE_FILE" --stdout > "$BUILD_DIR/$BASE_NAME.cpp"

# Compiler le fichier C++ généré avec g++
echo "Compilation du fichier C++..."
#g++ -O3 -std=c++17 -I "$INSTALL_DIR/usr/local/include/chrpp" -DENABLE_STATISTICS -DENABLE_TRACE "$BUILD_DIR/$BASE_NAME.cpp" -o "$BIN_DIR/$BASE_NAME"
g++ -O3 -std=c++17 -I "$INSTALL_DIR/runtime" -I "ext/solvint" -I "$INSTALL_DIR/../runtime" -DENABLE_STATISTICS -DENABLE_TRACE "$BUILD_DIR/$BASE_NAME.cpp" -o "$BIN_DIR/$BASE_NAME"

# Vérifier si la compilation a réussi
if [ $? -eq 0 ]; then
  echo "Compilation réussie ! Exécution du programme..."

  # Exécuter le programme
  ./"$BIN_DIR/$BASE_NAME"
else
  echo "Erreur de compilation."
  exit 1
fi
