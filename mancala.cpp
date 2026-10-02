#include <iostream>
#include <string>

using namespace std;

class Board
{
	public:	
		int board[2][6];
		int leftBank;
		int rightBank;
		
		void printBoard()
		{
			cout << "\n  6   5   4   3   2   1" << endl;
			cout << "  ";
			for(int r = 0; r < 2; r++)
			{
				if(r == 1)
				{
					cout << "\n" << leftBank << " ----------------------- " << rightBank << endl;
					cout << "  ";
				}
				
				for(int c=0;c<6;c++)
				{
					cout << board[r][c] << " | ";
				}
			}
			cout << endl;
			cout << "  1   2   3   4   5   6" << endl;
		}
		
		bool winCondition()
		{
			for(int r = 0; r < 2; r++)
			{
				for(int c = 0; c < 6; c++)
				{
					if(board[r][c] == 0)
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
			}
		}
		
		void movePieces(int userInput, bool playerTurn)
		{
			if(playerTurn == true)
			{
				for(int i = 0; i < board[1][userInput]; i++)
				{
					if(i+userInput % 5 < 6)
					{
						board[1][i+userInput-1]++;
					}
					
					else if(i+userInput % 6 == 0)
					{
						rightBank++;
					}
					
					else if(i+userInput == 0){
						//
					}
				}
				board[1][userInput-1] = 0;
			}
		void movePieces(int userInput, bool playerTurn){
			if(playerTurn==true){
				for(int i=0;i<board[1][userInput-1];i++){
					if(i+userInput%5<6){
						board[1][i+userInput-1]++;
					}
					else if(i+userInput%6==0){
						rightBank++;
					}
					else if(i+userInput==0){
						//
					}
				}//end for loop
				board[1][userInput-1]=0;
			}//end if
			
			else
			{
				//player2 turn
			}
		}
};

int main(){
	//creates an instance of the Board class
	Board mancala;
	
	//sets board values to 4
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 6; c++)
		{
			mancala.board[r][c] = 4;
		}
	}
	
	//sets the bank values to 0
	mancala.leftBank = 0;
	mancala.rightBank = 0;
	
	cout << "Player 1 starts on the left" << endl;
	cout << "Player 2 starts on the right" << endl;
	bool playerOneTurn = true;
	
	while(!mancala.winCondition())
	{
		//prints the board
		mancala.printBoard();
		
		//runs player1 turn
		if(playerOneTurn)
		{
			int iChoice;
			cout << "\nEnter the number of hole you would like to play: ";
			cin >> iChoice;
			
			//checks that the user input is valid
			if(iChoice < 1 || iChoice > 6)
			{
				cout << "\nInvalid number\n";
				continue;
			}
			
			if(mancala.board[1][iChoice-1] == 0)
			{
				cout << "\nEmpty space\n";
				continue;
			}

			else
			{
				mancala.movePieces(iChoice-1, true);
				playerOneTurn = false;
			}
		}
		
		//runs player2 turn
		else
		{
			playerOneTurn = true;
		}
	}

	if(mancala.leftBank > mancala.rightBank)
	{
		cout << "Player 1 wins" << endl;
	}

	else if(mancala.leftBank < mancala.rightBank)
	{
		cout << "Player 2 wins" << endl;
	}

	else
	{
		cout  <<  "draw"  <<  endl;
	}
	
	return 0;
}