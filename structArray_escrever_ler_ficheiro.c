#include <stdio.h>
#include <stdlib.h>

#define NUM_CARS 4

typedef struct S_CARRO {
	int referencia;
	char marca[10];
	int ano;
} t_carro;

void WriteToFile (t_carro *buffer) {
	FILE *fp;
	fp = fopen("data.bin", "wb");
	
	if(fp==NULL) {											
		perror("Erro na criacao do ficheiro\n\n");
		exit(1);
	} else{
		printf("Ficheiro criado com sucesso\n\n");
	}
//	int numElementos = sizeof(buffer)/sizeof(buffer[0]);  //usar sizeof(buffer[0]) em vez de sizeof(t_carros) mais eficiente caso se pretenda mudar o tipo de dados 't_carro'  p.exemplo
	size_t  numElementos;							/* atencao ao tipo de dados size_t   */
	numElementos = fwrite(buffer, sizeof(t_carro), sizeof(buffer), fp); 	// fwrite() retorna nr de elementos em bytes escritos com sucesso 
	printf("%ld elementos escritos com sucesso\n\n", numElementos);
	if(ferror(fp)){																// ferror() retorna valor dif de zero se o indicador de erros associado ao stream 'fp' estiver ativo
		printf("Erro na escrita dos dados para o ficheiro\n\n");
		clearerr(fp);															// reset dos indicadores de erro e eof do stream 'fp' 
	}
	fclose(fp);		
}

void readFromFile(t_carro *arrayCarros){
	FILE *fp;
	fp = fopen("data.bin", "rb");

	if(fp == NULL) {
		perror("falha na abertura do ficheiro. Erro: ");
		exit(1);
	}
	printf("Ficheiro aberto com sucesso\n");
	
	arrayCarros=malloc(sizeof(t_carro)*NUM_CARS);
	size_t n;
	n = fread(arrayCarros, sizeof(t_carro), NUM_CARS, fp);
	printf("Elementos lidos do ficheiro  com sucesso: %ld \n\n", n);
	int i;
	for (i=0;i<NUM_CARS; i++) {
		printf("Referencia:%d	Marca:%s	Ano:%d\n", arrayCarros[i].referencia, arrayCarros[i].marca, arrayCarros[i].ano);
	}
	free(arrayCarros);
	fclose(fp);
}

int main( ) {
	
	t_carro dados[] = {
					{001, "BMW", 2018},
					{002, "Fiat", 2013},
					{003, "Toyota", 2002},
					{004, "Fusca", 1963}
	};

	int i;
	for( i = 0; i<NUM_CARS; i++){
		printf("ref:%d	marca:%s	ano:%d\n", dados[i].referencia, dados[i].marca, dados[i].ano);
	}
	
	WriteToFile(dados);
		
	t_carro temp;
	readFromFile(&temp);
}
