//
// Created by Entropy on 1/31/19.
// Edited by Samuel Wong and Hayley Sperber

#ifndef MOVE_H
#define MOVE_H
#include "Board.h"
#include "ChessGame.h"
#include <stdio.h>

int check_valid_move(ChessBoard*cb, int from_x, int from_y, int to_x, int to_y);

int execute_move(ChessBoard* cb, int from_x, int from_y, int to_x, int to_y);

int PawnPromotion(ChessBoard* cb, char to_x, int to_y);

int check_valid_move_logic(ChessBoard* cb, char from_x, int from_y, char to_x, int to_y);

int White_check_check(ChessBoard* cb);

int WiVertup_Check(ChessBoard* cb, int kx, int ky);

int WiVertdown_Check(ChessBoard* cb,int kx, int ky);

int WiHorrite_Check(ChessBoard* cb,int kx, int ky);

int WiHorleft_Check(ChessBoard* cb,int kx, int ky);

int WiDiagUpRt_Check(ChessBoard* cb, int kx, int ky);

int WiDiagUpLft_Check(ChessBoard* cb, int kx, int ky);

int WiDiagDownRt_Check(ChessBoard* cb, int kx, int ky);

int WiDiagDownLft_Check(ChessBoard* cb, int kx, int ky);

int Winite_check(ChessBoard* cb,int kx, int ky);

int Black_check_check(ChessBoard* cb);

int BVertup_Check(ChessBoard* cb,int kx, int ky);

int BVertdown_Check(ChessBoard* cb,int kx, int ky);

int BHorrite_Check(ChessBoard* cb,int kx, int ky);

int BHorleft_Check(ChessBoard* cb,int kx, int ky);

int BDiagUpRt_Check(ChessBoard* cb, int kx, int ky);

int BDiagUpLft_Check(ChessBoard* cb, int kx, int ky);

int BDiagDownRt_Check(ChessBoard* cb, int kx, int ky);

int BDiagDownLft_Check(ChessBoard* cb, int kx, int ky);

int Bnite_check(ChessBoard* cb,int kx, int ky);


#endif
