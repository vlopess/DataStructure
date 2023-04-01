#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float distanceCalc(int x1, int y1, int x2, int y2);
void insertionSort(float A[], int length);

int main(){
  FILE *fp_in = fopen("L0Q1.in", "r");
  FILE *fp_out = fopen("L0Q1.out", "w");
  
  
  if(fp_in == NULL ||  fp_out==NULL){
    printf("Erro na leitura dos arquivos\n");
    return EXIT_FAILURE;
  }
  
  char file[255];  
  
  while(fgets(file, 255, fp_in) != NULL){
    char splitHere[] = " (,)";
    char point[] = "points";    
    char text[20];
    int i, j, c, k;
    float distance, shortcut;
    int number[100];
    int sort[100];
    float noSort[100];
    float distances[100];
    char copy[255];
    i = j = c = k = 0;    
    distance = shortcut = 0;
    //points (−2,−1) (4,2) (4,0) (2,2) (8,6)
    char *p = strtok(file, point);
    // printf("%s\n", p);
    char *slice  =  strtok(p, splitHere);    
    while (slice != NULL){
      strcpy(copy, slice);
      number[i] =  atoi(slice);
      i++;     
      slice  =  strtok(NULL, splitHere);         
    }   
    i--;
    for(int c = 0; c <= i - 3;c = c + 2){
      distance+= distanceCalc(number[c], number[c + 1], number[c + 2], number[c + 3]);      
    }
    for(int c = 0; c < i - 2;c = c + 2){      
      distances[j] = distanceCalc(number[c], number[c + 1], 0, 0); 
      noSort[j] = distanceCalc(number[c], number[c + 1], 0, 0); 
      j++;
    }
    
    insertionSort(distances, j);
    
    // for(int c = 0; c<j ;c++){
    //   printf("%2.2f\t\t\t", distances[c]);
    //   printf("%2.2f\n", noSort[c]);
    // }

    sprintf(text, "points ");
    fputs(text, fp_out);

    for(int c = 0; c < j; c++){      
      for(int a = 0, k = 0; a < j; a++, k += 2){
        if(distances[c] == noSort[a]){
          sprintf(text, "(%d,%d) ", number[k], number[k+1]);
          fputs(text, fp_out);
          break;
        }
      }
    }
    
    sprintf(text, "%s ", "distance:");
    fputs(text, fp_out);
    sprintf(text, "%2.2f  ", distance);
    fputs(text, fp_out);
    
    shortcut = distanceCalc(number[0], number[1], number[i - 1], number[i]);
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


float distanceCalc(int x1, int y1, int x2, int y2)
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