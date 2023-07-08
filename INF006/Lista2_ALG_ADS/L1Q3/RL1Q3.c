// Alunos: Sérgio Cerqueira e Victor Lopes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    int value;
    struct node *left, *right;
} Tree;

Tree *InsertTree(Tree *root, Tree *r, Tree *novo);
int TreeSearch(Tree **raiz, Tree *root, int key);
void WriteSortedTree(Tree *root, int nodeHeight, FILE *fp_out);
void InsertSeveralTree(Tree **raiz, Tree *novo);
void create(Tree **root, int num);
Tree *findAntecessor(Tree* ant,Tree* node, int key);

int main() {
  FILE *fp_in = fopen("L2Q3.in", "r");
  FILE *fp_out = fopen("L2Q3.out", "w");
    
  if(fp_in == NULL || fp_out == NULL) {
    puts("Erro na leitura dos arquivos");
    return EXIT_FAILURE;
  }
  Tree *root = NULL;
  char file[255];
  while(fgets(file, 255, fp_in) != NULL){
    char *space = " ";
    char *slice = strtok(file, space);
    while(slice){
      if(strcmp(slice, "a") == 0) {
        slice = strtok(NULL, space);
        int num = atoi(slice);
        create(&root, num);
      }
      if(strcmp(slice, "r") == 0) {
        slice = strtok(NULL, space);
        int num = atoi(slice);
        if(!TreeSearch(&root, root, num)){       
          create(&root, num);
        }
      }      
      slice = strtok(NULL, space);
    }
    WriteSortedTree(root, 0, fp_out);
    fputs("\n", fp_out);
    root = NULL;
  }
  fclose(fp_in);
  fclose(fp_out);
  return EXIT_SUCCESS;
}

void create(Tree **root, int num){
  Tree *newTree = (Tree*) malloc(sizeof(Tree));
  newTree->value = num;
  newTree->left = NULL;
  newTree->right = NULL;
  if(!*root)
    *root = InsertTree(*root, *root, newTree);
  else
    InsertTree(*root, *root, newTree);
}

Tree *InsertTree(Tree *root, Tree *r, Tree *novo) {
  if(!r){
    if(!root) 
      return novo;
    if(root->value > novo->value) root->left = novo;
    else root->right = novo;
    return novo;
  }
  if(r->value > novo->value)
    InsertTree(r, r->left, novo);
  else
    InsertTree(r, r->right, novo);
}


void InsertSeveralTree(Tree **raiz, Tree *novo){
  if(!novo) return;
  if(!*raiz)
    *raiz = InsertTree(*raiz, *raiz, novo);
  else
    InsertTree(*raiz, *raiz, novo);
  Tree *right = novo->right; 
  Tree *left = novo->left;
  novo->left = NULL;
  novo->right = NULL;
  InsertSeveralTree(raiz, right);
  InsertSeveralTree(raiz, left);
}
int TreeSearch(Tree **raiz, Tree *root, int key) {
  if(root == NULL) {
    return 0;
  } else {
      if(root->value == key){
        Tree *right = root->right; 
        Tree *left = root->left;
        if(root == *raiz){
          *raiz = NULL;
        }else{
          Tree *node = findAntecessor(*raiz, *raiz, key);
          if(node->value > key)
            node->left = NULL;
          else
            node->right = NULL;
        }
        free(root);
        root = NULL;
        InsertSeveralTree(raiz, right);
        InsertSeveralTree(raiz, left);
        return 1;
      }else {
        if(key < root->value)
          return TreeSearch(raiz, root->left, key);
        else
          return TreeSearch(raiz, root->right, key);
      }
   }
}

void WriteSortedTree(Tree *root, int nodeHeight, FILE *fp_out) {
  if(!root) return;
  WriteSortedTree(root->left, nodeHeight + 1, fp_out);
  fprintf(fp_out,"%d (%d) ", root->value, nodeHeight);
  WriteSortedTree(root->right, nodeHeight + 1, fp_out);
}
Tree *findAntecessor(Tree* ant,Tree* node, int key) {
  if(node->value == key)
    return ant;
  if(node->value > key)
    return findAntecessor(node, node->left, key);
  else
    return findAntecessor(node, node->right, key);
}