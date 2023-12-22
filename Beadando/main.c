#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "filekezels.h"
//#include "matrixgeneralas.h"


void displayMenu(void);
void userManual(void);
int **initmarix(int rows);
void freematrix(int **pt,int rows);
void printMatrix(int **matrix,int rows);
int **readMatrix(char fnev[100]);
int rowcountwhenread(void);

int main(int *argc, char *argv){

    int menupont;
    char rotation[3];
    char irany[4]; 
    int rows;
    int **matrix = NULL;
    char nev[100];
    int rowcount;
    do {

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &menupont);
        switch (menupont) {
            case 1:
                userManual();
                break;
            case 2:
            //hanincsmegmatrix
                if (matrix == NULL)
                {
                do{
                printf("Add meg hogy mekkora legyen a mátrux NxN (1 és 20 között): ");
                scanf("%d", &rows);
                }while(rows < 1 || rows > 20);
                do{
                printf("Add meg hogy merre induljon el (jobb,bal,fel,le): ");
                scanf("%s", irany);
                getchar();
                }while(strcmp(irany,"jobb") != 0 && strcmp(irany, "bal") != 0 && strcmp(irany,"fel") != 0 && strcmp(irany,"le") != 0);
                do {
                printf("Merre szeretnéd, hogy a feltöltés induljon?(cw,ccw): ");
                scanf("%s", rotation);
                getchar();
                } while (strcmp(rotation, "cw") != 0 && strcmp(rotation, "ccw") != 0);

                matrix = initmarix(rows);

                if(matrix == NULL){
                fprintf(stderr, "\033[1;31m\n");
                fprintf(stderr, "Nem sikerült a mátrix generálása, próbáld újra\n");
                fprintf(stderr, "\033[0m\n");
                }
                }
                else{

                freematrix(matrix,rows);
                do{
                printf("Add meg a mátrix sorainak számét (1 és 20 között): ");
                scanf("%d", &rows);
                }while(rows < 1 || rows > 20);
                do{
                printf("Add meg hogy merre induljon el (jobb,bal,fel,le): ");
                scanf("%s", irany);
                getchar();
                }while(strcmp(irany,"jobb") != 0 && strcmp(irany, "bal") != 0 && strcmp(irany,"fel") != 0 && strcmp(irany,"le") != 0);
               
                do {
                printf("Merre szeretnéd, hogy a feltöltés induljon?(cw,ccw): ");
                scanf("%s", rotation);
                getchar();
                } while (strcmp(rotation, "cw") != 0 && strcmp(rotation, "ccw") != 0);
                matrix = initmarix(rows);
                if(matrix == NULL){
                fprintf(stderr, "\033[1;31m\n");
                fprintf(stderr, "Nem sikerült a mátrix generálása, próbáld újra\n");
                fprintf(stderr, "\033[0m\n");
                }
                }
                break;
            case 3:
              //mátrix beolvasás
                if(matrix == NULL)
                {
                    printf("Add meg a file nevét (kiterjesztésssel eggyütt): ");
                    scanf("%s", nev);
                    getchar();
                    matrix = readMatrix(nev);
                }
                else{
                    freematrix(matrix,rows);
                    printf("Add meg a file nevét (kiterjesztésssel eggyütt): ");
                    scanf("%s", nev);
                    getchar();
                    matrix = readMatrix(nev);
                }
                break;
            case 4:
                //aktuális mátrix kirajzolása
                if(matrix == NULL){
                    printf("Kérlek generálj egy mátrixot vagy tölts be egyet");
                }else{
                    printMatrix(matrix,rows);
                }
                break;
            case 5:
            //kész áthelyezve a filejába
            /*
            if(matrix == NULL)
            {
                printf("Nincs jelenleg mentett mátrix nem tudom kiirni");
            }
            else{
                //mátrix kiirása fileba
               writeMatrix(matrix,rows,rotation,irany);
            }
            */
                break;
            
            case 6:
            //kilép a programbol
                 freematrix(matrix,rows);
                 printf("Köszönöm hogy használtad a programom,Visszavárunk!\n");
                return 0;
            default:
                    fprintf(stderr, "\033[1;31m");
                    fprintf(stderr, "Nincs ilyen opció, kérlek válassz az opciók közül\n");
                    fprintf(stderr, "\033[0m");
        }

    } while (menupont != 6);

}


void displayMenu(void) {
    printf(" ---------------------\n");
    printf("| \033[0;32mWelcome in the Matrix \033[0m|\n");
    printf(" --------------------- \n");
    printf("   Your Options:\n");
    printf("    \033[0;32m 1 - User Manual\n");
    printf("     2 - Generate matrix\n");
    printf("     3 - Load Mátrix\n");
    printf("     4 - Print Matrix\n");
    printf("     5 - Save Matrix\n");
    printf("     6 - Exit\n\033[0m");
}
void userManual(void)
{
    printf("Matrix User Manual:\n");

    printf("1 - User Manual\n");
    printf("Jelenleg ezt az oopciót választottad,Ez egy leírás a program működéséről\n");

    printf("2 - Generate matrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy legenráltass a programmal egy mátrixot \n");
    printf(" 3 paramétert fog kérni a program: mekkora legyen a mártix mérete N X M \n");
    printf("                                   melyik irányba induljon el a feltöltés(Jobb,bal,fel,le)\n");               
    printf("                                   Forgatási irány óramutató járásával megegyező(cw) vagy ellentétes (ccw)\n");               
                
    printf("3 - Load Mátrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy egy választott filebol betöltsünk a programnak egy Mátrixot\n");
                
    
    printf("4 - Print Matrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy az aktuális Mátrixot Kiirjuk a képernyőre\n");

    printf("5 - Save Mátrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy az aktuális Mátrixot egy file-ba kiirjuk\n");

    printf(" 6 - exit\n");
    printf("Kilépés a programobol\n");

}


int **initmarix(int rows) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int *)malloc(rows * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    // Initialize the matrix (you can customize this part)
    int count = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = count++;
        }
    }

    return matrix;
}

void freematrix(int **pt,int rows){
        for (int i = 0; i < rows; i++) {
            free(pt[i]);
        }
        free(pt);
}


void printMatrix(int **matrix,int rows){

    printf("A mentett mátrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%2d ", matrix[i][j]);
        }
            printf("\n");
        }

}


int **readMatrix(char fnev[100]){

 FILE* file = fopen(fnev, "r");
    if (!file) {
        fprintf(stderr, "Nem sikerült megnyitni a fajlt: %s\n", fnev);
        return NULL;
    }

    // Mátrix inicializálása
    int rows = 0;
    int cols = 0;
    int** matrix = NULL;

    // Mátrix elemeinek beolvasása a fájlból és dinamikus reallokálás
    int val;
    while (fscanf(file, "%d", &val) == 1) {
        // Mátrix sorainak dinamikus reallokálása
        matrix = realloc(matrix, (rows + 1) * sizeof(int*));

        // Mátrix sorának dinamikus lefoglalása
        matrix[rows] = malloc((cols + 1) * sizeof(int));

        // Mátrix elemének beolvasása
        matrix[rows][cols] = val;

        // Oszlop növelése
        cols++;

        // Ellenőrzés, hogy elértük-e a sor végét
        if (fgetc(file) == '\n') {
            // Jelenlegi sor befejeződött
            rows++;
            cols = 0;
        }
        else {
            // Visszaugrás egy karakterrel, hogy a következő ciklusban be tudjuk olvasni a következő elemet
            fseek(file, -1, SEEK_CUR);
        }
    }

    // Fájl bezárása
    fclose(file);



        return matrix;
}

