#include <iostream>
#include <string>

using namespace std;

class Board{
	public:	
		int board[2][6];
		int leftBank;
		int rightBank;
		
		void printBoard(){
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
		}//end printBoard()
		
		bool winCondition(){
			//
		}//end winCondition()
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
	
	mancala.leftBank=0;
	mancala.rightBank=0;
	
	//prints the board
	mancala.printBoard();
	
	return 0;
}//end main