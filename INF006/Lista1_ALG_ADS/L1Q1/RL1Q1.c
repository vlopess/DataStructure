#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insertionSort(float A[], int length);


int main(){
    FILE *fp_in = fopen("L1Q1.in", "r");
    FILE *fp_out = fopen("L1Q1.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }

    
    char file[255];
    char space[] = " "; 
    //start 2 4 1 21 start 3 9 18 1 start 3 12 4 12 3
    while(fgets(file, 255, fp_in) != NULL){
        
        char *listNumbers[255];
        int iListNumbers = 0;
        
        char *slice  =  strtok(file, space);

        while (slice != NULL)
        {
            int numbers[255];
            int iNumbers = 0;
            char *copy[255];

            slice  =  strtok(NULL, space);

            while(strcmp(slice, "start") && slice != NULL)
            {
                numbers[iNumbers++] = atoi(slice);
                slice  =  strtok(NULL, space);
            }
            for (int i = 0; i < iNumbers; i++)
            {
                printf("%d", numbers[i]);
                sprintf(copy, "%d ", numbers[i]);
                fputs(copy, fp_out);
            }

            fputs("sla",fp_out);
        
        }
        
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
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