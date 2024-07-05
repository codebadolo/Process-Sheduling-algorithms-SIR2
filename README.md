# Projet de Planification des Processus

Ce projet implémente et simule les algorithmes de planification des processus Shortest Job First (SJF) et Shortest Remaining Time First (SRTF) en langage C. Il vise à illustrer les principes théoriques de ces algorithmes et à évaluer leurs performances.

## Contenu du Projet

- `ordonnancement_processus.h` : Déclarations de structures et prototypes de fonctions.
- `ordonnancement_processus.c` : Implémentation des algorithmes SJF et SRTF.
- `main.c` : Programme principal qui gère les entrées utilisateur et appelle les fonctions de planification.
- `Makefile` : Automatisation de la compilation.
- `README.md` : Description du projet.

## Structure du Code

- **ordonnancement_processus.h** : Contient les déclarations de la structure `Processus` et les prototypes des fonctions `calculer_sjf`, `calculer_srtf` et `afficher_processus`.
- **ordonnancement_processus.c** : Implémente les fonctions de planification SJF et SRTF, ainsi que la fonction d'affichage des résultats.
- **main.c** : Gère l'entrée utilisateur, la validation des entrées et appelle les fonctions de planification appropriées.

## Guide de Compilation

Pour compiler le projet, utilisez le `Makefile` fourni. Ouvrez un terminal dans le répertoire du projet et exécutez la commande suivante :

```sh
make
