#include "menu.h"

void startChoice() {
    int saveChoice=0;
    char buffer[10];
    int typeCharge = 0;
    int validationManuelle = -1;
    int validationAuto = -1;
    FILE *file;

    while (saveChoice != 3) {
        printf("\nCharger une partie ! Taper 1\n");
        printf("Nouvelle partie ! Taper 2\n");
        printf("Quitter Taper 3\n");
        fgets(buffer,10,stdin);
        fflush(stdin);
        saveChoice = atoi(buffer);
        system("cls");

        //charge
        if (saveChoice == 1) {
            printf("\nVoir les charges automatiques ! Taper 1\n");
            printf("Voir les charges manuelles ! Taper 2\n");
            scanf("%d", &typeCharge);
            fflush(stdin);
            //charge auto
            if (typeCharge == 1) {

                file = fopen("saveAuto.txt", "r");
                if (file) {
                    fclose(file);
                    validationAuto = 1;
                    saveChoice = 1;
                } else {
                    printf("\nVous n'avez pas de charge auto !\n");
                    saveChoice = 0;
                }
            }
            //charge manuelle
            if (typeCharge == 2) {
                file = fopen("saveManuelle.txt", "r");
                if (file) {
                    fclose(file);
                    validationManuelle = 1;
                    saveChoice = 1;
                } else {
                    printf("\nVous n'avez pas de charge manuelle !\n");
                    saveChoice = 0;
                }
            }
        }

        //New partie
        if (saveChoice == 2) {
            initStartGame();
        }
        if (saveChoice == 3) {
            return;
        }

        if (validationAuto == 1) {
            charge(true);
        }

        if (validationManuelle == 1) {
            charge(false);
        }
    }
}