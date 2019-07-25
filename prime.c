/*
 * C - Basics
 * Prime numbers (prime.c)
 * v20190725
 *
 * gonzsou
 *
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, i;
	
	do{
		printf("Please indicate an integer equals or greater than 2: ");
		scanf("%d", &n);
	} while(n<2);
	
	for (i=2; i<=n/2; i++){		//optimization. evaluates only the first half of the number given by the user
		if(n%i==0){
			printf("%d is not prime because it's divisible not only by 1 and itself, but also at least by %d.\n", n, i);
			getchar();
			exit(1);					
		}
	}
	printf("%d is a prime number because it's divisible by only 1 and itself.\n", n);	
}