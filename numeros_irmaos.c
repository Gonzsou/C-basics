#include <stdio.h>
#include <stdlib.h>

void NumerosIrmaos(){
  	int num1, num2;
  	printf("\n Please enter two integers:  ");
  	scanf("%d %d", &num1, &num2);

	int i, j, isPrime, fator1=1, fator2=0; 
	for (i = 2; i <= num1; i++) {
		if(num1 % i == 0) {
			isPrime = 1;
			for (j = 2; j <= i/2; j++) {
				if(i % j == 0) {
					isPrime = 0;
					break;
				}
			} 
			if(isPrime == 1) {
				fator1=i;
			}         	
		}
	}
	for (i = 2; i <= num2; i++) {
		if(num2 % i == 0) {
			isPrime = 1;
			for (j = 2; j <= i/2; j++) {
				if(i % j == 0) {
					isPrime = 0;
					break;
				}
			} 
			if(isPrime == 1) {
				fator2=i;
			}         	
		}
	}
//	printf("\n fator1: %d ", fator1);
//	printf("\n fator2: %d ", fator2);
	if(fator1!=fator2) {
		printf("\n%d e %d não sao numeros irmãos.\n", num1, num2);
	} else {
		printf("\n%d e %d sao numeros irmãos.\n", num1, num2);
	}
}

int main(void) {
	NumerosIrmaos();
	return 0;
}
