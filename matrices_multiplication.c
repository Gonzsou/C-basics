/*
 * C - Basics
 * Creates two multi dimension arrays with elements entered by user, 
 * perform the multiplication the two arrays and store the results into new matrix
 * (matrices_multiplication.c) v20190727
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main() {
	 
	int m, n, i, j, k;

	printf("Enter the size of the arrays (up to 5x5)");
	do {
		printf("\nNumber of rows: ");
		scanf("%d", &m);
	} while (m>5||m<1);
	do {
		printf("Number of columns: ");
		scanf("%d", &n);
	} while (n>5||n<1);
 	
	int a[m][n], b[m][n], c[m][n];			//initializes all three arrays with same size
	
	/*Enter the values for the elements of the arrays a and b*/
	for (i=0; i<m; i++){
		for(j=0; j<n;j++){
			printf("Enter element a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	for (i=0; i<m; i++){
		for(j=0; j<n;j++){
			printf("Enter element b[%d][%d]: ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	 
	/*Perform the multiplication of two arrays */
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			c[i][j] = 0;
			for (k=0; k<m; k++){
				c[i][j] = c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}

	/*Print array a*/
	printf("Array A:\n");
	for (i=0; i<m; i++){
		 for(j=0; j<n; j++){
			 printf("%3d", a[i][j]);
		 }
		 printf("\n");
	}	
	printf("\n\n");

	/*Print array b*/
	printf("Array B:\n");
	for (i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%3d", b[i][j]);
		}
		printf("\n");
	}	
	printf("\n\n");

	 /*Print array c*/
 	printf("Result of AxB:\n");
	for (i=0; i<m; i++){
		for(j=0; j<m; j++){
			printf("%3d ", c[i][j]);
		}	 
		printf("\n");
	}
 }