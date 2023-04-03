#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


int isNumber(char ch[]);
int isPoint(char ch[]);

int main(){
  FILE *fp_in  = fopen("L0Q2.in", "r");
  FILE *fp_out = fopen("L0Q2.out", "w");
  
  if (fp_in == NULL || fp_out == NULL){
    printf("Erro na leitura dos arquivos");
    return EXIT_FAILURE;
  }
    
    char file[255];
    
    //maria 3.15 jose 4 8 −1 12.7 −1,−1 julia (−0.5 ,−0.5)
    while(fgets(file, 255, fp_in) != NULL){

      char string[100][255];
      int stringIndex = 0;
      char point[100][255];
      int pointIndex = 0;
      float floats[255];
      int floatsIndex = 0;
      int ints[255];
      int intsIndex = 0;
      char *slice;
      char text[100];

      slice = strtok(file," ");
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
          strcpy(point[pointIndex], slice);
          pointIndex++;          
        }else{
          strcpy(string[stringIndex],slice);
          stringIndex++;          
        }
        slice = strtok(NULL, " ");
        printf("\n%s", slice);      
      }
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
      for (int i = 0; i < pointIndex; i++)
      {
        sprintf(text, "%s", point[i]);
        fputs(text, fp_out);
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