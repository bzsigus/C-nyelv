#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void displayMenu(void);
void userManual(void);


int main(int *argc, char *argv){

    int menupont;
    char rotation[3];
    char irany[4]; 
    int rows, cols;
     int **matrix = NULL;
    do {

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &menupont);
        switch (menupont) {
            case 1:
                userManual();
                break;
            case 2:
                if(matrix != NULL)
                {
                     for (int i = 0; i < rows; ++i) {
                            free(matrix[i]);
                        }
                        free(matrix);
                }

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


                    // Mátrix inicializálása a heap-en
                    matrix = (int **)malloc(rows * sizeof(int *));
                    for (int i = 0; i < rows; ++i) {
                        matrix[i] = (int *)malloc(cols * sizeof(int));
                    }

                int c = 0;
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        matrix[i][j] = c++;
                    }
                    
                }
                



                
                printf("A mentett mátrix:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%2d ", matrix[i][j]);
                    }
                    printf("\n");
                }

                

                break;
            case 3:
                printf("You selected Option 3.\n");
                // Add your code for Option 3 here
                break;
            case 4:
                printf("Option 4.\n");
                break;
            case 5:
                
                break;
            
            case 6:
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


