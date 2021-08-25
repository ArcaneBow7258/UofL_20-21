#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
//CSE 110-02
//Lab 9
//Alvin Tran
//Date: 3/20/21
//Description: A simple program to play Tic-Tac-Toe against a simple random opponent using OOP
//Hindsight after making all of this, I should have used a 3-d array and it would have been easier for the board.

class board
{
	//
	public:
		int row1[3] = {0, 0, 0};
		int row2[3] = {0, 0, 0};
		int row3[3] = {0, 0, 0};
		
		//For all purposes, -1 is opponent, 0 is empty, and 1 is player
		//X / O assignment
		bool checkOpen(int position, int turn){ //Returns false if spot is taken
			position = position - 1; //Make it so mod opperation works out to get good divions of numbers.
			int row = position / 3; //Integer math allows us to ignore the decimal
			position = position % 3; //Gets exactly column
			
			switch(row){
				case 0:
					if (row1[position] == 0){
						return true;
					}
					else{
						if(turn == 1) // Don't want to output error if opponent turn (since random placement)
							cout << "That spot isn't empty!" << endl;
						return false;
					}
					break;
				case 1:
					if (row2[position] == 0){
						return true;
					}
					else{
						if(turn == 1) // Don't want to output error if opponent turn (since random placement)
							cout << "That spot isn't empty!" << endl;
						return false;
					}
					return true;
					break;
				case 2:
					if (row3[position] == 0){
						return true;
					}
					else{
						if(turn == 1) // Don't want to output error if opponent turn (since random placement)
							cout << "That spot isn't empty!" << endl;
						return false;
					}
					return true;
					break;
				default:
					cout << "Enter a valid input" << endl;
					return false;
					break;
			}
		}
		bool assignMove(int position, int player){ //Return false if an illegal move was made.
			position = position - 1; //Make it so mod opperation works out to get good divions of numbers.
			int row = position / 3; //Integer math allows us to ignore the decimal
			position = position % 3; //Gets exactly column
			
			switch(row){
				case 0:
					row1[position] = player;
					return true;
					break;
				case 1:
					row2[position] = player;
					return true;
					break;
				case 2:
					row3[position] = player;
					return true;
					break;
				default:
					cout << "Enter a valid position" << endl;
					return false;
					break;
			}		
		}
		int checkWin(){
			if( (row1[0] == row1[1] && row1[1] == row1[2] && row1[0] != 0) ) // Horizontal wins
				return row1[0];
			else if( (row2[0] == row2[1] && row2[1] == row2[2] && row2[0] != 0) )
				return row2[0];
			else if( (row3[0] == row3[1] && row3[1] == row3[2] && row3[0] != 0) )
				return row3[0];
			else if( (row1[0] == row2[0] && row2[0] == row3[0] && row1[0] != 0) ) // Vertical Wins
				return row1[0];
			else if( (row1[1] == row2[1] && row2[1] == row3[1] && row1[1] != 0) )
				return row1[1];
			else if( (row1[2] == row2[2] && row2[2] == row3[2] && row1[2] != 0) )
				return row1[2];	
			else if( (row1[0] == row2[1] && row2[1] == row3[2] && row1[0] != 0) ) // Diagonals
				return row1[0];
			else if( (row1[2] == row2[1] && row2[1] == row3[0] && row1[2] != 0) )
				return row1[2];
			else // Not yet done
				return 0;
			}
		bool checkDraw(){ // Assumes checkWin() is called before hand, thus no win detecetd
			int row = 0;
			int col = 0;
			for (int i = 0; i < 9; i++){
				row = i / 3;
				col = i % 3;
				switch(row){
					case 0:
						if(row1[col] == 0) // If any spot isn't filled, win is still possible
							return false;
					case 1:
						if(row2[col] == 0)
							return false;
					case 2:
						if(row3[col] == 0)
							return false;
				}
			}
			return true; //Above cases fail, thus every spot is full and checkWin still reports false
		}
		string convert(int value){
			if(value == 1)
				return "X";
			else if (value == -1)
				return "O";
			else
				return " ";
		}
		
		void displayBoard(){
			cout << " " << convert(row1[0]) << " | " << convert(row1[1]) << " | " << convert(row1[2]) << endl;
			cout << " " << convert(row2[0]) << " | " << convert(row2[1]) << " | " << convert(row2[2]) << endl;
			cout << " " << convert(row3[0]) << " | " << convert(row3[1]) << " | " << convert(row3[2]) << endl;
		}
		
};

int main(){
	board b;
	srand(time(NULL)); // Random seed for deciding player
	bool finished = false; // End Game
	bool validity = false; // End turn
	int turn = 0;
	int input;
	cout << "Positions are as follows" << endl << " 1 | 2 | 3 " << endl << " 4 | 5 | 6 " << endl << " 7 | 8 | 9 " << endl;
	
	if(rand() % 2 == 0){ //Turn 1 
		cout << "You go first, you are X's" << endl;
		turn = 1;
	}
	else{
		cout << "You go second, you are X's" << endl; //Keeping same indicator (X's instead of O's) because it helps make code easier.
		turn = -1;
	}
	
	while(!finished){
		while(!validity){ //Turn isn't over
			if(turn == 1){ //Player
				cout << "Please input a position" << endl;
				cin >> input;
				
			}else{ //Opponent
				input = (rand() % 9) + 1;
			}
			if(b.checkOpen(input, turn)){ //Check if input spot is open, true if valid input
				cout << "Opponent's move is " << input << endl;
				b.assignMove(input, turn); //assign board
				turn = (turn == 1)? -1 : 1; 
				validity = true;
			}
			else{
				validity = false;
			}
		}
		b.displayBoard();
		if(b.checkWin() != 0){
			finished = true;
			if(b.checkWin() == 1)
				cout << endl << "You win!";
			else
				cout << endl << "You lose!";
			
		}
		else if(b.checkDraw()){
			finished = true;
			cout << "It's a draw!";
		}
		else {
			finished = false;
			validity = false;
		}
	}
	
}
