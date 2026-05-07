#include <iostream>
#include <string>

using namespace std;

class Board{
	public:	
		int board[2][6];
		int leftBank;
		int rightBank;
		
		void printBoard(){
			cout<<"\n  6   5   4   3   2   1"<<endl;
			cout<<"  ";
			for(int r=0;r<2;r++){
				if(r==1){
					cout<<"\n"<<leftBank<<" ----------------------- "<<rightBank<<endl;
					cout<<"  ";
				}//end if
				
				for(int c=0;c<6;c++){
					cout<<board[r][c]<<" | ";
				}//end for loop
			}//end for loop
			cout<<endl;
			cout<<"  1   2   3   4   5   6"<<endl;
		}//end printBoard()
		
		bool winCondition(){
			for(int r=0;r<2;r++){
				for(int c=0;c<6;c++){
					if(board[r][c]==0){
						return true;
					}//end if
					
					else{
						return false;
					}//end else
				}//end for loop
			}//end for loop
		}//end winCondition()
		
		void movePieces(int userInput, bool playerTurn){
			if(playerTurn==true){
				for(int i=userInput;i<board[1][userInput];i++){
					board[1][i]++;
					//userInput=2
					//i=2;i<4;i++
					//	board[1][2]=5
					
					//i=3;i<4;i++
					//	board[1][3]=5
					
					//i=4;i<4;i++
					//	board[1][4]=5
				}
				//board[1][userInput-1]=0;
			}//end if
			
			else{
				//player2 turn
			}
		}//end movePieces()
};//end Board class

int main(){
	//creates an instance of the Board class
	Board mancala;
	
	//sets board values to 4
	for(int r=0;r<2;r++){
		for(int c=0;c<6;c++){
			mancala.board[r][c]=4;
		}//end for loop
	}//end for loop
	
	//sets the bank values to 0
	mancala.leftBank=0;
	mancala.rightBank=0;
	
	cout<<"Player 1 starts on the left"<<endl;
	cout<<"Player 2 starts on the right"<<endl;
	bool playerOneTurn=true;
	
	while(!mancala.winCondition()){
		//prints the board
		mancala.printBoard();
		
		//runs player1 turn
		if(playerOneTurn){
			int iChoice;
			cout<<"\nEnter the number of hole you would like to play: ";
			cin>>iChoice;
			
			//checks that the user input is valid
			if(iChoice<1 || iChoice>6){
				cout<<"\nInvalid number\n";
				continue;
			}//end if
			
			if(mancala.board[1][iChoice-1]==0){
				cout<<"\nEmpty space\n";
				continue;
			}//end if
			else{
				mancala.movePieces(iChoice,true);
				playerOneTurn=false;
			}//end else
		}//end if
		
		//runs player2 turn
		else{
			playerOneTurn=true;
		}//end else
	}//end while loop
	if(mancala.leftBank>mancala.rightBank){
		cout<<"Player 1 wins"<<endl;
	}//end if
	else if(mancala.leftBank<mancala.rightBank){
		cout<<"Player 2 wins"<<endl;
	}//end else if
	else{
		cout<<"draw"<<endl;
	}//end else
	
	return 0;
}//end main