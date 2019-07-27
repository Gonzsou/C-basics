/*
 * C - Basics
 * Fibonacci sequence up to given number of elements
 * (fibonacci.c) v20190727
 *
 * Gonzsou
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main () {
	int previous, current, i, n, temp;
	
	system("clear");
	
	printf("Indique um número ");
	scanf("%d", &n);
		
	previous =0;
	current = 1;
	printf ("Fibonacci sequence up to the first %d elements: \n%d, %d, ", n, previous, current);
	for (i=2; i<n; i++){
		temp = current;
		current = previous + current;
		previous = temp;
		if(i==n-1){
			printf("%d", current);
		} else {
			printf("%d, ", current);
		}
	} 
	printf("\n");
	return (0);
}
