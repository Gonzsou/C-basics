
#include <stdio.h>
#include <stdlib.h>

int NumerosIrmaos(int num1, int num2){
	int min, max;
	if (num1<num2){
		min = num1;
		max = num2;
	} else {
		min=num2;
		max=num1;
	}
	int i, j, primo;
	for (i = 2; i <= max; i++) {
     	if(max % i == 0) {
   			primo = 1;
			for (j = 2; j <= i/2; j++) {
				if(i % j == 0) {
					primo = 0;
					break;
				}
			} 
			if(primo == 1) {
				printf("\n %d is a Prime Factor ", i);
				if(min%i!=0){
					printf("\n %d e %d nao sao numeros irmaos.", min, max);
					return 0;
				}
			}	          	
		}
	}
	printf("\n %d e %d sao numeros irmaos.", min, max);
	return 1;
}

int main (void){
	int num1=3, num2=15;
	NumerosIrmaos(num1, num2);
	
	return 0;
}
