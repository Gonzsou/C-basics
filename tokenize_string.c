#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_BUFFER 100

#pragma warning(disable : 4996)

void writeToFile(char **str) {

    FILE *fp = (FILE *)malloc(sizeof(FILE*));

    fp = fopen("strings.txt", "w");

    if (fp == NULL){
        perror("erro na criação ou abertura de ficheiro");
        exit(EXIT_FAILURE);
    }
    fprintf(stdin, "Ficheiro criado/aberto com sucesso");

    // código-fonte para editar ficheiro


    fwrite(str, sizeof(str), 1, fp);
    
    fclose(fp);
}


int main() {
    FILE* f = stdin; // ler os dados do stdin

    // Buffer até 99 caracteres mais o caracter nulo  
    char buffer[MAX_BUFFER];

    //ponteiro alocar memória para a string
    char* str;
    int n, cod;

    //Solicita nome da disciplina ao utilizador
    //
    
    //recebe dados inseridos pelo utilizador, limitado pela dimensao MAX_BUFFER
    fgets(buffer, MAX_BUFFER, f);

    // substitui o carater nova linha pelo caracter terminal nulo
 /*   int i;
    for (i = 0; i < n; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
        }
    }
*/
    //calcula comprimento da string inserida mais o caracter nulo
    n = strlen(buffer) + 1;

    //copia a string recebida para o espaço de memória alocada dinamicamente
    str = (char*)malloc(n * sizeof(char));

    //caso falhe a alocacao de memória, lidar com o erro e sair 
    if (str == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }
    
    // copia buffer para str
    strcpy(str, buffer);
    //printf("%s", str);
  
    // Separa palavras de uma string
    char *delim = "0123456789- ";  // string contendo todos os caract delimitadores pretendidos para usar na funcao strtok

    n = strlen(str) + 1;
    char* auxStr;       // usa copia de str pq strtok() altera a string original
    auxStr = (char*)malloc(n * sizeof(char));

    strcpy(auxStr, str); 

    char* palavraPtr;    // ponteiro para primeiro carater da palavra
    palavraPtr = strtok(auxStr, delim);
    
    static int conta = 0;
    conta = strlen(palavraPtr)-1;
    //printf("conta: %d\n", conta);

    while (palavraPtr != NULL) {    //strtok() retorna null qd string esta toda dividida
        palavraPtr = strtok(NULL, delim);
    //    printf("'%s'\n", palavraPtr);
        conta += strlen(palavraPtr);
        printf("%d\n", conta);
    }
    printf("conta: %d\n", conta);




    // writeToFile(&str);

    return 0;
}
