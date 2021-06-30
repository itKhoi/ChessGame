/*GUI header file by Hayley Sperber*/

#ifndef _SIMPLE_H
#define _SIMPLE_H


#define MAX_MSGLEN  100
#define SQUARE_SIZE 50
#define WINDOW_BORDER 30
#define BOARD_BORDER 30
#define BOARD_WIDTH  (8*SQUARE_SIZE)
#define BOARD_HEIGHT (8*SQUARE_SIZE)
#define WINDOW_WIDTH  (BOARD_WIDTH + 8*BOARD_BORDER)
#define WINDOW_HEIGHT (BOARD_HEIGHT + 8*BOARD_BORDER)

enum GRID
{
        BLACK = 0,
        WHITE = 1,
        KING
        QUEEN
        BISHOP
        KNIGHT
        ROOK
        PAWN
};


#endif







