#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #5
Date: 02/11/2021
Description: A program that produces a short story based off the inputs of the user. 
The short story is randomly produced. and utlizes pointers and arrays for strings.

*/
//Functions



int main(){
	srand(time(0)); //Seeding Random
	
	//Branches
	char *prof[4] = {"baker", "janitor", "astronaut", "bartender", };
	char *quest[4] = {"... buy some groceries", "hike a mountain" , "sail the seas", "brave the desert"};;
	char *rival[6] = {"Gary", "Joe", "Arby", "Mary", "Tina", "Candice"};
	char *cloth[4] = {"shirt", "cape", "hat", "scarf"};
	char *end[4] = {"move on to a better hobby", "work together for years to come", "say syke and thus their rivalry continued", "went their seperate ways"};
	//User Input variables
	char name[20];
	int age;
	char food[20];
	char color[20];
	char hobby[50];
	
	//Inputs
	printf("Input your name ");
	scanf("%s", &name);
	printf("Input your age ");
	scanf("%i", &age);
	printf("Input your favorite food ");
	scanf("%s", &food);
	printf("Input your least favorite color ");
	scanf("%s", &color);
	printf("Finally, input your favorite hobby ");
	scanf("%s", &hobby);
	
	char *selRival = rival[rand()%5]; //Preselected random branches that will be reused.
	
	printf("\nOnce upon a time, existed a person named %s. \n\n", name);
	system("pause");
	printf("Some say %s the best at %s, if not their rival, %s. \n\n", name, hobby, selRival);
	system("pause");
	printf("To improve themselves, %s left their as a %s to go on a quest, at the prime age of %i.\n\n", name, prof[rand()%3], age);
	system("pause");
	printf("%s embarked on their quest to %s, but to their suprise, they found %s wearing an ugly %s-colored %s doing the same thing.\n\n", name, quest[rand()%3], selRival, color, cloth[rand()%3] );
	system("pause");
	printf("Despite the encounter, %s pushed on. So long as they had their surplus of %s, they were impervious.\n\n", name, food);
	system("pause");
	printf("In the end, %s and %s made a few amends to one another. After years of competing, they decided to give up on being the best at %s and competing against each other.\n\n", name, selRival, hobby);
	system("pause");
	printf("Instead, they shook hands, and chose to %s.", end[rand()%3]);
	

}
