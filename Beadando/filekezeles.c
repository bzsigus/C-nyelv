#include <stdlib.h>
#include <stdio.h>

void writeMatrix(int **matrix,int rows, char rotation[3], char irany[4]){
    char filename[30];
    sprintf(filename, "Spiral%d_%s_%s.txt", rows, rotation, irany);

    FILE *file = fopen(filename, "w");
    if (!file) 
    {
    fprintf(stderr, "Nem sikerült megnyitni a fajlt: %s\n", filename);
    }
    else
    {
        for (int i = 0; i < rows; i++) 
        {
        for (int j = 0; j < rows; j++) 
            {
            fprintf(file, "%2d ", matrix[i][j]);
            }
        fprintf(file, "\n");
        }
    }

        printf("A mátrix ki lett irva egy fileba\n");
    fclose(file);
}