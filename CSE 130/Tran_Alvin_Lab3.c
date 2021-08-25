#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #3
Date: 01/29/2021
Description: A program to simulate a basic 5 function calculator with the option of checking if a number is prime.

*/

main(){
	//Variable set up
	int option = 0;
	int i = 0;
	int integer1 = 0;
	int integer2 = 0;
	double double1 = 0.0;
	double double2 = 0.0;
	bool primeTest = false;
	int divisor = 1;
	//Starts menu, loops until option is chosen.
	do{
	
	printf("Calculator Menu \n\
1 - Addition  \n\
2 - Subtracton \n\
3 - Multiplication \n\
4 - Division \n\
5 - Modulus (integers only) \n\
6 - Prime Test (integers only) \n\
7 - Exit ");
	scanf("%i", &option);
	
	//Proceeds with option user chose.
	switch(option) {
		case 1: // addition
			printf("Enter your first number");
			scanf("%lf", &double1);
			printf("Enter your second number");
			scanf("%lf", &double2);
			printf("%lf + %lf = %lf \n", double1, double2, double1 + double2);
			break;
		case 2: //subtraction
			printf("Enter your first number");
			scanf("%lf", &double1);
			printf("Enter your second number");
			scanf("%lf", &double2);
			printf("%lf - %lf = %lf \n", double1, double2, double1 - double2);
			break;
		case 3: //mutliplication
			printf("Enter your first number");
			scanf("%lf", &double1);
			printf("Enter your second number");
			scanf("%lf", &double2);
			printf("%lf x %lf = %lf \n", double1, double2, double1 * double2);
			break;
		case 4: //divison
			printf("Enter your first number");
			scanf("%lf", &double1);
			printf("Enter your second number");
			scanf("%lf", &double2);
			printf("%lf / %lf = %lf \n", double1, double2, double1 / double2);
			break;
		case 5: //mod
			printf("Enter your first integer)");
			scanf("%i", &integer1);
			printf("Enter your second integer");
			scanf("%i", &integer2);
			printf("%i mod %i = %i \n", integer1, integer2, integer1 % integer2);
			break;	
		case 6: //prime
			printf("Enter your test integer");
			scanf("%i", &integer1);
			primeTest = false;
			for(i=2; i <= sqrt(integer1); i++){ //checks if a number between 2 and the sqrt of number if it is divisble since multiples are paired except squares)
				if(integer1 % i == 0){
					primeTest = true;
					divisor = i;
					break;
					
				};
			}
			
			if(primeTest){
				printf("%i is not prime \n", integer1);
				printf("%i x %i is %i \n", divisor, integer1/divisor, integer1);
			}
			else{
				printf("%i is prime \n", integer1);
			}
			break;
		case 7: //exit case
			printf("Turning off...");
			break;
		default: //skips if none above
			break;
	}
}while(option != 7);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
