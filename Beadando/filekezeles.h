#ifndef FILEKEZELES_H
#define FILEKEZELES_H

void writeMatrix(int **matrix,int rows, char rotation[3], char irany[4],bool olvasotte);
int **readMatrix(char fnev[100]);
int countrows(char fnev[100]);
#endif