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
int **initmarix(int rows,int rot,int jbfl)
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

    int dir;
    int cwOrccw =1;
    int n = rows;
    int stepcount = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
             }
         }
    int x = n/2;
    int y = n/2;
    int end = (n - x);
    int N = (n*n)+1;
    matrix[x][y] = 1;
    int szam = 2;

    if(rot == 1){
        switch(jbfl){
            //jobb
            case 0:
                    while(szam <= n*n){  
                    // jobb
                    for (int j = 0; j < stepcount && szam < N; j++) {
                        y++;
                        matrix[x][y] = szam++;
                     }
                    //le
                    for (int j = 0; j < stepcount && szam < N; j++) {
                        x++;
                        matrix[x][y] = szam++;   
                    }
                    stepcount++;
                     //bal
                    for (int j = 0; j < stepcount && szam < N; j++) {
                        y--;
                        matrix[x][y] = szam++;  
                    }
                    //fel
                      for (int j = 0; j < stepcount && szam < N; j++) {
                        x--;
                        matrix[x][y] = szam++;
                       }
                    stepcount++;   
                    }
                
            break;
            //bal
            case 1:
                    while(szam <= n*n){  
                            //bal
                            for (int j = 0; j < stepcount && szam < N; j++) {
                                y--;
                                matrix[x][y] = szam++;
                            
                            }
                             //fel
                            for (int j = 0; j < stepcount && szam < N; j++) {
                                x--;
                                matrix[x][y] = szam++; 
                            }
                            
                            stepcount++;
                            //jobb
                            for (int j = 0; j < stepcount && szam < N; j++) {
                                y++;
                                matrix[x][y] = szam++;
                            }
                            //le
                            for (int j = 0; j < stepcount && szam < N; j++) {
                                x++;
                                matrix[x][y] = szam++;
                            }
                            stepcount++;
                    }
            break;
             //fel
            case 2:
					while(szam <= n*n){  
					 //fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					}
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					}
					 stepcount++;
					//le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;     
					}
					//bal 
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					   
					}
					stepcount++;
					}
            break;
             //le
			case 3:
					while(szam <= n*n){  
					//le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;     
					}
					 //bal 
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					}
					 stepcount++;
					 //fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					}
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					}
					stepcount++;
					}
			break;
        }
    }else
    {   
     switch(jbfl){
            //jobb
            case 0:
            
					while(szam <= n*n){  
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					} 
                    //fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					  
					}
					stepcount++;
					//bal
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					   
					}
                    //le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;     
					}
					stepcount++;
			}
            break;
            //bal
            case 1:
                
					while(szam <= n*n){  
					//bal
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					}
					//le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;
					}
					stepcount++;
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					}
					//fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					}
					stepcount++;
					}
			break;
            //fel
            case 2:
                while(szam <= n*n){  
					 //fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					}
					//bal 
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					}
					stepcount++;
                    //le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;     
					}
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					}
					 stepcount++;
					}
            break;
            //le
            case 3:
			while(szam <= n*n){  
					//le
					for (int j = 0; j < stepcount && szam < N; j++) {
						x++;
						matrix[x][y] = szam++;     
					}
					//jobb
					for (int j = 0; j < stepcount && szam < N; j++) {
						y++;
						matrix[x][y] = szam++;
					}
					 stepcount++;
					 //fel
					for (int j = 0; j < stepcount && szam < N; j++) {
						x--;
						matrix[x][y] = szam++;
					}
					//bal 
					for (int j = 0; j < stepcount && szam < N; j++) {
						 y--;
						matrix[x][y] = szam++;
					}
					stepcount++;
					}
            break;
        }
    }
    return matrix;
}
