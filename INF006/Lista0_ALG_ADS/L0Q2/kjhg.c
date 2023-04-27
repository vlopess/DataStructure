#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Protótipo das Funções:

int main (){

	FILE *fp_in	=  fopen ("L0Q2.in", "r");
	FILE *fp_out = fopen ("L0Q2.out", "w");

	if ( fp_in == NULL || fp_out == NULL ){
		printf("O arquivo não pode ser lido.\n");
		return(1); // retornar um erro
	}
	char linha[256];
	char separador[1]	=	" "; // o que vai separar os tipos é  1 espaço 
	
	while(fgets(linha,255,fp_in)	!=	NULL){// aqui ta lendo linha por linha até chegar o 255
		char strings_strings[255];
		int i_string =	0;
		
		char strings_pontos[256];
		int i_ponto	=	0;
		
		char int_or_floats[256];
		int aux	=	0;
		int is_float = 0;
		int guarda_i;
		int guarda_aux;
		char strings_floats[256];
		int i_float = 0;
		int i_inteiro	=	0;
		char string_inteiros[256];
		int c = 0;
		int i =	0;
		// Fazer até o final da linha.
		while(linha[i] != '\0'){
			
			if(	linha[i] >= 97 && linha[i] <= 122	){	// se for string
				for(; linha[i] !=  separador[0]; i++ ,i_string++ ){
					strings_strings[i_string] = linha[i];
				}
				i_string++;
				strings_strings[i_string]	=	' '; // separar as strings entre ' '
				//printf("%s\n", string); //TESTE
				 
			} else if (linha[i] == '('){	//se for um ponto
				for(;	linha[i]	!= separador[0]	;	i++	,	i_ponto++){ // se for um ponto
					strings_pontos[i_ponto]	=	linha[i];
				}
				i_ponto++;
				strings_pontos[i_ponto]	=	' ';
				//printf("%s\n", )
				// dentro da variável strings_pontos[i_ponto] = "(-5.8,90)"
			}else {
				guarda_i	=	i;
				guarda_aux = aux;
				for(;	linha[i] != separador[0]	; i++,aux++){
					 int_or_floats[aux] = linha[i];
						if (linha[i] == '.'){
							is_float = 1; // é um inteiro, pois tem 1 ponto
						}
				}
				aux++;
				int_or_floats[aux] = '/'; // separar na variável
				c = i;
                i = guarda_i;// retornou ao valor de i inicial!
				aux = guarda_aux;
				if (is_float == 1){ // é um numero Real 
						while(int_or_floats[aux] !=	'/'){
						 // retornou ao valor aux inicial!
							for(;	linha[i]	!= separador[0]	; i++,i_float++){
								strings_floats[i_float]	= linha[i];
							}
							i_float++;
							strings_floats[i_float]	=	' '; // colocar para separar os floats
						}
					} else { // se Não é um float é um inteiro!
						while(int_or_floats[aux] !=	'/'){
							for(; linha[i]	!=	separador[0]	;	i++,i_inteiro++){
								string_inteiros[i_inteiro]	=	linha[i];
							}
							i_inteiro++;
							string_inteiros[i_inteiro]	=	' '; // para separar os inteiros 
						}
					}
				 aux++;
			}
            i = c;
			fprintf(fp_out,"str:%sint%sfloat:%sp:%s",strings_strings,string_inteiros,strings_floats,strings_pontos);
			// falta ordenar!
		}
	}
fclose (fp_out);
fclose (fp_in);
}
// Modularizações 