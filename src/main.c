#include <stdio.h>
#include <stdlib.h>

struct Joueur
{
    int experience;
    int niveau;
    int pointDeVieCourant;
    int pointDeVieMax;
    int *inventaire;
};
typedef struct Joueur Joueur;

void StatDepartJoueur(Joueur*);

int main(int argc, const char *argv[]) {
    Joueur joueurStruct;
    StatDepartJoueur(&joueurStruct);
    return 0;
}

void StatDepartJoueur(Joueur* joueurDebut) {
    joueurDebut->niveau = 1;
    joueurDebut->pointDeVieCourant = 100;
    joueurDebut->pointDeVieMax = 100;
    joueurDebut->inventaire = malloc(sizeof(int)*10);
    joueurDebut->inventaire[0] =1;
    joueurDebut->inventaire[1] =2;
    joueurDebut->inventaire[2] =3;
    joueurDebut->inventaire[3] =4;
}



