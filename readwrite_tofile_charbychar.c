/*
 * C - Basics
 * 
 * (strings.c) v20190728
 *
 * Gonzsou
 *
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 
 
void foo(int *parametro, int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d", parametro[i]++);		//prints elements of array passed to function and increments each of its elements right afterwards
	}
} 

int main(){

	int i, array[] = {3,5,8,6,8};				
	int n = sizeof(array)/sizeof(int);	//calculates number of elements of initialized integer array 

	/*Values before function call*/
	printf("Array before function call:\t");
	foo(array, n);
	printf("\n");

	/*Values after function call*/
	printf("Array after function call:\t");
	for (i=0;i<n;i++){
			printf("%d", array[i]);
	}
	printf("\n");

	return (0);
} 