#include "ChessGame.h"
int main(){
	int x = 0;
	int gameover=0;
	int y = 21;
	printf("Would you like PvP (0) or PvC (1)?\n");
	scanf("%d",&y);
	while(y > 1 || y < 0){
		printf("Not a valid game mode. Enter 0 for PvP and 1 for PvC\n");
		scanf("%d",&y);
	}
	x = Menu();
	gameover = Game(x,y);
	return 1;
	
}
int Game(int Player, int mode){
	int gover = 0;
	char from_letter, to_letter, space;
	ChessBoard* cb = createChessBoard();
  ChessBoard* cbPre = createChessBoard();
	putChessAtGameStart(cb);
	// White vs Black PVP
	if(Player == 0 && mode == 0){
		//displayBoard(cb);
		while(gover == 0){
     			displayBoard(cb);
     			/* FIXME */
     			// This is where I put the copyChessBoard
			cbPre = copyChessBoard(cb); //save the chessboard
			WhiteTurn(cb, Player);
			displayBoard(cb);                   
			IfUndoW(cbPre, cb, Player);                
			cbPre = copyChessBoard(cb); //save the chessboard
			BlackTurn(cb, Player);
			displayBoard(cb);
			IfUndoB(cbPre, cb, Player);                  
 			//gover = 1 should be replaced with the check function;
		}
	} 
	//Black vs White PVP
	else if(Player == 1 && mode == 0){
		  rdisplayBoard(cb);
		while(gover == 0){
      			cbPre = copyChessBoard(cb); //save the chessboard
      			WhiteTurn(cb, Player);
			rdisplayBoard(cb);
      IfUndoWr(cbPre, cb, Player);
      cbPre = copyChessBoard(cb); //save the chessboard
			BlackTurn(cb, Player);
			rdisplayBoard(cb);    
      IfUndoBr(cbPre, cb, Player);          
			// condition for game over
		}
	}
	//PVC
	else if(mode == 1){
		if(Player == 0){
			displayBoard(cb);
			while(gover == 0){
//      ChessBoard* cbPre = cb; //save the chessboard
				WhiteTurn(cb, Player);
//    IfUndoW(cbPre, cb, Player);                
//			  cbPre = cb;
				displayBoard(cb);
				bestMove(cb,Player);
				displayBoard(cb);
			}
		}
		else{
			rdisplayBoard(cb);
			while(gover == 0){
				bestMove(cb,Player);
				rdisplayBoard(cb);
//        ChessBoard* cbPre = cb; //save the chessboard
				BlackTurn(cb, Player);
				rdisplayBoard(cb);
//        IfUndoBr(cbPre, cb, Player);
			}
		}
	}
	
	deleteChessBoard(cb);
  deleteChessBoard(cbPre);
	return 1;
}

int WhiteTurn(ChessBoard* cb, int player){
	char command[6];
	char command2[6];
	int valid = 0;
	int from_x, to_x;
	char from_y, to_y;
	while(valid != 8){
	        printf("Red: ");
        	scanf("%s %s",command,command2);
       		sscanf(command, "%c%d", &from_y, &from_x);
       		sscanf(command2, "%c%d", &to_y, &to_x);
		//Invalid moves
                if(from_x>8 || from_x < 1 || to_x<0 || to_x>8 || from_y<97 || from_y>104 || to_y<97 || to_y>104){
                        while(from_x>8 || from_x < 1 || to_x<0 || to_x>8 || from_y<97 || from_y>104 || to_y<97 || to_y>104){
                                printf("Invalid move selection try again: ");
                                scanf("%s %s",command,command2);
                                sscanf(command, "%c%d", &from_y, &from_x);
                                sscanf(command2, "%c%d", &to_y, &to_x);
                         }
                }
		//switching black coordinates into board coordinates
		if(player == 1){
			from_y = charBlackLogic(from_y);
			from_x = numBlackLogic(from_x);
			to_y = charBlackLogic(to_y);
			to_x = numBlackLogic(to_x);
		}
		if(getPosition_logic(cb, from_y, from_x) -> color !=WHITE){
			printf("Wrong color please go again\n");
			continue;
		}
		if(check_valid_move_logic(cb, from_y, from_x, to_y, to_x) != 1){
			printf("Invalid move please try again\n");
			continue;
		}
		//moving the piece
		else{
			if(getPosition_logic(cb, from_y, from_x) -> type == PAWN){
				movement(cb, from_x, to_x, from_y, to_y);
				PawnPromotion(cb, to_y, to_x);
			}
			else{
                		movement(cb, from_x, to_x, from_y, to_y);
			}
			valid = 8;
		}
        }
	
        return 1;
}
int BlackTurn(ChessBoard* cb, int player){
        char command[6];
        char command2[6];
        int valid = 0;
        int from_x, to_x;
        char from_y, to_y;
        while(valid != 8){
                printf("Magenta: ");
                scanf("%s %s",command,command2);
                sscanf(command, "%c%d", &from_y, &from_x);
                sscanf(command2, "%c%d", &to_y, &to_x);
                if(from_x>8 || from_x < 1 || to_x<0 || to_x>8 || from_y<97 || from_y>104 || to_y<97 || to_y>104){
                        while(from_x>8 || from_x < 1 || to_x<0 || to_x>8 || from_y<97 || from_y>104 || to_y<97 || to_y>104){
                                printf("Invalid move selection try again: ");
                                scanf("%s %s",command,command2);
                                sscanf(command, "%c%d", &from_y, &from_x);
                                sscanf(command2, "%c%d", &to_y, &to_x);
                         }
                }
		if(player == 1){
			from_y = charBlackLogic(from_y);
			from_x = numBlackLogic(from_x);
			to_y = charBlackLogic(to_y);
			to_x = numBlackLogic(to_x);
		}
                if(getPosition_logic(cb, from_y, from_x) -> color != BLACK){
                        printf("Wrong piece selected please go again\n");
                        continue;
                }
		if(check_valid_move_logic(cb, from_y, from_x, to_y, to_x) != 1){
			printf("Invalid move please try again\n");
			continue;
		}
		else{
			if(getPosition_logic(cb, from_y, from_x) -> type == PAWN){
				movement(cb, from_x, to_x, from_y, to_y);
				PawnPromotion(cb, to_y, to_x);
			}
			else
                		movement(cb,from_x, to_x, from_y, to_y);
                	valid = 8;
		}

        }

        return 1;
}
int numBlackLogic(int x){
	switch(x){
		case 1:
			x=8;
			break;
		case 2:
			x=7;
			break;
		case 3:
			x=6;
			break;
		case 4:
			x=5;
			break;
		case 5:
			x=4;
			break;
		case 6:
			x=3;
			break;
		case 7:
			x=2;
			break;
		case 8:
			x=1;
			break;
	} 
	return x;
}
char charBlackLogic(char x){
	switch(x){
		case 97:
			x=104;
			break;
		case 98:
			x=103;
			break;
		case 99:
			x=102;
			break;
		case 100:
			x=101;
			break;
		case 101:
			x=100;
			break;
		case 102:
			x=99;
			break;
		case 103:
			x=98;
			break;
		case 104:
			x=97;
			break;		
	}
	return x;
	
}
 
//Physically moves a piece
void movement( ChessBoard* cb, int from_x, int to_x, char from_letter, char to_letter){
	Chess* startp = getPosition_logic(cb, from_letter, from_x);
	Chess* finalp = getPosition_logic(cb, to_letter, to_x);
	createNull(finalp);
	finalp = copyPiece(startp, finalp);	
	finalp->LastMove++;
	createNull(startp);
	
	
}
/*asks player to pick which team they would like to be in*/
int PickSide(){
	int color;
	printf("Pick a side\nEnter 0 to be red or 1 to be magenta:\n");
	scanf("%d",&color);
	while(color > 1 || color < 0){
		printf("Invalid team selection.\n Please enter 0 for white or 1 for black");
		scanf("%d",&color);
	}
	return color;

}
/*INitial Print screen returns players choice of team color*/
int Menu(){
	int x;
	printf("Welcome to Team 17's game of chess,\n");
	x=PickSide();
	return x;
}


/* if someone won, returns 1 which will be used in an if to break the while loop of main*/
int EndGame(int CCondition){
	if(CCondition==1){
		printf("Checkmate.");
		return 1;
	}
	else{
		return 0;
	}
}


void IfUndoW(ChessBoard* cbPre, ChessBoard* cb, int Player)
{
  int UndoRes = 2;
  printf("Do you want to undo? 0 for no, 1 for yes\n" );
  scanf("%d", &UndoRes);
  while (UndoRes == 1)
  {
    cb = copyChessBoard(cbPre); //save the chessboard
    displayBoard(cb); //display previous chessboard 
    WhiteTurn(cb, Player);  
		displayBoard(cb);  
    break;   
  }
}

void IfUndoB(ChessBoard* cbPre, ChessBoard* cb, int Player)
{
  int UndoRes = 2;
  printf("Do you want to undo? 0 for no, 1 for yes\n" );
  scanf("%d", &UndoRes);
  while (UndoRes == 1)
  {
    cb = copyChessBoard(cbPre); //save the chessboard
    displayBoard(cb); //display previous chessboard 
    BlackTurn(cb, Player);  
		//displayBoard(cb);  
    break;     
  }
}
 
void IfUndoWr(ChessBoard* cbPre, ChessBoard* cb, int Player)
{
  int UndoRes = 2;
  printf("Do you want to undo? 0 for no, 1 for yes\n" );
  scanf("%d", &UndoRes);
  while (UndoRes == 1)
  {
    cb = copyChessBoard(cbPre); //save the chessboard
    rdisplayBoard(cb); //display previous chessboard 
    WhiteTurn(cb, Player);  
		rdisplayBoard(cb);   
    break;    
  }
}

void IfUndoBr(ChessBoard* cbPre, ChessBoard* cb, int Player)
{
  int UndoRes = 2;
  printf("Do you want to undo? 0 for no, 1 for yes\n" );
  scanf("%d", &UndoRes);
  while (UndoRes == 1)
  {
    cb = copyChessBoard(cbPre); //save the chessboard
    rdisplayBoard(cb); //display previous chessboard 
    BlackTurn(cb, Player);  
		rdisplayBoard(cb); 
    break;      
  }
}
