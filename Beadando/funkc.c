#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("%5d ", matrix[i][j]);
        }
            printf("\n");
        }

}
int **initmarix(int rows,char rotation[3], char irany[4])
{
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
    int dir = 0;
    int cwOrccw = 0;
    int n = rows;
    int num = rows * rows;
    int mid = n / 2;
    //jobb = 0;bal= 1;fel = 2;le=3;
    if(strcmp(irany,"jobb") == 0){
        dir= 0;
    }
    else if(strcmp(irany,"bal")== 0){
        dir= 1;

    }
     else if(strcmp(irany,"fel")== 0){
                dir =2;

    }
     else if(strcmp(irany,"le")== 0){
                dir =3;

    }
    //cw = 1;ccw = 2;
    if(strcmp(rotation,"cw")== 0){
        cwOrccw = 1;
    }else if (strcmp(rotation,"ccw")== 0){
        cwOrccw = 2;
    }


    //cw rot
    if(cwOrccw == 1){
        switch(dir){
            //jobb
            case 0:
                
            break;
            //bal
            case 1:

                        num = rows * rows;
                    for (int layer = 0; layer < (n + 1) / 2; ++layer) {
                        // Right
                        for (int i = layer; i < n - layer; ++i)
                            matrix[layer][i] = num--;

                        // Down
                        for (int i = layer + 1; i < n - layer; ++i)
                            matrix[i][n - 1 - layer] = num--;

                        // Left
                        for (int i = n - 2 - layer; i >= layer; --i)
                            matrix[n - 1 - layer][i] = num--;

                        // Up
                        for (int i = n - 2 - layer; i > layer; --i)
                            matrix[i][layer] = num--;
                        }

            break;
             //fel
            case 2:
         
                    for (int layer = 0; layer < (n + 1) / 2; ++layer) {
                        // Down
                        for (int i = layer; i < n - layer; ++i)
                            matrix[i][layer] = num--;

                        // Right
                        for (int i = layer + 1; i < n - layer; ++i)
                            matrix[n - 1 - layer][i] = num--;

                        // Up
                        for (int i = n - 2 - layer; i >= layer; --i)
                            matrix[i][n - 1 - layer] = num--;

                        // Left
                        for (int i = n - 2 - layer; i > layer; --i)
                            matrix[layer][i] = num--;
                        }


            break;
             //le
           
        
            break;
        
        }
    
    }
    //ccw rot
    else if(cwOrccw == 2){
    switch(dir){
            //jobb
            case 0:

            break;


            //bal
            case 1:
                 for (int layer = 0; layer < (n + 1) / 2; ++layer) {
                // Up
                for (int i = n - 1 - layer; i >= layer; --i)
                    matrix[i][layer] = num--;

                // Left
                for (int i = layer + 1; i < n - layer; ++i)
                    matrix[layer][i] = num--;

                // Down
                for (int i = layer + 1; i < n - layer; ++i)
                    matrix[i][n - 1 - layer] = num--;

                // Right
                for (int i = n - 2 - layer; i > layer; --i)
                    matrix[n - 1 - layer][i] = num--;
            }

            break;

             //fel
            case 2:
                for (int layer = 0; layer < (n + 1) / 2; ++layer) {
                    // Down
                    for (int i = layer; i < n - layer; ++i)
                        matrix[i][layer] = num++;

                    // Right
                    for (int i = layer + 1; i < n - layer; ++i)
                        matrix[n - 1 - layer][i] = num++;

                    // Up
                    for (int i = n - 2 - layer; i >= layer; --i)
                        matrix[i][n - 1 - layer] = num++;

                    // Left
                    for (int i = n - 2 - layer; i > layer; --i)
                        matrix[layer][i] = num++;
                }


            break;



             //le
            case 3:
            break;
        }
    }

 

    return matrix;
}
