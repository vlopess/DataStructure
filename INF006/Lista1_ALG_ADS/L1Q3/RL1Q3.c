#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    FILE *fp_in = fopen("L1Q1.in", "r");
    FILE *fp_out = fopen("L1Q1.out", "w");
    
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro na leitura dos arquivos\n");
        return EXIT_FAILURE;
    }

    
    char file[255];
    while(fgets(file, 255, fp_in) != NULL){
        
        
        
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
