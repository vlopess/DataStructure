#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct sub{
  float num;
  struct sub *next;
} Sub;

typedef struct NO{
  int number;
  struct NO *prior;
  struct NO *next;
  Sub *sub;
}No;

void insertionSort(Sub *start);
void freeAll(No *start);
void create(No *i, No **start, No **end);
void sortSub(Sub *i, Sub **start, Sub **end);

int main(){
    FILE *fp_in = fopen("L1Q3.in", "r");
    FILE *fp_out = fopen("L1Q3.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }

    char file[255];
  
    No *start = NULL;
    No *end = NULL;
  
    while(fgets(file, 255, fp_in) != NULL){          
      
      char space[] = " ";

      start = NULL;
      end = NULL;
  
      char *slice = strtok(file, space);
      slice = strtok(NULL, space);
    
      while(strcmp(slice, "LI")){ 
        No *i = malloc(sizeof(No));
        i->number = atoi(slice);
        create(i, &start, &end);        
        slice = strtok(NULL, space);          
      }
    
      slice = strtok(NULL, space);
      while(slice != NULL){
        float num = atof(slice);
        for(No *i = start; i; i = i->next){
          if(i->number == (int) num){
            Sub *s = malloc(sizeof(Sub));
            s->num = num;
            if(!i->sub){
              s->next = s;
              i->sub = s;
            }else{
              Sub *a = i->sub;                
              while(a){                  
                Sub *b = a;
                a = a->next;                  
                if(a == i->sub){
                  a = b;
                  break;
                }                 
              }
              a->next = s;
              s->next = i->sub; 
            }
            break;
          }
        }
        slice = strtok(NULL, space);
      }
      for(No *c = start; c; c = c->next){
        if(c->sub != NULL)
          insertionSort(c->sub);
      }
      char text[10];
      fputs("[", fp_out);
      for(No *i = start; i; i = i->next){
        sprintf(text,"%d(", i->number);
        fputs(text, fp_out);
        Sub *begin = i->sub;
        Sub *j = i->sub;
        if(j){
          do{
            sprintf(text, "%g", j->num);
            fputs(text, fp_out);
            j = j->next;
            if(j != begin)
              fputs("->", fp_out);
          }while(j != begin);
        }          
        fputs(")", fp_out);
        if(i->next)
          fputs("->", fp_out);
      }
      fputs("]", fp_out);              
      fputs("\n", fp_out);              
    }
    freeAll(start);
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}

void insertionSort(Sub *start)
{
  Sub *j = start->next;
  do
  {
    if(j != start){
      float key = j->num;
      Sub *i = start;
      do
      {
        if(i->next == j)
          break; 
        i = i->next;
      }while(i != start);
      do
      {
        if(i->num > key){
          i->next->num = i->num;
          Sub *a = i;
          do
          {
            if(i->next == a)
              break;
            i = i->next;
          }while(i != a);
        }
        else
          break;      
      }while(i->next != start);
      i->next->num = key;

      j = j->next;
    }
  }while(j != start);
}


void freeAll(No *start){
  No *i = start;
  No *next = NULL;
  while(i){
    next = i->next;
    Sub *sub = i->sub;
    if(sub){
      do{
        Sub *s = sub->next;
        free(sub);
        sub = s;
      }while(sub != i->sub);
    }
    free(i);
    i = next;
  }
  
}

void create(No *i,No **start, No **end){
  
  if(*end == NULL || *start == NULL){
    i->next = NULL;
    i->prior = NULL;
    *end = i;
    *start = i;
    return;
  }
  No *p = *start;
  No *old = NULL;
  while(p)
  {
    if(p->number < i->number){
      old = p;
      p = p->next;      
    }
    else
    {
      if(p->prior){
        p->prior->next = i;
        i->next = p;
        i->prior = p->prior;
        p->prior = i;
        return;
      }
      i->next = p;
      i->prior = NULL;
      p->prior = i;
      *start = i;
      return;
    }
  }
  old->next = i;
  i->next = NULL;
  i->prior = old;
  *end = i;
}

void sortSub(Sub *i, Sub **start, Sub **end){
  if(*start == NULL){
    i->next = i;
    *start = i;
    *end = i;
    return;
  }

  Sub *p = *start;
  Sub *old = NULL;

  do
  {
    if(i->num > p->num){
      old = p;
      p = p->next;
    }
    else
    {
      if(p->next != *start){
        Sub *aux = *start;
        do
        {
         if(aux->next == p){
          aux->next = i;
          break;
         }           
          aux = aux->next;
        }while(aux != *start);
        i->next = p;
        return;
      }
      i->next = p;
      p->next = i;
      *start = i;
      return;  
    }
  }while(p != *start);
  
  old->next = i;
  i->next = *start;
  *end = i;
}