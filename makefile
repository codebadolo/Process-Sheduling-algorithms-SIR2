CC = gcc
CFLAGS = -Wall
OBJ = main.o ordonnancement_processus.o

# Cible principale
tout: srtf

# Cible pour générer l'exécutable
srtf: $(OBJ)
	$(CC) $(CFLAGS) -o srtf $(OBJ)

# Cible pour compiler le fichier main.c
main.o: main.c ordonnancement_processus.h
	$(CC) $(CFLAGS) -c main.c

# Cible pour compiler le fichier ordonnancement_processus.c
ordonnancement_processus.o: ordonnancement_processus.c ordonnancement_processus.h
	$(CC) $(CFLAGS) -c ordonnancement_processus.c

# Cible pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f *.o srtf