/*
 * C - Basics
 * Creates array with elements entered by user, 
 * then present array as entered, in ascending order and in descending order 
 * (ascend_descend_array.c) v20190727
 *
 * Gonzsou
 *
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 
 int main(){

	/*Declare, initialize array of 'n' elements entered by user*/
	 int i, n;
	 printf("How many numbers: ");
	 scanf("%d", &n);
 	 int array[n];
	for (i=0; i<n; i++){
		printf("Please enter value %d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	/*print array as is*/
	printf("Array as entered: [");
	for (i = 0; i < n; i++){
		if (i<n-1){
			printf("%d, ", array[i]);
		} else {
			printf("%d] \n", array[i]);
		}
	}
	
	/*reorganize array in ascending order*/
	int j, temp;
	for (i=0; i<n; i++){
		for (j=0; j<i;j++){
			if(array[i]<array[j]){
				temp = array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	
	/*print array in ascending order*/
	printf("Array in ascending order: [");
	for (i = 0; i < n; i++){
		if (i<n-1){
			printf("%d, ", array[i]);
		} else {
			printf("%d] \n", array[i]);
		}
	}

	
	/*reorganize array in descending order*/
	for (i=0; i<n; i++){
		for (j=0; j<i;j++){
			if(array[i]>array[j]){
				temp = array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	
	/*print array in descending order*/
	printf("Array in descending order: [");
	for (i = 0; i < n; i++){
		if (i<n-1){
			printf("%d, ", array[i]);
		} else {
			printf("%d] \n", array[i]);
		}
	}
	
	return(0);
 }