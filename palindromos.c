
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAXBUFFER 100

char* ConverteAcentos(char* str) {	//Converte letras com acentos em carateres simples
	size_t i = 0;
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
			case (char)(0xe0 + 10) :
			case (char)(0xe0 + 11) :
			str[i] = 'e';
			//			printf("\n##-->%c", str[i]);
				break;
			case (char)(0xc0 + 8) :
			case (char)(0xc0 + 9) :
			case (char)(0xc0 + 10) :
			case (char)(0xc0 + 11) :
			str[i] = 'E';
			//			printf("\n##-->%c", str[i]);
				break;
			case (char)(0xe0 + 12) :
			case (char)(0xe0 + 13) :
			case (char)(0xe0 + 14) :
			case (char)(0xe0 + 15) :
			str[i] = 'i';
			//			printf("\n##-->%c", str[i]);
				break;
			case (char)(0xc0 + 12) :
			case (char)(0xc0 + 13) :
			case (char)(0xc0 + 14) :
			case (char)(0xc0 + 15) :
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
			case (char)(0xd0 + 10) :
			case (char)(0xd0 + 11) :
			case (char)(0xd0 + 12) :
			str[i] = 'U';
				//			printf("\n##-->%c", str[i]);
				break;
			case (char)(0xf0 + 9) :
			case (char)(0xf0 + 10) :
			case (char)(0xf0 + 11) :
			case (char)(0xf0 + 12) :
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

char* RemoveSimbolos(char* str) {			//Remove carateres que nao sejam letras do alfabeto 
	size_t i = 0;
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

	for (i = 0; i < strlen(str); i++) {
		str[i] = toupper(str[i]);
	}

	return str;
}

int LogicaPalindromo(char* str) {	// retorna 1 se teste é válido
	int flag = 1;
	size_t i = 0;
	while (i <= strlen(str) / 2) {
		if (str[i] == str[strlen(str) - i - 1]) {
			i++;
			continue;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

void AvaliaPalindromos(){	//Carrega ficheiro de dados e imprime string se a mesma for palindromo
		FILE* fp;
	fp = fopen("frases.txt", "r");
	if (fp == NULL) {
		perror("Erro ao abrir ficheiro. Erro: ");
		exit(1);
	}
	static char str[MAXBUFFER];
	while (fgets(str,sizeof(str),fp) != NULL){
		char tmp[100];

		strcpy(tmp, str);
		ConverteAcentos(str);
		RemoveSimbolos(str);

		int palindromo = LogicaPalindromo(str);

		if (palindromo) {
			printf("%s", tmp);
		}		
	}
	fclose(fp);
}

int main(void) {
	setlocale(LC_ALL, "English-EUROPE.28591");  //cmd.exe-->chcp 28591 (linha de comandos configurada com code page 28591, e ficheiros fonte e de dados com codificação ISO8859-1 
	
	AvaliaPalindromos();

	return (0);
}
