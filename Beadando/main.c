#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void displayMenu(void);
void userManual(void);
int **initmarix(int rows,int cols);
void freematrix(int **pt,int rows);
void printMatrix(int **matrix,int rows,int cols);


int main(int *argc, char *argv){

    int menupont;
    char rotation[3];
    char irany[4]; 
    int rows, cols;
    int **matrix = NULL;
    int beforerow,afterrow;
    char filename[];
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
                printf("Add meg a mátrix sorainak számét (1 és 20 között): ");
                scanf("%d", &rows);
                }while(rows < 1 || rows > 20);
                do {
                printf("Add meg a mátrix oszlopainak számát (1 és 20 között):");
                scanf("%d", &cols);
                }while(cols < 1 || cols > 20);
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

                matrix = initmarix(rows,cols);
                }
                else{
                
                freematrix(matrix,rows);
                do{
                printf("Add meg a mátrix sorainak számét (1 és 20 között): ");
                scanf("%d", &rows);
                }while(rows < 1 || rows > 20);
                do {
                printf("Add meg a mátrix oszlopainak számát (1 és 20 között):");
                scanf("%d", &cols);
                }while(cols < 1 || cols > 20);
                
                do{
                printf("Add meg hogy merre induljon el (jobb,bal,fel,le): ");
                scanf("%s", irany);
                getchar();
                }while(strcmp(irany,"jobb") != 0 && strcmp(irany, "bal") != 0 && strcmp(irany,"fel") != 0 && strcmp(irany,"le") != 0);
               
                do {
                printf("Merre szeretnéd, hogy a feltöltés induljon?(cw,ccw): ");
                scanf("%s", rotation);
                // Consume the newline character from the previous input
                getchar();
                } while (strcmp(rotation, "cw") != 0 && strcmp(rotation, "ccw") != 0);
                matrix = initmarix(rows,cols);
                }
                break;
            case 3:
                if (matrix == NULL){
                    
                }
                
                break;
            case 4:
                //aktuális mátrix kirajzolása

                if(matrix == NULL){
                    printf("Kérlek generálj egy mátrixot vagy tölts be egyet");
                }else{
                    printMatrix(matrix,rows,cols);
                }

                break;
            case 5:
                //mátrix fileba irás
                break;
            
            case 6:
                 freematrix(matrix,rows);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
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

    printf("2 - generate matrix:\n");
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


int **initmarix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Handle memory allocation failure
            // Cleanup allocated memory before returning
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
        for (int j = 0; j < cols; ++j) {
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


void printMatrix(int **matrix,int rows,int cols){

    printf("A mentett mátrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
            printf("\n");
        }


}
readfromfile(int **matrix,int rows,int cols,char *filename);
