#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funkc.h"
#include "filekezeles.h"



int main(int *argc, char *argv[]){

    int menupont;
    int rows;
    char rotation[3];
    char irany[4]; 
    char nev[100];
    bool olvasottfile = false;
    int **matrix = NULL;
    int jbfl;
    int rot;
    
    
    do {
        //menu kiirasa
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &menupont);
        //menu csinal valamit
        switch (menupont) {
            case 1:
                    userManual();
            break;
            //hanincsmegmatrix
            case 2:
            
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
                       
                         /jobb = 0;bal= 1;fel = 2;le=3;
                        if(strcmp(irany,"jobb") == 0){
                            jbfl= 0;
                        }
                        if(strcmp(irany,"bal")==0){
                            jbfl= 1;
                        }
                        if(strcmp(irany,"fel")== 0){
                            jbfl=2;
                        }
                        if(strcmp(irany,"le")== 0){
                            jbfl =3;
                        }

                        do {
                        printf("Merre szeretnéd, hogy a feltöltés induljon?(cw,ccw): ");
                        scanf("%s", rotation);
                        getchar();
                        } while (strcmp(rotation, "cw") != 0 && strcmp(rotation, "ccw") != 0);
                       
                        if(strcmp(rotation, "cw") == 0){
                            rot = 1;
                        }
                        else{
                            rot = 2;
                        }

                        matrix = initmarix(rows,rot,jbfl);

                    if(matrix == NULL){
                        fprintf(stderr, "\033[1;31m\n");
                        fprintf(stderr, "Nem sikerült a mátrix generálása, próbáld újra\n");
                        fprintf(stderr, "\033[0m\n");
                    }
                    }else{

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
                        //jobb = 0;bal= 1;fel = 2;le=3;
                        if(strcmp(irany,"jobb") == 0){
                            jbfl= 0;
                        }
                        if(strcmp(irany,"bal")==0){
                            jbfl= 1;
                        }
                        if(strcmp(irany,"fel")== 0){
                            jbfl=2;
                        }
                        if(strcmp(irany,"le")== 0){
                            jbfl =3;
                        }

                        do {
                        printf("Merre szeretnéd, hogy a feltöltés induljon?(cw,ccw): ");
                        scanf("%s", rotation);
                        getchar();
                        } while (strcmp(rotation, "cw") != 0 && strcmp(rotation, "ccw") != 0);
                        if(strcmp(rotation, "cw") == 0){
                            rot = 1;
                        }
                        else{
                            rot = 2;
                        }
                        matrix = initmarix(rows,rot,jbfl);
                   

                    if(matrix == NULL){
                        fprintf(stderr, "\033[1;31m\n");
                        fprintf(stderr, "Nem sikerült a mátrix generálása, próbáld újra\n");
                        fprintf(stderr, "\033[0m\n");
                        }
                    }
                     olvasottfile = false;
             break;
            
            //mátrix beolvasás
            case 3:
                    if(matrix == NULL)
                    {
                        printf("Add meg a file nevét (kiterjesztésssel eggyütt): ");
                        scanf("%s", nev);
                        getchar();
                        matrix = readMatrix(nev);
                        rows = countrows(nev);  
                    }
                    else{
                        freematrix(matrix,rows);
                        printf("Add meg a file nevét (kiterjesztésssel eggyütt): ");
                        scanf("%s", nev);
                        getchar();
                        matrix = readMatrix(nev);
                        rows = countrows(nev);
                    
                    }
                    olvasottfile = true;
            break;

            //aktuális mátrix kirajzolása
            case 4:
                
                    if(matrix == NULL){
                        printf("Kérlek generálj egy mátrixot vagy tölts be egyet");
                    }else{
                        printMatrix(matrix,rows);
                    }
             break;

             //mátrix kiirása fileba
            case 5:
            
                    if(matrix == NULL)
                    {
                        printf("Nincs jelenleg mentett mátrix nem tudom kiirni");
                    }
                    else{
                    
                    writeMatrix(matrix,rows,rotation,irany,olvasottfile);
                    }
                    
             break;
            
            //kilép a programbol
            case 6:
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