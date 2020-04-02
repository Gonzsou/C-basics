#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#pragma setlocale("English_Europe.28591")

char* ConverteAcentos(char *str) {	//Converte letras com acentos em carateres simples
	int i = 0;
	for (i = 0;i < strlen(str); i++) {
		switch (str[i]) {
		case (char)(0xe0 + 0) :
		case (char)(0xe0 + 1) :
		case (char)(0xe0 + 2) :
		case (char)(0xe0 + 3) :
		case (char)(0xe0 + 4) :
		case (char)(0xe0 + 5) :
			str[i] = 'a';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xc0 + 0) :
		case (char)(0xc0 + 1) :
		case (char)(0xc0 + 2) :
		case (char)(0xc0 + 3) :
		case (char)(0xc0 + 4) :
		case (char)(0xc0 + 5) :
			str[i] = 'A';
//			printf("\n##-->%c", str[i]);
			break;		
		case (char)(0xe0 + 8) :
		case (char)(0xe0 + 9) :
		case (char)(0xe0 + 10):
		case (char)(0xe0 + 11):
			str[i] = 'e';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xc0 + 8) :
		case (char)(0xc0 + 9) :
		case (char)(0xc0 + 10):
		case (char)(0xc0 + 11):
			str[i] = 'E';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xe0 + 12):
		case (char)(0xe0 + 13):
		case (char)(0xe0 + 14):
		case (char)(0xe0 + 15):
			str[i] = 'i';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xc0 + 12):
		case (char)(0xc0 + 13):
		case (char)(0xc0 + 14):
		case (char)(0xc0 + 15):
			str[i] = 'I';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xd0 + 2) :
		case (char)(0xd0 + 3) :
		case (char)(0xd0 + 4) :
		case (char)(0xd0 + 5) :
		case (char)(0xd0 + 6) :
		case (char)(0xd0 + 8) :
			str[i] = 'O';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xf0 + 0) :
		case (char)(0xf0 + 2) :
		case (char)(0xf0 + 3) :
		case (char)(0xf0 + 4) :
		case (char)(0xf0 + 5) :
		case (char)(0xf0 + 6) :
		case (char)(0xf0 + 8) :
			str[i] = 'o';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xd0 + 9) :
		case (char)(0xd0 + 10):
		case (char)(0xd0 + 11):
		case (char)(0xd0 + 12):
			str[i] = 'U';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xf0 + 9) :
		case (char)(0xf0 + 10):
		case (char)(0xf0 + 11):
		case (char)(0xf0 + 12):
			str[i] = 'u';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xd0 + 1) :
			str[i] = 'N';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xf0 + 1) :
			str[i] = 'n';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xc0 + 7) :
			str[i] = 'C';
			//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xe0 + 7) :
			str[i] = 'c';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0x90 + 15) :
		case (char)(0xd0 + 13) :
			str[i] = 'Y';
//			printf("\n##-->%c", str[i]);
			break;
		case (char)(0xf0 + 13) :
		case (char)(0xf0 + 15) :
			str[i] = 'y';
//			printf("\n##-->%c", str[i]);
			break;
		default:
			break;
		}
	}
	return str;
}

char* RemoveSimbolos(char* str) {
	//Remove carateres que nao sejam letras do alfabeto 
	int i = 0;
	int conta = 0;
	for (i = 0;i < strlen(str); i++) {
		if (isalpha(str[i])) {
			continue;
		}
		else {
			while (i <= strlen(str)) {
				str[i] = str[i + 1];
				i++;
			}
			conta++;
		}
		i = -1;
	}
//	printf("\n\nFrase: %s\n", str);	//imprime palavra

	for (i = 0; i < strlen(str); i++) {
		str[i] = toupper(str[i]);
	}
//	printf("\n\nFrase: %s\n", str);	//imprime palavra
	return str;
}

int TestaPalindromo(char *str) {	// retorna 1 se teste válido
	int flag = 0;
	int i = 0;
	while (i <= strlen(str) / 2) {
		if (str[i] == str[strlen(str) - i - 1]) {
			i++;
			continue;
		}
		else {
			flag = 1;
			break;
		}
	}
	return flag;
}

void LeFicheiro() {
	FILE* fp;
//	fp = (FILE *)malloc(sizeof(FILE));
	fp = fopen("frases.txt", "r");

	if (fp == NULL) {
		perror("Erro ao abrir ficheiro. Erro: ");
		exit(-1);
	}
	int i = 0;
	char linha[100];

	char* array[100]=malloc(sizeof(char *linha[100]);

	while (fp) {
		printf("Certo\n");
		fprintf(fp, "%s\n", linha);
		i++;
	}
	fclose(fp);
}

int main(void) {

	char tmp[50];
	char str[50];
	printf("Indique uma string: ");
	fgets(str, 50, stdin);
	strncpy_s(tmp,sizeof(str), str, strlen(str));

	ConverteAcentos(str);

	RemoveSimbolos(str);
 
	int palindromo = TestaPalindromo(str);

	if (palindromo) {
		printf("%s", tmp);
		printf("Não é Palindromo");
	}
	else {
		printf("%s", tmp);
		printf("É palindromo");
	}

	LeFicheiro();

	return 0;
}
