# Projet_Stage – Transformations XCSP3 vers CHR

## Installation & Compilation

### Option 1 : Clonage manuel avec sous-modules à importer

Clonez le dépôt principal :

```bash
git clone https://github.com/AllTomc/Projet_Stage.git
cd Projet_Stage
```

Puis clonez manuellement les sous-modules nécessaires dans le dossier `ext/` :

- [`chrpp`](https://gitlab.com/vynce/chrpp) :
  ```bash
  git clone https://gitlab.com/vynce/chrpp ext/chrpp
  ```
- [`XCSP3-CPP-Parser`](https://github.com/xcsp3team/XCSP3-CPP-Parser) :
  ```bash
  git clone https://github.com/xcsp3team/XCSP3-CPP-Parser ext/XCSP3-CPP-Parser
  ```

### Option 2 : Clonage avec sous-modules 

```bash
git clone --recurse-submodules https://github.com/AllTomc/Projet_Stage.git
```

---

### ⚙️ Compilation

#### 1. Compilation du sous-module `chrpp` :

```bash
cd ext/chrpp
mkdir build
cd build
cmake ..
make
```

#### 2. Compilation du projet principal :

```bash
# retour à la racine du projet
mkdir build
cd build
cmake ..
make
```

Ou utilisez le script pour parser une instance qui compile également le projet :

```bash
./parserXCSPtoCHR.sh instances/nom_instance.xml
```

---

## Utilisation du parseur

Le parseur convertit des instances XCSP3 en règles CHR, par défaut l'ensemble des règles sont traduites puis est renvoyé dans le terminal uniquement le bloc de règles CHR.

```bash
./parserXCSPtoCHR.sh [options] <instance.xml>
```

### Options disponibles

- `-b` : Utiliser `CHRStructBuilder` et avoir une proposition de fichier .chrpp
         complet (fonctions, bloc CHR, main).
- `-m` : Mode minimal (réduction de certaines déclarations). 
- `-s [r1,r2,...]` : Ne parser que certaines règles (par exemple : `linear`, `allDifferent`, etc.)
- `-f` : Écriture vers un fichier de sortie `out/[filename].chrpp`

### Exemple :

```bash
./parserXCSPtoCHR.sh -b -m -s linear,allDifferent instances/instance0.xml
```

---

## Arborescence recommandée

```
Projet_Stage/
├── build/                  # Compilation du projet principal
├── ext/
│   ├── chrpp/              # Sous-module CHR++
│   └── XCSP3-CPP-Parser/   # Sous-module XCSP3
├── src/                    # Code source du parseur
├── parserXCSPtoCHR.sh      # Script de lancement parser
├── solveCHR.sh             # Script de lancement solveur
├── instances/              # Contient des fichiers XML à parser
└── out/                    # Contient les fichiers chrpp générés avec -f
```

---

