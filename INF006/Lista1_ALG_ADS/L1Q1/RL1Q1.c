#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insertionSort(float A[], int length);


int main()
{

    FILE *fp_in = fopen("L1Q1.in", "r");
    FILE *fp_out = fopen("L1Q1.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL)
    {
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }
    
    char file[255];
    char space[] = " "; 
    //start 2 3 4 56 start 7 6 4 0 1 start 1
    while(fgets(file, 255, fp_in) != NULL)
    {
        // char *listNumbers[255];
        // int iListNumbers = 0;
        int tam = strlen(file);
        if(strchr(file, '\n') != NULL)
          file[tam - 1] = '\0';

        printf("%s?\n", file);

        char *slice  =  strtok(file, space);
                

        while (slice != NULL)
        {
            printf("(%s)\n", slice);
            int numbers[255];
            int iNumbers = 0;
            // char copy[255];

            slice  =  strtok(NULL, space);

            while(strcmp(slice, "start") != 0 && slice != NULL)
            {
                printf("!(%s)\n", slice);
                numbers[iNumbers++] = atoi(slice);
                slice  =  strtok(NULL, space);
            }
            printf("K(%s)\n", slice);
            for (int i = 0; i < iNumbers; i++)
            {
                printf("%d \n", numbers[i]);
                fputs("sla",fp_out);
            }
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