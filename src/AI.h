//
// 1/28/2019
//

#ifndef AI_H
#define AI_H

#include "Move.h"
#include "Board.h"
#include "ChessGame.h"


//Function will change the chess board itself, so it will return nothing
void bestMove(ChessBoard* cb, int AIcolor);

int notInCheck(ChessBoard* cb, int AIcolor);

int scoreKnightCapture(ChessBoard* cb, int x, int y, int AIcolor);

int scoreQueenCapture(ChessBoard* cb, int x, int y, int AIcolor);

int scoreBishopCapture(ChessBoard* cb, int x, int y, int AIcolor);

int scoreRookCapture(ChessBoard* cb, int x, int y, int AIcolor);

int scorePawnCapture(ChessBoard* cb, int x, int y, int AIcolor);

int appraise(ChessBoard* cb, int x, int y);

int decodeScore(int x);

int decodefx(int x);

int decodefy(int x);

int decodetx(int x);

int decodety(int x);


#endif