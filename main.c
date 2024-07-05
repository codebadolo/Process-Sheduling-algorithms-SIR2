#include <stdio.h>
#include "ordonnancement_processus.h"

int main() {
    int n, choix;
    printf("Entrez le nombre de processus : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Erreur : nombre de processus invalide.\n");
        return 1;
    }
    Processus processus[n];
    for (int i = 0; i < n; i++) {
        processus[i].id = i + 1;
        printf("Entrez le temps d'arrivée et la durée pour le processus %d : ", i + 1);
        if (scanf("%d %d", &processus[i].temps_arrivee, &processus[i].duree) != 2 || 
            processus[i].temps_arrivee < 0 || processus[i].duree <= 0) {
            fprintf(stderr, "Erreur : entrée invalide pour le processus %d.\n", i + 1);
            return 1;
        }
    }
    printf("Choisissez l'algorithme de planification (1 pour SJF, 2 pour SRTF) : ");
    if (scanf("%d", &choix) != 1 || (choix != 1 && choix != 2)) {
        fprintf(stderr, "Erreur : choix d'algorithme invalide.\n");
        return 1;
    }
    if (choix == 1) {
        calculer_sjf(processus, n);
    } else {
        calculer_srtf(processus, n);
    }
    afficher_processus(processus, n);
    return 0;
}