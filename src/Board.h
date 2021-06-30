//
// Created by Entropy Xu on 2019-01-23.
//

#ifndef BOARD_H
#define BOARD_H

#define WIDTH 8
#define HEIGHT 8
#define KRED "\x1B[31m"
#define KMAG "\x1B[35m"
#define KWHT "\x1B[37m"
#define RESET "\x1B[0m"
//<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//#include "Move.h"
//=======
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"


// The type for the color of the chess and sometimes used to represent which player is taking a movement.
typedef enum {WHITE = 1, BLACK = 2} ChessColor;

// The type for all kind of pieces. the value 0 or NULL means empty.
typedef enum {KING = 1,
              QUEEN = 2,
              BISHOP = 3,
              ROOK = 4,
              KNIGHT = 5,
              PAWN = 6
} ChessType;

// The structure for a Chess, containing the type of the chess and the color of the chess. isEmpty is for redundancy.
typedef struct{
    ChessType type;
    ChessColor color;
    int isEmpty;
    int LastMove;
} Chess;

// Create the Chess with Chess type and Chess color
Chess* createChess(ChessType type, ChessColor color);
//Make a current chess struct null
void createNull(Chess* chess);
//set one chess piece equal to the other
Chess* copyPiece(Chess* init, Chess* fin);
// Create an empty chess which is usually used to represent the empty space on board.
Chess* createEmpty();

// delete the Chess and free the memory
void deleteChess(Chess* chess);

// The data structure for the main chessboard.
typedef struct{
    Chess* board[8][8];
} ChessBoard;

// create an empty chess board
ChessBoard* createChessBoard();

// delete the chess board and free the memory
void deleteChessBoard(ChessBoard* cb);

// put the chess at the position of a game start
void putChessAtGameStart(ChessBoard* cb);

// set the the Chess che in the Chessboard cb at logical position x and y
// A logical position is where the position is on the board not in the 2-D array
// For example: d5, a3
int setPosition_logic(ChessBoard* cb, Chess* che, char x_logic, int y_logic);

// get the chess at logical position x and y in board cb
Chess* getPosition_logic(ChessBoard* cb, char x_logic, int y_logic);

// set the the Chess che in the Chessboard cb at array index x and y
int setPosition(ChessBoard* cb, Chess* che, int x, int y);

// get the chess at array index [x][y]
Chess* getPosition(ChessBoard* cb, int x, int y);

// copy the content of the chessboard from the cb.
ChessBoard* copyChessBoard(ChessBoard* cb);

// a simple terminal interface to display the board
// used for debugging
void displayBoard(ChessBoard* cb);
//for use when player picks black
void rdisplayBoard(ChessBoard* cb);

#endif //BOARD_H
