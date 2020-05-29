#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
	FILE *pFicheiro;
	char *buffer;
	long dimFicheiro;
	size_t resultado;
	
	pFicheiro = fopen("produtos.txt", "rb");						// Abre ficheiro
	if(pFicheiro==NULL){											// Verifica abertura de ficheiro
		perror("Ocorreu um erro na abertura do ficheiro. Erro ");
		exit(EXIT_FAILURE);
	}

	fseek(pFicheiro, 0, SEEK_END);			                            // posiciona ponteiro no fim do ficheiro
	dimFicheiro = ftell(pFicheiro);			                            // se for fluxo binario indica o numero de bytes, se for fluxo de texto o resultado é undefined
	rewind(pFicheiro);			                                        // reposiciona ponteiro para o inicio do ficheiro 
		
	buffer = malloc(sizeof(char)*dimFicheiro);                          //aloca memória suficiente para todo o ficheiro 
	if(buffer==NULL){			//verifica alocacao de memoria
		perror("Ocorreu um erro ao alocar memoria. Erro ");
		exit(EXIT_FAILURE);
	}
	
	//copia o conteudo do ficheiro para o buffer
	resultado = fread(buffer, dimFicheiro, 1, pFicheiro);			    //fread retorna numero de elementos lidos
	if(resultado != 1){				                                    // se numero elementos lidos for diferente do parametro count que é neste caso 1, ocorreu um erro na leitura do ficheiro
		perror("Ocorreu um erro na leitura do ficheiro. Erro ");
		exit(EXIT_FAILURE);
	}

	//FAZ ALGO COM O CONTEUDO DO FICHEIRO CARREGADO PARA O BUFFER
	int i;
	for (i=0; i<strlen(buffer);i++){
		printf("%c", buffer[i]);
	}
	
	//Termina o processo fechando o ficheiro e libertando a memoria
	fclose(pFicheiro);			                                        //fecha ficheiro
	free(buffer);			                                          	  //liberta memoria do buffer
}
