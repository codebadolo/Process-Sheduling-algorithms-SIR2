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