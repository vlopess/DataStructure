#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void putOnStack(char *nome);
void insertionSortPlus(char *nome);
void push(char *nome);
void pop();
int numberHouses(int num);

char stack[100][255];
int tos = 0;
char *text = NULL;


int main(){
  
    FILE *fp_in = fopen("L1Q2.in", "r");
    FILE *fp_out = fopen("L1Q2.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }
            
    char file[255];
  
    while(fgets(file, 255, fp_in) != NULL){
        char nomes[100][255];
        int qtdNomes = 0;   
        char space[] = " ";
        tos = 0;
      
        int tam = strlen(file);
        if(strchr(file, '\n') != NULL)
          file[tam - 1] = '\0';
      
        char *slice = strtok(file, space);
        while(slice != NULL){          
          strcpy(nomes[qtdNomes], slice);
          qtdNomes++;
          slice = strtok(NULL, space);
        }
        for(int i = 0 ; i < qtdNomes; i++){
          putOnStack(nomes[i]);
        }
        
        tam = strlen(text);
        if(text[tam - 1] == ' ')
          text[tam - 1] = '\0';

        fputs(text, fp_out);
        fputs("\n", fp_out);

        text = NULL;
    }
    
    free(text);
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}

int numberHouses(int num) {
  int count = 1;
  while (num / 10 != 0) {
    count++;
    num /= 10;
  }
  return count;
};

void putOnStack(char *nome){
  if(!tos)
    push(nome);    
  else
    insertionSortPlus(nome);
}


void push(char *nome){
  char *copy = NULL;
  int tam = strlen(nome) + 7;
  
  strcpy(stack[tos], nome);
  tos++;
  copy = malloc(tam);
  sprintf(copy, "%s%s ","push-", nome);
  tam = text == NULL ? 1 : strlen(text);
  
  tam += strlen(copy) + 1;
  if(text)
    text = realloc(text, tam);
  else
    text = malloc(tam);
  strcat(text, copy);  
  free(copy);
}

void pop(){
  tos--;
}

void insertionSortPlus(char *nome){
  int Pop = 0;
  char pops[255][255];
  for(int i = tos - 1; i >= 0 && strcmp(stack[i], nome) > 0; i--){
    strcpy(pops[Pop], stack[i]);
    pop();
    Pop++;
  }  
  if(Pop){
    char *popcopy = NULL;
    int tam = numberHouses(Pop) + 7;
    popcopy = malloc(tam);
    sprintf(popcopy, "%d%s ", Pop, "x-pop");
    tam = strlen(text) + strlen(popcopy) + 1;
    text = realloc(text, tam);
    strcat(text, popcopy);
    free(popcopy);
  }
  push(nome);
  for(int i = Pop - 1; i >= 0; i--){
      push(pops[i]);
  }
}