/*
 * C - Basics
 * Creates multi dimension array with elements entered by user, 
 * then present the array
 * (multi_dimension_array.c) v20190727
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main() {
	 
	 int m, n, i, j;
	 int a[5][5];		//Initialize a 5x5 array

	printf("Enter the size of the array (up to 5x5)");
	do {
		printf("\nNumber of rows: ");
		scanf("%d", &m);
	} while (m>5||m<1);
	do {
		printf("\nNumber of columns: ");
		scanf("%d", &n);
	} while (n>5||n<1);
	 
	 /*Enter elements in the array*/
	 for (i=0; i<m; i++){
		 for(j=0; j<n;j++){
			 printf("Enter element a[%d][%d]: ", i, j);
			 scanf("%d", &a[i][j]);
		 }
	 }

	/*Print the multidimentional array*/
	 for (i=0; i<m; i++){
		 for(j=0; j<n; j++){
			 printf("%3d", a[i][j]);
		 }
		 printf("\n");
	 }
 }