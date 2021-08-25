#include <iostream>

#include <time.h>
#include <stdlib.h>
using namespace std;
//CSE 110-02
//Lab 10
//Alvin Tran
//Date: 3/27/21
//Description: A program to play 3-D Tic-Tac-Toe against a simple random opponent using OOP

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
		int checkWin(){ // Revised to output total. Furthermore no longer else if since we count when board is full
			int wins = 0;
			if( (row1[0] == row1[1] && row1[1] == row1[2] && row1[0] != 0) ) // Horizontal wins
				wins += row1[0];
			if( (row2[0] == row2[1] && row2[1] == row2[2] && row2[0] != 0) )
				wins += row2[0];
			if( (row3[0] == row3[1] && row3[1] == row3[2] && row3[0] != 0) )
				wins += row3[0];
			if( (row1[0] == row2[0] && row2[0] == row3[0] && row1[0] != 0) ) // Vertical Wins
				wins += row1[0];
			if( (row1[1] == row2[1] && row2[1] == row3[1] && row1[1] != 0) )
				wins += row1[1];
			if( (row1[2] == row2[2] && row2[2] == row3[2] && row1[2] != 0) )
				wins += row1[2];	
			if( (row1[0] == row2[1] && row2[1] == row3[2] && row1[0] != 0) ) // Diagonals
				wins += row1[0];
			if( (row1[2] == row2[1] && row2[1] == row3[0] && row1[2] != 0) )
				wins += row1[2];
			return wins;
			}
		bool checkDraw(){ // Utilized to check if board is full, in which the game is over when all 3 boards are full.
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
		
		void displayBoard(string spacer){
			cout << spacer << " " << convert(row1[0]) << " | " << convert(row1[1]) << " | " << convert(row1[2]) << endl;
			cout << spacer << " " << convert(row2[0]) << " | " << convert(row2[1]) << " | " << convert(row2[2]) << endl;
			cout << spacer << " " << convert(row3[0]) << " | " << convert(row3[1]) << " | " << convert(row3[2]) << endl;
		}
};
class verticalBoard: public board{ // Instead of creating a big 3x3x3 board, I reconstructed the boards in a 3-d manner to get wins. uses same 3 row format
		public:
		int checkWin(){ //must override the checkWin to ensure we don't double count horizontals since those are already accounted for in regular 
			int wins;
			if( (row1[0] == row2[0] && row2[0] == row3[0] && row1[0] != 0) ) // Vertical Wins
				wins += row1[0];
			if( (row1[1] == row2[1] && row2[1] == row3[1] && row1[1] != 0) )
				wins += row1[1];
			if( (row1[2] == row2[2] && row2[2] == row3[2] && row1[2] != 0) )
				wins += row1[2];	
			if( (row1[0] == row2[1] && row2[1] == row3[2] && row1[0] != 0) ) // Diagonals
				wins += row1[0];
			if( (row1[2] == row2[1] && row2[1] == row3[0] && row1[2] != 0) )
				wins += row1[2];
			return wins;
		} 
	
};
class sideBoard: public board{ //Close, bottom left is pivot point.
	public:
		int checkWin(){ //Must ovveride checkWin to ensure we don't count horizontals nor verticals.
			int wins;
			if( (row1[0] == row2[1] && row2[1] == row3[2] && row1[0] != 0) ) // Diagonals
				wins += row1[0];
			if( (row1[2] == row2[1] && row2[1] == row3[0] && row1[2] != 0) )
				wins += row1[2];
			return wins;
		}
};// Only missing 4 diagonal fringe cases, which we need to utilzie multiple vertical or horizontal boards to catch, which we'll check later.
//These cases are the 3-d diagonals from corner to corner across.

int main(){
	board top;
	board mid;
	board bot;
	verticalBoard back;
	verticalBoard centerV;
	verticalBoard front;
	sideBoard left;
	sideBoard centerS;
	sideBoard right;
	srand(time(NULL)); // Random seed for deciding player
	bool finished = false; // End Game
	bool validBoard = false; //Makes sure user a valid correct board.
	bool validity = false; // End turn
	int turn = 0;
	string inputStr;
	int inputBoard; // Create a int version for easier processing with opponent AI and rand()
	int vBoard; // Same as above but for vertical boards.
	int sBoard; // Samea s above but for sideways Boards
	int inputPos;
	int totalWins;
	cout << "Positions are as follows" << endl << " 1 | 2 | 3 " << endl << " 4 | 5 | 6 " << endl << " 7 | 8 | 9 " << endl;
	cout << "Top board is top, middle board is mid, and bottom board is bot." << endl << "This is case sensitive" << endl;
	
	if(rand() % 2 == 0){ //Turn 1 
		cout << "You go first, you are X's" << endl << endl;
		turn = 1;
	}
	else{
		cout << "You go second, you are X's" << endl; //Keeping same indicator (X's instead of O's) because it helps make code easier.
		turn = -1;
	}
	
	while(!finished){ // Game loop
		while(!validity){ //Turn isn't over
			while(!validBoard){ // Making sure player is picking a correct board before proceeding
				if(turn == 1) { // Player
					cout << "Please input a board" << endl;
					cin >> inputStr;
					if(inputStr.compare("top") == 0){
						inputBoard = 0;
						validBoard = true;
					}else if(inputStr.compare("mid") == 0){
						inputBoard = 1;
						validBoard = true;
					}else if(inputStr.compare("bot") == 0){
						inputBoard = 2;
						validBoard = true;
					}else{
						cout << "Enter a valid board" << endl;
						validBoard = false;
					}
					
				} else{
					inputBoard = rand() % 3;
					validBoard = true; //Opponent always gets a correct input
				}
			}
			//Position picking
			if(turn == 1){ //Player choice
				cout << "Please input a position" << endl;
				cin >> inputPos;
				
			}else{ //Opponent choice
				inputPos = (rand() % 9) + 1;
			}
			//First we have to check what board we're using
			switch(inputBoard){
				case 0:{
					if(top.checkOpen(inputPos, turn)){ //Check if input spot is open, true if valid input
						if(turn == -1)
							cout << "Opponent's move is " << inputPos << " on board " << inputBoard + 1 << endl;
						top.assignMove(inputPos, turn); //assign board
						
						validity = true;
						
						//VERTICAL BOARD CHECK
						
					}
					else{
						validity = false;
						validBoard = false;
					}
					break;
				}
				case 1:{
					if(mid.checkOpen(inputPos, turn)){ //Check if input spot is open, true if valid input
						if(turn == -1)
							cout << "Opponent's move is " << inputPos << " on board " << inputBoard + 1 << endl;
						mid.assignMove(inputPos, turn); //assign board
						
						validity = true;
					}
					else{
						validity = false;
						validBoard = false;
					}
					break;
				}
				case 2:{
					if(bot.checkOpen(inputPos, turn)){ //Check if input spot is open, true if valid input
						if(turn == -1)
							cout << "Opponent's move is " << inputPos << " on board " << inputBoard + 1 << endl;
						bot.assignMove(inputPos, turn); //assign board
						
						validity = true;
					}
					else{
						validity = false;
						validBoard = false;
					}
					break;
				}
				default: //Defaults to rest if we somehow don't get our expected cased/
					validity = false;
					validBoard = false;
			} //Switch end
			//Since switch processed, we can conclude that the spot was previously open so no need to check position (although for proper coding you should check just in case)
			if(validity){ //Move was processed correctly, safe to move to mimic on vertical board
				inputPos = inputPos - 1; //Make it so mod opperation works out to get good divions of numbers.
				vBoard = inputPos / 3; //Integer math allows us to ignore the decimal
				sBoard = inputPos % 3;
				//Vertical: Inputs 1-3 gets us back. 4-6 gets center, 7-9 gets front
				//Sideways: Inputs 1, 4, 7 gives left, 2, 5, 8 is center, 3, 6, 9 is right
				//Top board are values 1-3, Middle is 3-6, Bottom is 7-9
				switch(vBoard){
					case 0: // Back
						back.assignMove( (inputPos + 1) + inputBoard * 3, turn);
						break;
					case 1: // Center
						centerV.assignMove( (inputPos - 2) + inputBoard * 3, turn);
						break;
					case 2: // Front
						front.assignMove( (inputPos - 5) + inputBoard * 3, turn);
						break;
				}
				switch(sBoard){
					case 0: // Left
						left.assignMove( 3 - (inputPos/3) + inputBoard * 3, turn);
						break; 
					case 1: //Center
						centerS.assignMove( 3 - (inputPos/3) + inputBoard * 3, turn);
						break;
					case 2: // Right
						right.assignMove( 3 - (inputPos/3) + inputBoard * 3, turn);
						break;
				}
				turn = (turn == 1)? -1 : 1; //Switch trun after we are done processing a single turn.
			}
			
		} //End of "turn loop"
		//Displaying all boards
		top.displayBoard(" "); 
		cout <<	endl;
		mid.displayBoard("   ");
		cout << endl;
		bot.displayBoard("     ");
		cout << endl;
		//Tallying wins thus far
		//First, tally flat "2-D" possible wins
		totalWins = top.checkWin() + mid.checkWin() + bot.checkWin() + back.checkWin() + centerV.checkWin() + front.checkWin() + left.checkWin() + centerS.checkWin() + right.checkWin(); 
		//Checking 3-d diagonals
		if(top.row1[0] == mid.row2[1] && mid.row2[1] == bot.row3[2])
			totalWins += mid.row2[1];
		if(top.row1[2] == mid.row2[1] && mid.row2[1] == bot.row3[1])
			totalWins += mid.row2[1];
		if(top.row3[0] == mid.row2[1] && mid.row2[1] == bot.row1[2])
			totalWins += mid.row2[1];
		if(top.row3[2] == mid.row2[1] && mid.row2[1] == bot.row1[0])
			totalWins += mid.row2[1];
		
		//Checking if everyhting is full, thus we end game
		if( (top.checkDraw() && mid.checkDraw()) && bot.checkDraw()){ // Check draw is a misnomer here, we jsut check if all boards are full to end the game
			finished = true;
			
			if(totalWins > 0){
				cout << "Player wins!";
			}
			else if(totalWins < 0){
				cout << "Opponent wins!";
			}
			else{ //Case where totalWins = 0
				cout << "It is a draw!";
			}
		}
		else {
			finished = false;
			validBoard = false;
			validity = false;
		}
	}
	
}
