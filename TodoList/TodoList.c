#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "TodoList.h"

char *timeNow();
int menu();
void createToDoList();
void salvar(FILE *file);
void sair();

char *text = NULL;
int main(){
  while(1){
    switch(menu()){
      case 1: createToDoList(); 
        break;
      case 2: sair();
    }
  }  
  return EXIT_SUCCESS;
}

char *timeNow(){
  time_t lt = time(NULL);
  struct tm *ptr = localtime(&lt);
  return asctime(ptr);
}

int menu(void){
  int option;
  system("cls");
  puts("\t\t\t\t\t\t\t Welcome to the Todo");
  puts("\t\t\t\t\t[1]Create Todo");
  puts("\t\t\t\t\t[2]Exit");
  printf("\t\t\t\t\t> ");
  do{
    scanf("%d", &option);
  }while(option!=1 && option!=2);
  return option;
}

void createToDoList(){  
  ToDOList list;
  char *pathinit = "C:/Users/User/OneDrive/Documentos/All Obsidian Notes/ToDo/";
  fflush(stdin);
  printf("\t\t\t\t\tNome da Tarefa: ");
  fgets(list.name, sizeof(list.name), stdin);
  int tam = strlen(pathinit) + strlen(list.name) + strlen(".md");
  char *path = malloc(tam * sizeof(char));
  tam = strlen(list.name);
  list.name[tam-1] = '\0';
  strcpy(path, pathinit);
  strcat(path, list.name);
  strcat(path, ".md");
  FILE *fp_out = fopen(path, "w");  
  list.hora = timeNow();
  tam = strlen(list.hora) + 4;
  text = malloc(tam);
  sprintf(text, "==%s\n", list.hora);
  printf("\t\t\t\t\tDescription: ");
  fgets(list.Description, sizeof(list.Description), stdin);
  tam = strlen("**Descricao: ") + strlen(list.Description) + strlen(text) + 3;
  text = realloc(text, tam);
  strcat(text, "**Descricao: ");
  strcat(text, list.Description);
  strcat(text, "\n");
  char c;
  do
  {    
    fflush(stdin);
    printf("\t\t\t\t\tToDo: ");
    fgets(list.todo, sizeof(list.todo), stdin);
    tam = strlen("- [ ]  ") + strlen(list.todo) + 3 + strlen(text);
    text = realloc(text, tam);
    strcat(text, "- [ ]  ");
    strcat(text, list.todo);
    fflush(stdin);
    do{
      printf("\n\t\t\t\t\tDeseja adicionar mais um ToDo? (y/n)");
      scanf("%c", &c);
    }while(c != 'y' && c != 'n');
  } while (c == 'y');
  salvar(fp_out);  
  fclose(fp_out);
  free(text);
}

void sair(){
  int count = 0;
  while(!count){
    system("cls");
    printf("\t\t\t\t\t    Saindo");
    for(int i = 0 ; i < 3; i++){
      printf(".");
      sleep(1);
    }
    count++;
  }
  puts("\n\t\t\t\t\tCreate by Victor");
  sleep(1);
  exit(0);
}

void salvar(FILE *file){
  int count = 0;
  while(!count){
    system("cls");
    printf("\t\t\t\t\t   Salvando");
    for(int i = 0 ; i < 3; i++){
      printf(".");
      sleep(1);
    }
    fputs(text, file);
    count++;
  }
}