#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #7
Date: 03/4/2021
Description: A program that records names and phone numbers of user-inputted people.
Updated to sort alphabetically, access to seach function, random selection, and clear phonebook.
*/


typedef struct{
	char first[30];
	char last[30];
	char number[10];
	
	
}bookEntry;

int main(){
	srand(time(0));
	int random = 0;
	int choice = 0;
	int maxEntry = 5;
	bool full = false;
	bool sorted = false;
	
	int numInput = 0;
	char input[30];
	char input2[30];
	int i = 0;
	int j = 0;
	int nextEntry = 0;
	bookEntry *phoneBook =  (bookEntry *) calloc(maxEntry, sizeof(bookEntry) );
 	bookEntry *temp;
 	bookEntry entryTemp;

	do{
		//int sizeEntry = sizeof(bookEntry);
		printf("Phone Book Application \n	1 - Add Friend\n	2 - Remove Friend\n	3 - Show Phone Book\n	4 - Sort\n	5 - Search by name\n	6 - Random Call\n	7 - Clear all\n	8 - Exit\n%");
		printf("Enter an option number\n");
		scanf("%i",&choice);

		switch(choice){	
			case 1: //Add Entry
				full = true;
				for(i = 0; i < maxEntry; i++){ //Looking for next empty spot
					if(strlen(phoneBook[i].first ) < 1 ){ //We found an empty spot
						nextEntry = i;
						full = false;
						break;
					}
			}
				if(full){ //If we didn't find a new nextEntry, so we'd be full and need to expand our array.
					
						nextEntry = maxEntry;
						maxEntry = maxEntry + 1; //Poorly named, but maxEntry is actually length of phonebook.
						temp = (bookEntry *) realloc(phoneBook, maxEntry * sizeof(bookEntry) );
						if(phoneBook == NULL){ //Out of Memeory
							printf("Out of memory");
							break;	
						} 
						else{ // Success
							
							phoneBook = temp;
						
							
						}
						
				}
			
					
				printf("Input first name\n");
				scanf("%s",&input);
				strcpy(phoneBook[nextEntry].first, input);
				
				printf("Input last name\n");
				scanf("%s",&input);
				strcpy(phoneBook[nextEntry].last , input);
				
				printf("Input phone number\n");
				scanf("%s",&input);
				strcpy(phoneBook[nextEntry].number, input);
				
				break;
			case 2: //Remove Entry, oldest entry out first.
				printf("Input first name for delete search\n");
				scanf("%s",&input);

				
				printf("Input last name for delete search\n");
				scanf("%s",&input2);
				
				for(i = 0; i < maxEntry; i++){
					if( (strcmp(phoneBook[i].first, input) == 0) && (strcmp(phoneBook[i].last, input2) == 0) ){ //serah succeeds
						
						strcpy(phoneBook[i].first, "");
						strcpy(phoneBook[i].last, "");
						strcpy(phoneBook[i].number, "");
						break;
					}
				}
		

				 break;
			case 3: //Show Entries
				for(j = 0; j < maxEntry; j++){ //Using maxEntry since we know how many entires there are and ther will be
					if(strlen(phoneBook[j].first) > 0 ){
						printf("%s %s %s\n", phoneBook[j].first, phoneBook[j].last, phoneBook[j].number);	
					}
				}
				break;
			case 4: //Sort
				printf("Input 1 to sort by first and 2 by last name (A-Z)\n");
				scanf("%i",&numInput);
				sorted = false;
				while(!sorted){
					i = 0;
					sorted = true;
					
					if(numInput == 1){
						
						for(i = 0; i < maxEntry - 1; i++){ //max entry -1 since we're doing a simple but inefficient search by comparing to immediate next value
							if(strcmp(phoneBook[i].first, phoneBook[i+1].first) > 0 )
							{
								entryTemp = phoneBook[i];
								phoneBook[i] = phoneBook[i+1];
								phoneBook[i+1] = entryTemp;
								sorted = false;
							}
						}
					
						
					}
					if(numInput == 2){
						for(i = 0; i < maxEntry - 1; i++){ //max entry -1 since we're doing a simple but inefficient search by comparing to immediate next value
							if(strcmp(phoneBook[i].last, phoneBook[i+1].last) > 0 )
							{
								
								entryTemp = phoneBook[i];
								phoneBook[i] = phoneBook[i+1];
								phoneBook[i+1] = entryTemp;
								sorted = false;
							}
						}
					
						
					}
				}
				
				break;
			case 5: //Search. Same code for delete but instead prints found entry
				printf("Input first name for search\n");
				scanf("%s",&input);

				
				printf("Input last name for search\n");
				scanf("%s",&input2);
				
				for(i = 0; i < maxEntry; i++){
					if( (strcmp(phoneBook[i].first, input) == 0) && (strcmp(phoneBook[i].last, input2) == 0) ){ //serah succeeds
						
						printf("%s %s's number is %s\n", phoneBook[i].first, phoneBook[i].last, phoneBook[i].number);
	
						break;
					}
				}
		
				break;
			case 6: //SRandom
			//Bug in which sizeof() is returning 0 for bookEntry AND phoneBook when used here, so counting the hard way before doing random, also the hard way.
				j = 0;
				
				for(i = 0; i < maxEntry; i++){
					if(strlen(phoneBook[i].first) > 0 ){
						j = j + 1; //Counting number of entries
					}
				}
				random = rand()%j + 1; //We are using random to get the 1st/2nd/etc known address
				
				j = 0;
				for(i = 0; i < maxEntry; i++){
					if(strlen(phoneBook[i].first) > 0 ){
						j = j + 1; //Recounting, and choosing the xth number where x is represented by random
						if(j == random){
							random = i; //Reassigning relative random address (ie out of the filling indexes) to the actual address (the index of that address in the array)
							break;
						}
					}
				}
				
				printf("Calling %s %s at %s...\n", phoneBook[random].first, phoneBook[random].last, phoneBook[random].number);
				break;
				
				
			case 7: //Clear
			printf("Are you sure you wish to clear ALL entries? Type \"Yes\" if so.\n");
				scanf("%s",&input);
				if(strcmp(input, "Yes") == 0){
					free(phoneBook);
					phoneBook =  (bookEntry *) calloc(maxEntry, sizeof(bookEntry));
				
				}
				
				break;
			case 8: //Exit
				printf("Exiting...");
				break;
			default:
				break;
		}
	}while(choice != 8);
	free(phoneBook);
	return 0;
}
