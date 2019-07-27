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
	 int a,b;
	 char op;
	 int result;
	 
	 printf("First number (up to 9999999): ");
	 scanf("%6d", &a);
	 getchar();
	 printf("Enter operator +, -, *, /, %%):  ");
	 scanf("%c", &op);	 
	 getchar();
	 printf("Second number (up to 9999999): ");
	 scanf("%6d", &b);
 	 getchar();

	 
	 switch (op){
		 default:
			printf("Invalid Operator");
			break;
		
		case '+':
			result = a+b;
			printf("Result: %d\n", result);
			break;
			
		case '-':
			result = a-b;
			printf("Result: %d\n", result);
			break;
			
		case '*':
			result = a*b;
			printf("Result: %d\n", result);			
			break;
			
		case '/':
			result = a/b;
			printf("Result: %f\n", (float)result);			
			break;
			
		case '%':
			result = a%b;
			printf("Result: %d\n", result);
			break;		 
	 }
 }