#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int isNumber(char ch[]);
int isPoint(char ch[]);

void ordenaFloats(float floats[], int floatsIndex);
void ordenaInteiros(int ints[], int intsIndex);
void ordenaString(char string[][255], int stringIndex);
float distanceCalc(float x1, float y1, float x2, float y2);
void insertionSort(float A[], int length);
void ordenarPontos(float sort[], float noSort[], float num[], int j, int k);

int main(){
  
  FILE *fp_in  = fopen("L0Q2.in", "r");
  FILE *fp_out = fopen("L0Q2.out", "w");
  
  if (fp_in == NULL || fp_out == NULL){
    printf("Erro na leitura dos arquivos");
    return EXIT_FAILURE;
  }
    
    char file[255];
    char splitHere[] = " ";
  
    while(fgets(file, 255, fp_in) != NULL) {
      char string[100][255];
      int stringIndex = 0;
      //char point[100][255];
      int pointIndex = 0;
      float floats[255];
      int floatsIndex = 0;
      int ints[255];
      int intsIndex = 0;
      char *slice;
      char text[25555];
      float point[100];
      float noSort[100];
      float distances[100];
      int j = 0;
      slice = strtok(file, splitHere);
      while (slice != NULL){
        if(isNumber(slice)){
          if(strstr(slice, ".") == NULL){
             ints[intsIndex] = atoi(slice);         
             intsIndex++; 
          }else{
            floats[floatsIndex] = atof(slice);
            floatsIndex++; 
          }
        }else if (isPoint(slice)){
          float x, y;
          sscanf(slice, "(%f,%f)", &x, &y);
          point[pointIndex] = x;
          pointIndex++;  
          point[pointIndex] = y;
          pointIndex++;
        }else{
          strcpy(string[stringIndex],slice);
          stringIndex++;  
        }
        slice = strtok(NULL, splitHere);
      }
    for(int c = 0; c < pointIndex;c += 2){      
      distances[j] = distanceCalc(point[c], point[c + 1], 0, 0); 
      noSort[j] = distanceCalc(point[c], point[c + 1], 0, 0);
      j++;
    }
      insertionSort(distances, j);
      ordenaFloats(floats, floatsIndex);
      ordenaInteiros(ints, intsIndex);
      //ordenaString(string, stringIndex);
      ordenarPontos(distances, noSort, point, j, pointIndex);

      sprintf(text, "%s", "str:");      
      fputs(text, fp_out);
      for (int i = 0; i < stringIndex; i++)
      {
        sprintf(text, "%s ", string[i]);
        fputs(text, fp_out);
      }
      sprintf(text, " %s", "int:");
      fputs(text, fp_out);
      for (int i = 0; i < intsIndex; i++)
      {
        sprintf(text, "%d ", ints[i]);
        fputs(text, fp_out);
      }
      sprintf(text, "%s", "float:");
      fputs(text, fp_out);
      for (int i = 0; i < floatsIndex; i++)
      {
        sprintf(text, "%2.2f ", floats[i]);
        fputs(text, fp_out);
      }
      sprintf(text, "%s", "p:");
      fputs(text, fp_out);
       for(int c = 0; c < pointIndex; c++){
      sprintf(text, "%s", "(");
      fputs(text, fp_out);
      if(point[c] == (int) point[c]){
        sprintf(text, "%.0f", point[c]);
        fputs(text, fp_out);
      }else{
        sprintf(text, "%2.2f", point[c]);
        fputs(text, fp_out);
      }
            
      sprintf(text, "%s", ",");
      fputs(text, fp_out);
      c++;
      if(point[c] == (int) point[c]){
        sprintf(text, "%.0f", point[c]);
        fputs(text, fp_out);
      }
      else{
        sprintf(text, "%2.2f", point[c]);
        fputs(text, fp_out);
      }
      
      sprintf(text, "%s ", ") ");
      fputs(text, fp_out);
    } 
  }
  fclose(fp_in);
  fclose(fp_out);
  return EXIT_SUCCESS;
}

int isNumber(char ch[]){
  int tam = strlen(ch);
  for(int i = 0; i < tam; i++){
    if((ch[i] > 57 || ch[i] < 48) && (ch[i] != '.' && ch[i] != '-'))
      return 0;
  }
  return 1;
}

int isPoint(char ch[]){
  if(strchr(ch, '(') != NULL){   
    return 1;
  }
  return 0;
}

void ordenaFloats(float floats[], int floatsIndex) {
     int j;
     for (j = 1; j < floatsIndex; j++) {
          float key = floats[j];
          int i = j - 1;          
          while (i >= 0 && floats[i] > key) {
               floats[i + 1] = floats[i];
               i--;
          }
          floats[i + 1] = key;
     }
}
void ordenaInteiros(int ints[], int intsIndex) {
     int j;
     for (j = 1; j < intsIndex; j++) {
          float key = ints[j];
          int i = j - 1;          
          while (i >= 0 && ints[i] > key) {
               ints[i + 1] = ints[i];
               i--;
          }
          ints[i + 1] = key;
     }
}
void ordenaString(char string[][255], int stringIndex) {
    int j;
    for (j = 1; j < stringIndex; j++) {
      char key[255];
      int i = j - 1;;
      strcpy(key, string[j]);
      while (i >= 0 && strcmp(string[i], key) > 0) {
          strcpy(string[i+1], string[i]);
          i--;
      }
      strcpy(string[i+1], key);
    }
}

void ordenaPontos(char point[][255], int pointIndex) {
    int j;
    for (j = 1; j < pointIndex; j++) {
      char key[255];
      int i = j - 1;;
      strcpy(key, point[j]);
      while (i >= 0 && strcmp(point[i], key) > 0) {
          strcpy(point[i+1], point[i]);
          i--;
      }
      strcpy(point[i+1], key);
    }
  int tam=0;
  char copia1[15][255], copia2[15][255];
  for(j=0;j<pointIndex;j++) {
    if(point[j][1] == '-') {
      tam++;
      strcpy(copia1[j],point[j]);
    } else {
      break;
    }
  }
  int i=0;
  j--;
  while(j>=0) {
    strcpy(point[i], copia1[j]);
    i++;
    j--;
  }
  for(j=tam;j<pointIndex;j++) {
    strcpy(copia2[j],point[j]);
  }
  
  j=5;
  while(j<pointIndex) {
    strcpy(point[i], copia2[j]);
    i++;
    j++;
  }
  
}

float distanceCalc(float x1, float y1, float x2, float y2)
{
  float distance = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
  return distance;
}

void insertionSort(float A[], int length)
{
     int j;
     for (j = 1; j < length; j++)
     {
          float key = A[j];
          int i = j - 1;
          while (i >= 0 && A[i] > key)
          {
              A[i + 1] = A[i];
              i--;
          } 
          A[i + 1] = key;
     }
}

void ordenarPontos(float sort[], float noSort[], float num[], int j, int k){
  int i = 0;
  int n[k];
  // int k = sizeof(num[0]) / sizeof(num);
  // printf("%d", k);
  for(int c = 0; c < j; c++){   
      int k = 0;
      for(int a = 0; a < j ; k += 2 , a++){
        if(sort[c] == noSort[a]){
          printf("(%.0f)\t", num[k]);          
          n[i] = num[k];
          i++;
          n[i] = num[k+1];
          i++;
          printf("(%.0f)\n", num[k+1]);
          break;
        }
      }
    }
  
  for(int c = 0; c < i; c++){
    num[c] = n[c];
  }
}