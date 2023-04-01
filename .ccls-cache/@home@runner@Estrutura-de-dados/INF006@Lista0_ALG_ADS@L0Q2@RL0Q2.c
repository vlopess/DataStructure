// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include <locale.h>
// int ordenaportipo(char *resposta);
// int ordenastring(char *resposta, char *stringaux);
// int ordenanumeros(char *resposta, char *inteiroaux);
// int ordenapontos(char *resposta, char *pontoaux);

// int main(){
//   setlocale(LC_ALL, "");
//   FILE *fp_in  = fopen("L0Q2.in", "r");
//   FILE *fp_out = fopen("L0Q2.out", "w");
  
//   if (fp_in == NULL || fp_out == NULL){
//     printf("Erro na leitura dos arquivos");
//     return EXIT_FAILURE;
//   }
    
//     char file[255];
//     char splitHere[] = " ";
//     char *slice;
//     char text[20];
//     char resposta[100];
//     printf("ok");
//     //maria 3.15 jose 4 8 −1 12.7 −1,−1 julia −0.5 ,−0.5 TA SEM OS PARENTESES
//     while(fgets(file, 255, fp_in) != NULL) {  
//       slice = strtok(file, splitHere);
//       stpcpy(resposta, slice); 
//       resposta[strlen(resposta) + 1] = ' ';
//       while (slice != NULL){ 
        
//            //sprintf(text, "%s", slice);
//            //fputs(text, fp_out);
//            //fputs("\n", fp_out);        
//           slice = strtok(NULL, splitHere);
//           strcpy(resposta, slice);
//           resposta[strlen(resposta) + 1] = ' ';
//       }
//       printf("Resposta sem ordenar:%s\n", resposta);
//       //ordenaresposta(resposta);
//       //printf("Resposta com ordenacao: %s\n", resposta);
//       fclose(fp_in);
//       fclose(fp_out);
//       return EXIT_SUCCESS;
//     }
  
//   ordenaportipo(resposta);
// }

// int ordenaportipo(char *resposta) {
//     char stringaux[99], inteiroaux[99], pontoaux[99];
//     /*ta tendo algum problema que a string simplesmente fica null,
//     entao dessa forma eu garanto que o conteudo da string nao se perde*/
//     setbuf(stdin, 0);
//     ordenastring(resposta, stringaux);
//     ordenapontos(resposta, pontoaux);
//     setbuf(stdin, 0);
//     strcpy(resposta, "sergio silva 1.43 4 5 (9,8) (5,1) joao 55.1");
//     ordenanumeros(resposta, inteiroaux);
    
//   return 0;
// }
// int ordenastring(char *resposta, char *stringaux) {

//   int i=0, j=0;
//   while(resposta[i] != '\0') {
//     setbuf(stdin, 0);
//     if(resposta[i] >= 'a' && resposta[i] <= 'z') {
//         for(; resposta[i] != ' '; i++) {
//             setbuf(stdin, 0);
//             stringaux[j] = resposta[i];
//             j++;
//         }
//       setbuf(stdin, 0);
//       stringaux[j] = ' ';
//       j++;
//     }
//     i++;
//   }
// printf("Resposta: %s\n", resposta);
// stringaux[j] = '\0';
// setbuf(stdin, 0);
// printf("Stringaux: %s\n", stringaux);
// return 0;
// }
// int ordenanumeros(char resposta[], char *inteiroaux) {
//   int i=0, j=0;
  
//   while(resposta[i] != '\0') {
//     setbuf(stdin, 0);
//     if(resposta[i] == '(') {
//       i+=11;
//     }
//     if((resposta[i] >= '0' && resposta[i] <= '9') || resposta[i] == '-') {
//         for(; resposta[i] != ' '; i++){
//             setbuf(stdin, 0);
//             inteiroaux[j] = resposta[i];
//             j++;
//         }
//         inteiroaux[j] = ' ';
//         j++;
//     }
//     i++;
//   }

// inteiroaux[j] = '\0';
// setbuf(stdin, 0);
// printf("Numero aux: %s\n", inteiroaux);
// setbuf(stdin, 0);
// return 0;
// }
// int ordenapontos(char *resposta, char *pontoaux) {
// setbuf(stdin, 0);
//   int i=0, j=0;
//   while(resposta[i] != '\0') {
//     setbuf(stdin, 0);
//     if(resposta[i] == '(') {
//         for(; resposta[i] != ' '; i++) {
//             setbuf(stdin, 0);
//             pontoaux[j] = resposta[i];
//             j++;
//         }
//       setbuf(stdin, 0);
//       pontoaux[j] = ' ';
//       j++;
//     }
//     i++;
//   }
// pontoaux[j +1] = '\0';
// setbuf(stdin, 0);
// printf("Pontoaux: %s\n", pontoaux);
// return 0;
// }

// /*
// void insertionSort(char *A) {
//   int troca = 1;
//   char *token;
//   char stringcomnome[80];
//   char stringcopia[15];
//   strcpy(stringcomnome, A);
//     while(troca > 0) {
//       troca=0;
//       token = strtok(stringcomnome, " ");
      
//       while(token!=NULL) {
//         strcpy(stringcopia, token);
//         token = strtok(NULL, " ");
         
//         if(strcmp(token, stringcopia) > 0) {
//           strcpy(stringcopia, token);
//           strcpy(A, stringcopia);
//       printf("Printando so para testar: %s\n", A);
//         } 
        
//       }
      
//       troca++;
//     }
// }
// */
