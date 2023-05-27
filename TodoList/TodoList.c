#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "TodoList.h"

char *timeNow();
int menu();
void createToDoList();
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
  puts("\t\t Welcome to the Todo");
  puts("[1]Create Todo");
  puts("[2]Exit");
  printf("> ");
  do{
    scanf("%d", &option);
  }while(option!=1 && option!=2);
  return option;
}

void createToDoList(){  
  ToDOList list;
  char *namefile = "C:/Users/User/OneDrive/Documentos/All Obsidian Notes/ToDo/";
  fflush(stdin);
  printf("Nome da Tarefa: ");
  fgets(list.name, sizeof(list.name), stdin);
  int tam = strlen(namefile) + strlen(list.name) + strlen(".md");
  char *path = malloc(tam * sizeof(char));
  tam = strlen(list.name);
  list.name[tam-1] = '\0';
  strcpy(path, namefile);
  strcat(path, list.name);
  strcat(path, ".md");
  FILE *fp_out = fopen(path, "w");  
  list.hora = timeNow();
  tam = strlen(list.hora) + 4;
  text = malloc(tam);
  sprintf(text, "==%s\n", list.hora);
  printf("Description: ");
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
    printf("ToDo: ");
    fgets(list.todo, sizeof(list.todo), stdin);
    tam = strlen("- [ ]  ") + strlen(list.todo) + 3 + strlen(text);
    text = realloc(text, tam);
    strcat(text, "- [ ]  ");
    strcat(text, list.todo);
    strcat(text, "\n");
    fflush(stdin);
    printf("Deseja adicionar mais um ToDo? (y/n)");
    scanf("%c", &c);
  } while (c != 'n');
  fputs(text, fp_out);  
  fclose(fp_out);
}

void sair(){
  int count = 0;
  while(!count){
    system("cls");
    printf("\t    Saindo");
    for(int i = 0 ; i < 3; i++){
      printf(".");
      sleep(1);
    }
    count++;
  }
  puts("\n\tCreate by Victor");
  sleep(1);
  exit(0);
}