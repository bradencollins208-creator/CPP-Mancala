#include <iostream>
#include <string>

using namespace std;

class Board
{
	public:	
		int board[14];
		//left bank = board[0]
		//right bank = board[7]
		//top row = board[1] - board[6]
		//bottom row = board[8] - board[13]
		
		//prints the board
		void printBoard()
		{
			cout << "\n  6   5   4   3   2   1" << endl;
			cout << "  ";
			for(int i = 1; i < 13; i++)
			{
				cout << board[i] << " | ";
				if(i == 6)
				{
					cout << "\n" << board[0] << " ----------------------- " << board[7] << endl;
					cout << "  ";
				}

				else if(i == 7)
				{
					continue;
				}
			}
			cout << endl;
			cout << "  1   2   3   4   5   6" << endl;
		}
		
		//returns true if either bank has 24 pieces, false otherwise
		bool winCondition()
		{
			return (board[0] >= 24 || board[7] >= 24);
		}
		
		//moves pieces from the selected hole to the next holes
		void movePieces(int userInput, bool playerTurn)
		{
			//
		}
};

int main()
{
	//creates an instance of the Board class
	Board mancala;
	
	//sets board values to 4
	for(int i = 0; i < 14; i++)
	{
		mancala.board[i] = 4;
	}
	
	//sets the bank values to 0
	mancala.board[0] = 0;
	mancala.board[7] = 0;
	
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
			
			else if(mancala.board[iChoice] == 0)
			{
				cout << "\nEmpty space\n";
				continue;
			}

			else
			{
				mancala.movePieces((iChoice), true);
				playerOneTurn = false;
			}
		}
		
		//runs player2 turn
		else
		{
			playerOneTurn = true;
		}
	}

	if(mancala.board[0] > mancala.board[7])
	{
		cout << "Player 1 wins" << endl;
	}

	else if(mancala.board[0] < mancala.board[7])
	{
		cout << "Player 2 wins" << endl;
	}

	else
	{
		cout  <<  "draw"  <<  endl;
	}
	
	return 0;
}