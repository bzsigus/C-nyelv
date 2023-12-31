#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


void writeMatrix(int **matrix,int rows, char rotation[3], char irany[4],bool olvasotte){
    if(olvasotte){
       char filename[30] = "Beolvasottfile.txt";
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
              printf("A mátrix ki lett irva ebbe a fileba: %s\n",filename);
          fclose(file);
    }else{
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
              printf("A mátrix ki lett irva ebbe a fileba: %s\n",filename);
          fclose(file);
    }
   
}


int **readMatrix(char fnev[100]) {

  FILE *fp = fopen(fnev, "r");
  if (fp == NULL) {
    printf("A fájl nem nyitható meg.");
    return NULL;
  }

 int sor = 1;
  int oszlop = 1;
  char c;

  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      sor++;
    } 
  }
  sor -= 1;

  fclose(fp);


   FILE *op = fopen(fnev, "r");
  if (op == NULL) {
    printf("A fájl nem nyitható meg.");
    return NULL;
  }

  int **matrix = (int **)malloc(sor * sizeof(int *));
  if (matrix == NULL) {
    fclose(op);
    return NULL;
  }

  for (int i = 0; i < sor; ++i) {
    matrix[i] = (int *)malloc(sor * sizeof(int));
    if (matrix[i] == NULL) {
      for (int j = 0; j < i; ++j) {
        free(matrix[j]);
      }
      free(matrix);
      fclose(op);
      return NULL;
    }
  }

  // Continue using the same file pointer (fp) to read the matrix content
  for (int i = 0; i < sor; i++) {
    for (int j = 0; j < sor; j++) {
      fscanf(op, "%d", &matrix[i][j]);
    }
  }

  fclose(op);

  return matrix;
}

int countrows(char fnev[100]){
  FILE *fp = fopen(fnev, "r");
  if (fp == NULL) {
    printf("A fájl nem nyitható meg.");
    return 0;
  }
 int sor = 1;
  int oszlop = 1;
  char c;
  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      sor++;
    } 
  }
  fclose(fp);
 sor -= 1;
  return sor;
}
