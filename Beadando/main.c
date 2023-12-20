#include <stdio.h>
#include <stdlib.h>


void displayMenu(void);
void userManual(void);

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(int **matrix, int rows, int cols) {
    int value = 8;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }
}


int main(int *argc, char *argv){

     int rows = 8;
    int cols = 8;
    int matrix[rows][cols];


    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                userManual();
                break;
            case 2:
                printf("You selected Option 2.\n");
                // Add your code for Option 2 here
                break;
            case 3:
                printf("You selected Option 3.\n");
                // Add your code for Option 3 here
                break;
            case 4:
                printf("Option 4.\n");
                break;
            case 5:
                fillMatrix(matrix[rows][cols], rows, cols);
                printMatrix(matrix[rows][cols], rows, cols);
                break;
            
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

}

void displayMenu(void) {
    printf(" ---------------------\n");
    printf("| \033[0;32mWelcome in the Matrix \033[0m|\n");
    printf(" --------------------- \n");
    printf("   Your Options:\n");
    printf("    \033[0;32m 1 - User Manual\n");
    printf("     2 - Generate matrix\n");
    printf("     3 - Load Mátrix:\n");
    printf("     4 - Save Matrix:\n");
    printf("     5 - Print Matrix\n");
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
                
    printf("4 - Save Mátrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy az aktuális Mátrixot egy file-ba kiirjuk\n");

    printf("5 - Print Matrix:\n");
    printf(" Ez a választás lehetőséget ad arra hogy az aktuális Mátrixot Kiirjuk a képernyőre\n");

    printf(" 6 - exit\n");
    printf("Kilépés a programobol\n");

}


