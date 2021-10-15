#include <stdio.h>
#include <stdlib.h>

struct Joueur
{
    int experience;
    int niveau;
    int pointDeVieCourant;
    int pointDeVieMax;
    int inventaire[10][3];
};
typedef struct Joueur Joueur;

void StatDepartJoueur(Joueur*);



int main(int argc, const char *argv[]) {
    Joueur joueurStruct;
    //Stat du joueur au début de la partie
    StatDepartJoueur(&joueurStruct);
    
    return 0;
}
void StatDepartJoueur(Joueur* joueurDebut) {
    joueurDebut->niveau = 1;
    joueurDebut->pointDeVieCourant = 100;
    joueurDebut->pointDeVieMax = 100;
    joueurDebut->inventaire[0][0] =  1;
    joueurDebut->inventaire[0][1] =  10;
    joueurDebut->inventaire[0][2] =  1;
    joueurDebut->inventaire[1][0] =  2;
    joueurDebut->inventaire[1][1] =  10;
    joueurDebut->inventaire[1][2] =  0;
    joueurDebut->inventaire[2][0] =  3;
    joueurDebut->inventaire[2][1] =  10;
    joueurDebut->inventaire[2][2] =  0;
    joueurDebut->inventaire[3][0] =  4;
    joueurDebut->inventaire[3][1] =  10;
    joueurDebut->inventaire[3][2] =  0;
}






