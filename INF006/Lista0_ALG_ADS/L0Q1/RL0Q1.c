#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float distanceCalc(float x1, float y1, float x2, float y2);
void insertionSort(float A[], int length);
void ordenarPontos(float sort[], float noSort[], float num[], int j, int k);


int main(){
  FILE *fp_in = fopen("L0Q1.in", "r");
  FILE *fp_out = fopen("L0Q1.out", "w");
  
  
  if(fp_in == NULL ||  fp_out==NULL){
    printf("Erro na leitura dos arquivos\n");
    return EXIT_FAILURE;
  }
  
  char file[255];  
  
  while(fgets(file, 255, fp_in) != NULL){
    fflush(stdin);
    char splitHere[] = " (,)";
    char point[] = "points";    
    char text[20];
    int i, j, c;
    float distance, shortcut;
    float number[100];
    float noSort[100];
    float distances[100];
    i = j = c= 0;    
    distance = shortcut = 0;
    //points (−2,−1) (4,2) (4,0) (2,2) (8,6)
    char *p = strtok(file, point);
    // printf("%s\n", p);
    char *slice  =  strtok(p, splitHere);
       
    while (slice != NULL){
      number[i] =  atof(slice);
      i++;     
      slice  =  strtok(NULL, splitHere);         
    }   
    i--;
    for(int c = 0; c < i - 3;c = c + 2){
      distance+= distanceCalc(number[c], number[c + 1], number[c + 2], number[c + 3]);      
    }
    //printf("%d\n", i);  
    for(int c = 0; c < i;c += 2){      
      distances[j] = distanceCalc(number[c], number[c + 1], 0, 0); 
      noSort[j] = distanceCalc(number[c], number[c + 1], 0, 0);
      j++;
    }
    
    insertionSort(distances, j);
    shortcut = distanceCalc(number[0], number[1], number[i - 2], number[i - 1]);

    
    // printf("%d\n", j);  
    // for(int c = 0; c<j ;c++){
    //   printf("%2.2f\t\t\t", distances[c]);
    //   printf("%2.2f\n", noSort[c]);
    // }

    sprintf(text, "points ");
    fputs(text, fp_out);

    // for (int i = 0; i < j; i++)
    // {
    //   sprintf(text, "(%d,%d) ", number[index[i]], number[index[i]+1]);
    //   fputs(text, fp_out);
    // }
    
    ordenarPontos(distances, noSort, number, j, i);

    // for(int c = 0; c < i; c++){
    //   printf("%2.2f ", number[c]);
    // }
    
    for(int c = 0; c < i; c++){
      sprintf(text, "%s", "(");
      fputs(text, fp_out);
      if(number[c] == (int) number[c]){
        sprintf(text, "%.0f", number[c]);
        fputs(text, fp_out);
      }else{
        sprintf(text, "%2.2f", number[c]);
        fputs(text, fp_out);
      }
            
      sprintf(text, "%s", ",");
      fputs(text, fp_out);
      c++;
      if(number[c] == (int) number[c]){
        sprintf(text, "%.0f", number[c]);
        fputs(text, fp_out);
      }
      else{
        sprintf(text, "%2.2f", number[c]);
        fputs(text, fp_out);
      }
      
      sprintf(text, "%s ", ") ");
      fputs(text, fp_out);
    }
    
    sprintf(text, "%s ", "distance:");
    fputs(text, fp_out);
    sprintf(text, "%2.2f  ", distance);
    fputs(text, fp_out);
    
    
    //printf("%d %d %d %d\n", number[0], number[1], number[i - 2], number[i - 1]);
    //printf("%2.2f\n", shortcut);
    sprintf(text, "%s", "shortcut: ");
    fputs(text, fp_out);
    sprintf(text, "%2.2f", shortcut);
    fputs(text, fp_out);
    fputc('\n', fp_out);
  }
  fclose(fp_in);
  fclose(fp_out);
  return EXIT_SUCCESS;
}


float distanceCalc(float x1, float y1, float x2, float y2)
{
  float distance = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
  return distance;
}

/*
Função que ordena o vetor as distancias do vetor
*/
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
          //printf("(%.0f)\t", num[k]);          
          n[i] = num[k];
          i++;
          n[i] = num[k+1];
          i++;
          //printf("(%.0f)\n", num[k+1]);
          break;
        }
      }
    }
  
  for(int c = 0; c < i - 1; c++){
    num[c] = n[c];
  }
}
