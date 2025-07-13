#!/bin/bash

#if [ -z "$1" ]; then
#  echo "Erreur : aucun fichier spécifié."
#  echo "Usage : $0 <nom_du_fichier.chrpp>"
#  exit 1
#fi

cd build
cmake ..
make
cd ..

./build/converter $@
