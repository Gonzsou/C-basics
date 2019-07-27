/*
 * C - Basics
 * Creates a 2D array with elements entered by user, print the array, and print the transposed array 
 * then present the array
 * (transpose.c) v20190728
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main() {
	 
	 int m, n, i, j;

	printf("Enter the size of the array (up to 6x6)");
	do {												//controls the value entered by user for number of rows
		printf("\nNumber of rows: ");
		scanf("%d", &m);
	} while (m>6||m<1);
	do {												//controls the value entered by user for number of columns
		printf("Number of columns: ");
		scanf("%d", &n);
	} while (n>6||n<1);
	
	int a[m][n];	//Initialize the array with the number of rows and columns entered by user
	 
	 /*Enter elements in the array*/
	 for (i=0; i<m; i++){
		 for(j=0; j<n;j++){
			 printf("Enter element a[%d][%d]: ", i, j);
			 scanf("%d", &a[i][j]);
		 }
	 }

	/*Print entered matrix*/
	 for (i=0; i<m; i++){
		 for(j=0; j<n; j++){
			 printf("%3d", a[i][j]);
		 }
		 printf("\n");
	 }

	printf("\n");

	/*Print the transposed matrix*/
	for (i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%3d", a[j][i]);
		}
		printf("\n");
	}
}