// Alunos: Sérgio Cerqueira e Victor Lopes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tree{
  int num;
  struct tree *right;
  struct tree *left;
}Tree;

Tree *putInTree(Tree *root, Tree *r, int num);
void ordem(Tree *root, FILE *fp_out);
int Sum(Tree *raiz, Tree *r);

int main(){
    FILE *fp_in = fopen("L2Q2.in", "r");
    FILE *fp_out = fopen("L2Q2.out", "w");
    
    
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
          root = putInTree(root, root, num);
        else
          putInTree(root, root, num);
        slice = strtok(NULL, space);
      }
      ordem(root, fp_out);
      fputs("\n", fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}


Tree *putInTree(Tree *root, Tree *r, int num){
  if(!r){
    Tree *novo = (Tree *) malloc(sizeof(Tree));
    novo->left = NULL;
    novo->right = NULL;
    novo->num = num;
    if(!root) 
      return novo;
    if(root->num > num) root->left = novo;
    else root->right = novo;
    return novo;
  }  
  if(r->num > num)
    putInTree(r, r->left, num);
  else if(r->num < num)
    putInTree(r, r->right, num);
}


int Sum(Tree *raiz, Tree *r){
  int sum = 0;
  if(!r) return 0;
  sum += Sum(raiz, r->left);
  if(r != raiz) sum += r->num;
  sum += Sum(raiz, r->right);
  return sum;
}


void ordem(Tree *root, FILE *fp_out){
  if(!root) return;
  ordem(root->left, fp_out);
  int sum = Sum(root, root->right) - Sum(root, root->left);
  fprintf(fp_out,"%d (%d) ", root->num, sum);
  ordem(root->right, fp_out);
}

