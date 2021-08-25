#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #6
Date: 02/11/2021
Description: A program that records names and phone numbers of user-inputted people.

*/


typedef struct{
	char first[30];
	char last[30];
	char number[10];
	
	
}bookEntry;

int main(){
	int choice = 4;
	int maxEntry = 5;
	bool full = false;
	char input[30];
	char input2[30];
	int i = 0;
	int j = 0;
	int nextEntry = 0;
	bookEntry *phoneBook =  (bookEntry *) calloc(maxEntry, sizeof(bookEntry) );
 	bookEntry *temp;
	do{
		
		printf("Phone Book Application \n	1 - Add Friend\n	2 - Remove Friend\n	3 - Show Phone Book\n	4 - Exit\n%");
		scanf("%i",&choice);
		
		switch(choice){
			case 1: //Add Entry
				full = true;
				for(i = 0; i < maxEntry; i++){ //Looking for next empty spot
					if(strlen(phoneBook[i].first ) < 1 ){ //We found an empty spot
						printf("hi");
						nextEntry = i;
						full = false;
						break;
					}
			}
				if(full){ //If we didn't find a new nextEntry, so we'd be full and need to expand our array.
						printf("hey");
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
			case 4: //Exit
				printf("Exiting...");
				break;
			default:
				break;
		}
	}while(choice != 4);
	free(phoneBook);
	return 0;
}
