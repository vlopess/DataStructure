#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


int isNumber(char ch[]);
int isPoint(char ch[]);

int main(){
  setlocale(LC_ALL, "");
  FILE *fp_in  = fopen("L0Q2.in", "r");
  FILE *fp_out = fopen("L0Q2.out", "w");
  
  if (fp_in == NULL || fp_out == NULL){
    printf("Erro na leitura dos arquivos");
    return EXIT_FAILURE;
  }
    
    char file[255];
    char splitHere[] = " ";
    char *slice;
    char copy[255];
    //maria 3.15 jose 4 8 −1 12.7 −1,−1 julia (−0.5 ,−0.5)
    while(fgets(file, 255, fp_in) != NULL) {  
      slice = strtok(file, splitHere);
      while (slice != NULL){ 
        strcpy(copy, slice);
        //printf(">: %s\n", copy);
        if(isNumber(copy)){
          if(strstr(slice, ".") == NULL){
            printf("Number int: %s\n", slice);
          }else{
            printf("Number float: %s\n", slice);
          }                
        }else if (isPoint(copy)){
          printf("Point: %s\n", slice);
        }else{
          printf("String: %s\n", slice);
        }
        slice = strtok(NULL, splitHere);        
      }
      fclose(fp_in);
      fclose(fp_out);
      return EXIT_SUCCESS;
    }

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
  char copy[255];
  int tam = strlen(ch);
  if(ch[0] == '(' && ch[tam-1] == ')'){
    char split[] = "(,)";
    char *slice = strtok(ch, split);
    strcpy(copy, slice);
    if(!isNumber(copy))
      return 0;
    ch = strtok(NULL, split);
    strcpy(copy, slice);
    if(!isNumber(copy))
      return 0;
  }else
    return 0;
  return 1;
}