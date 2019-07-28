/*
 * C - Basics
 * Factorial of a given number using recursion 
 * (factorial_recursive.c) v20190728
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
int factorial(int n){
	int fnum;
	
	if (n==1){		
		return 1;
	} else {
		fnum = n * factorial(n-1);	//each parcel fnum gets chained up to next factorial(n-1), until factoria(n-1)=factorial(1) is reached
	}
	return fnum;
}
 
int main() {
	 
	 /*requests number from user*/
	 int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	printf("Factorial de %d: %d\n", n, factorial(n));			//call recursive function and print value returned, arguments passed by value
}