
# Projet de Planification des Processus

Ce projet implémente et simule les algorithmes de planification des processus Shortest Job First (SJF) et Shortest Remaining Time First (SRTF) en langage C. Il vise à illustrer les principes théoriques de ces algorithmes et à évaluer leurs performances.

## Contenu du Projet

- `ordonnancement_processus.h` : Déclarations de structures et prototypes de fonctions.
- `ordonnancement_processus.c` : Implémentation des algorithmes SJF et SRTF.
- `main.c` : Programme principal qui gère les entrées utilisateur et appelle les fonctions de planification.
- `Makefile` : Automatisation de la compilation.
- `README.md` : Description du projet.

## Structure du Code

### `ordonnancement_processus.h`

Déclare la structure `Processus` et les prototypes des fonctions `calculer_sjf`, `calculer_srtf` et `afficher_processus`.

```c
#ifndef ORDONNANCEMENT_PROCESSUS_H
#define ORDONNANCEMENT_PROCESSUS_H

// Structure représentant un processus
typedef struct {
    int id;               // ID du processus
    int temps_arrivee;    // Temps d'arrivée du processus
    int duree;            // Durée du processus
    int temps_restant;    // Temps restant pour le processus
    int temps_depart;     // Temps de départ du processus
    int temps_completion; // Temps de complétion du processus
    int temps_attente;    // Temps d'attente du processus
    int temps_retour;     // Temps de retour du processus
} Processus;

// Prototype des fonctions
void calculer_sjf(Processus processus[], int n);
void calculer_srtf(Processus processus[], int n);
void afficher_processus(Processus processus[], int n);

#endif // ORDONNANCEMENT_PROCESSUS_H
