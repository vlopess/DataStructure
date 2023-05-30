#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct list{
  int *numbers;
  int len;
  int sum;
  struct list *next;
}List;

void insertionSort(int *vetor, int tam);
void putInList(List *novo, List **start);
void freeMemory(List *start);

int main() {
  FILE *fp_in = fopen("L1Q1.in", "r");
  FILE *fp_out = fopen("L1Q1.out", "w");

  if(fp_in == NULL || fp_out == NULL) {
    printf("Erro na leitura dos arquivos\n");
    return EXIT_FAILURE;
  }
  char file[255];
  List *start = NULL;
  while(fgets(file, 255, fp_in) != NULL){
    char *slice = strtok(file, " ");
    while(slice != NULL){
      if(!strcmp(slice, "start")){
        List *novo = malloc(sizeof(List));
        novo->len = 0;
        novo->sum = 0;
        novo->next = NULL;
        novo->numbers = NULL;
        slice = strtok(NULL, " ");
        while(slice && strcmp(slice, "start")){         
          novo->numbers = realloc(novo->numbers, (novo->len + 1) * sizeof(int*));
          int num = atoi(slice);
          novo->numbers[novo->len] = num;
          novo->len++;
          novo->sum+=num;
          slice = strtok(NULL, " ");
        }
        
        insertionSort(novo->numbers, novo->len);
        putInList(novo, &start);       
      }
    }
    for(List *i = start ; i != NULL; i = i->next){
      fputs("start ", fp_out);
      int tam = i->len;
      for(int c = 0 ; c < tam ; c++){
        char num[10];
        sprintf(num, "%d ", i->numbers[c]);
        fputs(num, fp_out);
      }    
    }
    fputc('\n', fp_out);
    freeMemory(start);
    start = NULL;    
  }  
  return EXIT_SUCCESS;
}


void insertionSort(int *vetor, int tam) {
    int i, chave, j;
    for (i = 1; i < tam; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void putInList(List *novo, List **start){
  if(*start == NULL){
    *start = novo;
    return;
  }
  List *p = *start;
  List *old = NULL;
  while(p && p->sum < novo->sum){
    old = p;
    p = p->next;
  }
  if(p == *start){
    novo->next = *start;
    *start = novo;
    return;
  }
  novo->next = old->next;
  old->next = novo;
}

void freeMemory(List *start){
  List *i = start;
  while(i){
    if(i->numbers){
     free(i->numbers); 
    }      
    free(i);
    i = i->next;
  }
}
