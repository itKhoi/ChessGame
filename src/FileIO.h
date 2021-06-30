//
// Created by Entropy Xu on 2019-01-30.
//

#ifndef FILEIO_H
#define FILEIO_H

#include "Board.h"
#include "Move.h"
#include "stdio.h"

/* save the ChessBoard cb with current side "current_turn" to file with filename */
int saveChessBoard(ChessBoard* cb, ChessColor current_turn, char* filename);

/* load the ChessBoard with file name "filename" */
ChessBoard* loadChessBoard(char* filename);

/* load the Current side of the game in filename */
ChessColor loadChessTurn(char* filename);

/* save the game state to a file, call this function when one of the player moves
 * This function will save every move into a single file with name "%s_%d.sav", game_name, turn_num
 * The parameter ChessBoard is the ChessBoard you want to save and the current_side is the current side of the game*/
int saveGame(ChessBoard* cb, ChessColor current_side, char* game_name, int turn_num);

/* load the ChessBoard from the game with game_name at turn "turn_num"
 * You can also think this function as load the ChessBoard of the file "%s_%d.sav", game_name, turn_num */
ChessBoard* loadGameChessBoard(char* game_name, int turn_num);

/* Load the Current Turn from the game with game_name at turn "turn_num"
 * You can also think this function as load the Current Turn of the file "%s_%d.sav", game_name, turn_num */
ChessColor loadGameCurrentTurn(char* game_name, int turn_num);

#endif //TEAM17_FILEIO_H
