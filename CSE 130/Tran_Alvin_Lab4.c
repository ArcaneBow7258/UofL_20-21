#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #4
Date: 02/4/2021
Description: A program to simulate a complex calcualtor using predefined functions as options.

*/
//Functions
void addition(){
	double a, b;
	printf("Enter your first number");
	scanf("%lf", &a);
	printf("Enter your second number");
	scanf("%lf", &b);
	
	printf("%lf + %lf = %lf \n", a, b, a+b );

}
void subtraction(){
	double a, b;
	printf("Enter your first number");
	scanf("%lf", &a);
	printf("Enter your second number");
	scanf("%lf", &b);
	
	printf("%lf - %lf = %lf \n", a, b, a-b );
}
void multiply(){
	double a, b;
	printf("Enter your first number");
	scanf("%lf", &a);
	printf("Enter your second number");
	scanf("%lf", &b);
	
	printf("%lf * %lf = %lf \n", a, b, a*b );
}
void divide(){
	double a, b;
	printf("Enter your first number");
	scanf("%lf", &a);
	printf("Enter your second number");
	scanf("%lf", &b);
	
	printf("%lf / %lf = %lf \n", a, b, a/b );
}
void mod(){
	int a, b;
	printf("Enter your first integer");
	scanf("%i", &a);
	printf("Enter your second integer");
	scanf("%i", &b);
	
	printf("%i mod %i = %i \n", a, b, a%b );
}
void prime(){
	int integer1;
	printf("Enter your test integer");
	scanf("%i", &integer1);
	bool primeTest = false;
	int divisor = 1;
	int i = 2;
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
}
void factorial(){
	int a;
	int i = 0;
	printf("Enter your integer");
	scanf("%i", &a);
	int fact = a;
	for (i = a - 1; i > 0; i--){
		fact *= i;
	}
	printf("%i! is %i \n", a, fact);
	
}
void power(){
	double a, b;
	printf("Enter your first number");
	scanf("%lf", &a);
	printf("Enter your second number");
	scanf("%lf", &b);
	
	printf("%lf ^ %lf = %lf \n", a, b, pow(a,b) );
}
void triangle(){
	int a;
	printf("How many triangle numbers do you want?");
	scanf("%i", &a);
	int tri[a];
	int i = 1;
	for( i = 1; i <= a; i++){ //creating and storing values
		tri[i-1] = (i)*(i+1)/2;
	}
	
	for (i = 0; i < (sizeof(tri)/sizeof(tri[0])); i++){
		printf("Triange number %i is %i \n", i+1, tri[i]);
	}
	
}

void main(){
	//Variable set up
	int option = 0;
	int i = 0;
	int integer1 = 0;
	int integer2 = 0;
	int double1 = 0;
	int double2 = 0;
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
7 - Factorial (integers only) \n\
8 - Power \n\
9 - Triangular Numbers \n\
0 - Exit ");
	scanf("%i", &option);
	
	//Proceeds with option user chose.
	switch(option) {
		case 1: // addition
			addition();
			
			break;
		case 2: //subtraction
			subtraction();
			break;
		case 3: //mutliplication
			multiply();
			break;
		case 4: //divison
			divide();
			break;
		case 5: //mod
			mod();
			break;	
		case 6: //prime
			prime();
			break;
		case 7:
			factorial();
			break;
		case 8:
			power();
			break;
		case 9:
			triangle();
			break;
		case 0: //exit case
			printf("Turning off...");
			break;
		default: //skips if none above
			break;
	}
}while(option != 0);
		
		
		
}

