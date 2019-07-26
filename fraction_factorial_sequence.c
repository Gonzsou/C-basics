/*
 * C - Basics
 * A sequence of fractional factorials
 * (fraction_factorial_sequence.c) v20190726
 *
 * Gonzsou
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main () {
	int i=2, n, fact=1;
	float sum = 0;

	printf("Introduce an integer: ");
	scanf("%d", &n);
	
	for(i=2;i<n+2;i++){							//controls the number of parcels to calculate
		
		fact=fact*i;								//calculates parcel's denominator 
		
		sum = sum + ((float)(i-1)/fact);	//calculates i-th parcel and updates variable sum
		
		if(i==2){									// conditional just to format the expression to be presented
			printf("%d/%d! ", i-1, (i));
		} else {
			printf(" + %d/%d! ", i-1, (i));
		}
	}
	printf("= %f\n", sum);
}