#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Move.h"
#include "Board.h"
#include "AI.h"
/* Lets the user pick which team they want to be in*/

int PickSide();

/* Determines if the piece trying to be moved is the current player's piece if not, it keeps asking until the right move is made*/

int WhiteTurn(ChessBoard* cb, int player);
int BlackTurn(ChessBoard* cb, int player);
//converts black input to fit with data structure
int numBlackLogic(int x);
char charBlackLogic(char x);
// main game
int Game(int Player, int mode);
//Moves the piece
void movement(ChessBoard* cb, int from_x, int to_x, char from_letter, char to_letter);

/* main menu stuff*/
int Menu();
int PickSide();
/*Ends the game if checkmate ahs been achieved*/
int EndGame(int CCondition);

//Ask if the player want to undo
void IfUndoW(ChessBoard* cbPre, ChessBoard* cb, int Player);
void IfUndoB(ChessBoard* cbPre, ChessBoard* cb, int Player);
void IfUndoWr(ChessBoard* cbPre, ChessBoard* cb, int Player);
void IfUndoBr(ChessBoard* cbPre, ChessBoard* cb, int Player); 