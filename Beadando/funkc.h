#ifndef FUNKC_H
#define FUNKC_H


void displayMenu(void);
void userManual(void);
int **initmarix(int rows,int rot,int jbfl);
void freematrix(int **pt,int rows);
void printMatrix(int **matrix,int rows);
#endif