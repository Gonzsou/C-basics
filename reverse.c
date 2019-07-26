/*
 * C - Basics
 * Reverse order
 * (reverse.c) v20190726
 *
 * Gonzsou
 *
 */
 
 #include<stdio.h>
 #include<stdlib.h>
 
 int main () {
	 int i, n, digit;
	 printf("Please insert a 3 digit number: ");
	 scanf("%3d", &n);		// %3d format only scans first 3 digits introduced, ignoring all extra characters which might have been introduced 
	 
	 while (n>0){
		digit = n%10;				//isolates last digit using modulo 10, last digit becomes the remainder, then assigns remainder to an integer type variable
		switch(digit){
			 case 0:	printf("ZERO\n");	break;
			 case 1:	printf("ONE\n");	break;
			 case 2:	printf("TWO\n");	break;
			 case 3:	printf("THREE\n");break;
			 case 4:	printf("FOUR\n");	break;
			 case 5:	printf("FIVE\n");	break;
			 case 6:	printf("SIX\n");		break;
			 case 7:	printf("SEVEN\n");break;
			 case 8:	printf("EIGHT\n");	break;
			 case 9:	printf("NINE\n");	break;
			 default:	printf("Invalid input\n");	break;
		}
		n=n/10;		// divides by 10 to move to remove the last digit, since we're dealing with integers 
	 }	
 }
