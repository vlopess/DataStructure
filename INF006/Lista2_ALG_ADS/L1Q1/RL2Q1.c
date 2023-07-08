// Alunos: Sérgio Cerqueira e Victor Lopes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree{
  int num;  struct tree *right;
  struct tree *left;
}Tree;

Tree *putInTree(Tree *root, Tree *r, int num, int tam, FILE *fp_out);
void findMAximum(Tree *pred, Tree *max, int tam, FILE *fp_out);

int main(){
    FILE *fp_in = fopen("L2Q1.in", "r");
    FILE *fp_out = fopen("L2Q1.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }

    char file[255];
  
    while(fgets(file, 255, fp_in) != NULL){  
      Tree *root = NULL;
      
      char *space = " ";
      char *slice = strtok(file, space);
      
      while(slice){
        int num = atoi(slice);
        if(!root)
          root = putInTree(root, root, num, 0, fp_out);
        else
           putInTree(root, root, num, 0, fp_out);
        slice = strtok(NULL, space);
      }
      findMAximum(NULL, root, 0, fp_out);
      fputs("\n", fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}

Tree *putInTree(Tree *root, Tree *r, int num, int tam, FILE *fp_out){
  if(!r){
    Tree *novo = (Tree *) malloc(sizeof(Tree));
    novo->left = NULL;
    novo->right = NULL;
    novo->num = num;
    fprintf(fp_out, "%d ", tam);
    if(!root) 
      return novo;
    if(root->num > num) root->left = novo;
    else root->right = novo;
    return novo;
  }  
  if(r->num > num)
    putInTree(r, r->left, num, tam+1, fp_out);
  else
    putInTree(r, r->right, num, tam+1, fp_out);
}

void findMAximum(Tree *pred, Tree *max, int tam,  FILE *fp_out){
  if(max->right){
    findMAximum(max, max->right, tam+1, fp_out);
    return;    
  }
  fprintf(fp_out, "%s %d %s %d ", "max", max->num, "alt",tam);
  if(pred)
    fprintf(fp_out, "%s %d", "pred",pred->num);
  else
    fprintf(fp_out, "%s","pred NaN");
}
