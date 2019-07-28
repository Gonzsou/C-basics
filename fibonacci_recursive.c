/*
 * C - Basics
 * Fibonacci series up to a given number of elements 
 * (fibonacci_recursive.c) v20190727 
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 void fib(int *previous, int *current, int  n ){
	
	/*swaps value stored on 'previous' by value stored in 'current', and calculates new 'current' value*/
	int temp = *current;
	*current += *previous;
	*previous = temp;
	
	/*controls the exit point of recursive function, every recursive function must have a condition in order to stop the recursion*/
	if (n>3){
		printf("%d, ", *current);
		n--;
		fib(previous, current, n);		//recursion call to next element 
	} else if (n==3){
		printf("%d\n", *current); 			//prints last element (last element without comma)
		n--;
	}
 }
 
 int main() {
	 
	 /*base values */
	 int previous = 0;
	 int current = 1;
	 
	 /*requests number fibonacci series elements to print*/
	 int n=0;
	printf("Enter how many elements of fibonacci series you want to print: ");
	scanf("%d", &n);
	
	/*Controls what to print based on the number of elements 'n' entered by the user*/
	if (n==1) {
		printf("%d\n", previous);
	} else if(n==2) {
		printf("%d, %d\n", previous, current);
	} else if (n>2) {
		printf("%d, %d, ", previous, current);
		fib(&previous, &current, n);						//fib function call by reference
	} else { 
		printf("%d, %d\n", previous, current);
	}
}