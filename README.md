
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
```

```c
#include <stdio.h>
#include "ordonnancement_processus.h"

// Fonction pour calculer le planning SJF
void calculer_sjf(Processus processus[], int n) {
    // Tri des processus par temps d'arrivée puis par durée de rafale
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processus[j].temps_arrivee > processus[j + 1].temps_arrivee || 
                (processus[j].temps_arrivee == processus[j + 1].temps_arrivee && processus[j].duree > processus[j + 1].duree)) {
                Processus temp = processus[j];
                processus[j] = processus[j + 1];
                processus[j + 1] = temp;
            }
        }
    }
    // Calcul des temps d'attente et de retour
    int temps_courant = 0;
    for (int i = 0; i < n; i++) {
        if (temps_courant < processus[i].temps_arrivee) {
            temps_courant = processus[i].temps_arrivee;
        }
        processus[i].temps_depart = temps_courant;
        processus[i].temps_completion = processus[i].temps_depart + processus[i].duree;
        processus[i].temps_retour = processus[i].temps_completion - processus[i].temps_arrivee;
        processus[i].temps_attente = processus[i].temps_retour - processus[i].duree;
        temps_courant += processus[i].duree;
    }
}

// Fonction pour calculer le planning SRTF
void calculer_srtf(Processus processus[], int n) {
    int temps = 0, termines = 0, min_temps_restant = 9999, plus_court = 0, temps_fin;
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        processus[i].temps_restant = processus[i].duree;
    }
    while (termines != n) {
        for (int i = 0; i < n; i++) {
            if (processus[i].temps_arrivee <= temps && processus[i].temps_restant < min_temps_restant && processus[i].temps_restant > 0) {
                min_temps_restant = processus[i].temps_restant;
                plus_court = i;
                trouve = 1;
            }
        }
        if (!trouve) {
            temps++;
            continue;
        }
        processus[plus_court].temps_restant--;
        min_temps_restant = processus[plus_court].temps_restant;
        if (min_temps_restant == 0) {
            min_temps_restant = 9999;
        }
        if (processus[plus_court].temps_restant == 0) {
            termines++;
            temps_fin = temps + 1;
            processus[plus_court].temps_completion = temps_fin;
            processus[plus_court].temps_retour = temps_fin - processus[plus_court].temps_arrivee;
            processus[plus_court].temps_attente = processus[plus_court].temps_retour - processus[plus_court].duree;
        }
        temps++;
    }
}

// Fonction pour afficher les détails des processus
void afficher_processus(Processus processus[], int n) {
    int total_attente = 0, total_retour = 0;
    printf("\nID\tArrivée\tDurée\tDépart\tComplétion\tAttente\tRetour\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               processus[i].id, processus[i].temps_arrivee, processus[i].duree,
               processus[i].temps_depart, processus[i].temps_completion,
               processus[i].temps_attente, processus[i].temps_retour);
        total_attente += processus[i].temps_attente;
        total_retour += processus[i].temps_retour;
    }
    printf("\nTemps d'attente moyen: %.2f\n", (double) total_attente / n);
    printf("Temps de retour moyen: %.2f\n", (double) total_retour / n);
}
#endif
