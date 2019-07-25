/*
 * C - Basics
 * Prime numbers within a given range
 * (primes_up_to_n.c) v20190725
 *
 * gonzsou
 *
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, m, i, k, flag, count=0;

	printf("Two integers equals or greater than 2, for lower and upper limits of the range:\n");
	do{
		printf("lower limit:");
		scanf("%d", &m);
	} while(m<2);
	getchar();
	do{
			printf("upper limit:");
			scanf("%d", &n);
		} while(n<2||n<m);
	
	for (i=m; i<=n; i++){	// each i-th number is assessed by following code to check if it'is prime number
		flag = 1;
		for (k=2; k<=i/2; k++){		// optimization. Evaluates the first half of the number given by the user
			if(i%k==0){					// evaluates if the i-th number is divisible by any number other than 1 and itself			
				flag = 0;					// if condition above evaluates true, i-th number is not prime number, hence flag is set to 0
				break;						// no need to continue in this iteration
			}
		}
		if(flag == 1){						// conditional using flag value in order to print the numbers that are prime  
			printf("%d	", i);
			count++;
		}
	}
	printf("\nThere are %d prime numbers between number %d and number %d \n", count, m, n);
}