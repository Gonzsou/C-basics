/*
 * C - Basics
 * Check if a number is a narcisistic or armstrong number 
 * (armstrong_number.c) v20190728
 *
 * Gonzsou
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
int main() {
	int n, num, power=0;
	
	/*User enters an integer number*/
	printf("Enter an integer: ");
	scanf("%d", &num);
	n=num;
	
	/*calculates power coeficient to use*/
	int r;
	while (n>0){
		r=n%10;
		power++;
		n=n/10;
	}
	n=num;		//reset n

	int parcial=1;
	int i, sum=0;
	while (n>0){
		r=n%10;								//isolate rightmost digit using the remainder for that purpose
		printf("remainder: %d\n", r);
	
		for(i=0; i<power;i++){			//calculates the partials of power operation on each digit
			parcial =parcial*r;
		}

		sum+=parcial;				//updates the sum of partials		
		
		parcial=1;		//reset partial variable for next iteration
		n=n/10;			//moves to next decimal place 
	}
	
	/*Prints out result*/
	if(num==sum){
		printf("%d é um numero Armstrong!\n", num);
	} else {
		printf("%d nao é um numero Armstrong!\n", num);
	}
}