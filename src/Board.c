//
// Created by Entropy Xu on 2019-01-23.
//

#include "Board.h"

Chess* createChess(ChessType type, ChessColor color)
{
    Chess* che = malloc(sizeof(Chess));
    che -> color = color;
    che -> isEmpty = 0;
    che -> type = type;
    che -> LastMove = 0;
    return che;
}
void createNull(Chess* chess){
	chess -> color = 0;
	chess -> isEmpty = 1;
	chess -> type = 0;
	chess -> LastMove = 0;
}
Chess* copyPiece(Chess* init, Chess* fin){
	fin -> color = init -> color;
	fin -> isEmpty = init -> isEmpty;
	fin -> type = init -> type;
	fin -> LastMove = init -> LastMove;
	return fin;
}
Chess* createEmpty()
{
    Chess* che = malloc(sizeof(Chess));
    che -> color = 0;
    che -> type = 0;
    che -> isEmpty = 1;
    che -> LastMove = 0;
    return che;
}

void deleteChess(Chess* chess)
{
    assert(chess);
    free(chess);
}

ChessBoard* createChessBoard()
{
    ChessBoard* cb = malloc(sizeof(ChessBoard));
    for(int i = 0; i < WIDTH; i++)
        for(int j = 0; j < HEIGHT; j++)
        {
            cb -> board[i][j] = createEmpty();
        }
    return cb;
}

void deleteChessBoard(ChessBoard* cb)
{
    assert(cb);
    for(int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            deleteChess(cb->board[i][j]);
        }
    }

        free(cb);
}

void putChessAtGameStart(ChessBoard* cb)
{
    assert(cb);
    Chess* pawn_w_0 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_0, 0, 1);
    Chess* pawn_w_1 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_1, 1, 1);
    Chess* pawn_w_2 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_2, 2, 1);
    Chess* pawn_w_3 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_3, 3, 1);
    Chess* pawn_w_4 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_4, 4, 1);
    Chess* pawn_w_5 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_5, 5, 1);
    Chess* pawn_w_6 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_6, 6, 1);
    Chess* pawn_w_7 = createChess(PAWN, WHITE);
    setPosition(cb, pawn_w_7, 7, 1);

    Chess* pawn_b_0 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_0, 0, 6);
    Chess* pawn_b_1 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_1, 1, 6);
    Chess* pawn_b_2 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_2, 2, 6);
    Chess* pawn_b_3 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_3, 3, 6);
    Chess* pawn_b_4 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_4, 4, 6);
    Chess* pawn_b_5 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_5, 5, 6);
    Chess* pawn_b_6 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_6, 6, 6);
    Chess* pawn_b_7 = createChess(PAWN, BLACK);
    setPosition(cb, pawn_b_7, 7, 6);

    Chess* rook_w_0 = createChess(ROOK, WHITE);
    setPosition(cb, rook_w_0, 0, 0);
    Chess* rook_w_1 = createChess(ROOK, WHITE);
    setPosition(cb, rook_w_1, 7, 0);
    Chess* rook_b_0 = createChess(ROOK, BLACK);
    setPosition(cb, rook_b_0, 7, 7);
    Chess* rook_b_1 = createChess(ROOK, BLACK);
    setPosition(cb, rook_b_1, 0, 7);

    Chess* knight_w_0 = createChess(KNIGHT, WHITE);
    setPosition(cb, knight_w_0, 1, 0);
    Chess* knight_w_1 = createChess(KNIGHT, WHITE);
    setPosition(cb, knight_w_1, 6, 0);
    Chess* knight_b_0 = createChess(KNIGHT, BLACK);
    setPosition(cb, knight_b_0, 1, 7);
    Chess* knight_b_1 = createChess(KNIGHT, BLACK);
    setPosition(cb, knight_b_1, 6, 7);

    Chess* bishop_w_0 = createChess(BISHOP, WHITE);
    setPosition(cb, bishop_w_0, 2, 0);
    Chess* bishop_w_1 = createChess(BISHOP, WHITE);
    setPosition(cb, bishop_w_1, 5, 0);
    Chess* bishop_b_0 = createChess(BISHOP, BLACK);
    setPosition(cb, bishop_b_0, 2, 7);
    Chess* bishop_b_1 = createChess(BISHOP, BLACK);
    setPosition(cb, bishop_b_1, 5, 7);

    Chess* king_w = createChess(KING, WHITE);
    setPosition(cb, king_w, 4, 0);
    Chess* king_b = createChess(KING, BLACK);
    setPosition(cb, king_b, 4, 7);
    Chess* queen_w = createChess(QUEEN, WHITE);
    setPosition(cb, queen_w, 3, 0);
    Chess* queen_b = createChess(QUEEN, BLACK);
    setPosition(cb, queen_b, 3, 7);
}

Chess* getPosition(ChessBoard* cb, int x, int y)
{
    assert(cb);
    assert(0 <= x && x <= 7);
    assert(0 <= y && y <= 7);
    return cb -> board[x][y];
}

int setPosition(ChessBoard* cb, Chess* che, int x, int y)
{
    assert(cb);
    assert(che);
    assert(0 <= x && x <= 7);
    assert(0 <= y && y <= 7);
    cb -> board[x][y] = che;
    return 1;
}

int setPosition_logic(ChessBoard* cb, Chess* che, char x_logic, int y_logic)
{
    int x = 0;

    switch (x_logic)
    {
        case 97:
            x = 0;
            break;
        case 98:
            x = 1;
            break;
        case 99:
            x = 2;
            break;
        case 100:
            x = 3;
            break;
        case 101:
            x = 4;
            break;
        case 102:
            x = 5;
            break;
        case 103:
            x = 6;
            break;
        case 104:
            x = 7;
            break;
        default:
            x = 0;
    }

    return setPosition(cb, che, x, y_logic - 1);
}

Chess* getPosition_logic(ChessBoard* cb, char x_logic, int y_logic)
{
    int x = 0;

    switch (x_logic)
    {
        case 'a':
            x = 0;
            break;
        case 'b':
            x = 1;
            break;
        case 'c':
	    x = 2;
            break;
        case 'd':
            x = 3;
            break;
        case 'e':
            x = 4;
            break;
        case 'f':
            x = 5;
            break;
        case 'g':
            x = 6;
            break;
        case 'h':
            x = 7;
            break;
        default:
            x = 0;
    }

    return getPosition(cb, x, y_logic - 1);
}

void displayBoard(ChessBoard* cb)
{
    int boardnum[8] = {1,2,3,4,5,6,7,8};
    assert(cb);
    for(int i = WIDTH - 1; i >= 0; i--){
                printf("----");
    }
    printf("\n");
    for(int j = HEIGHT - 1; j >= 0; j--)
    {
        for(int i = 0; i < WIDTH; i++)
        {
	    Chess* che = getPosition(cb, i, j);	
            switch(getPosition(cb, i, j) -> type)
            {
                case KING:
		    if(che -> color == WHITE)
			printf("| "KRED "K" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "K" RESET" ");
                    break;
                case QUEEN:
		    if(che -> color == WHITE)
			printf("| "KRED "Q" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "Q" RESET" "); 
                    break;
                case BISHOP:
		    if(che -> color == WHITE)
			printf("| "KRED "B" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "B" RESET" ");
                    break;
                case ROOK:
		    if(che -> color == WHITE)
			printf("| "KRED "R" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "R" RESET" ");
                    break;
                case KNIGHT:
		    if(che -> color == WHITE)
			printf("| "KRED "k" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "k" RESET" ");
                    break;
                case PAWN:
		    if(che -> color == WHITE)
			printf("| "KRED "P" RESET" ");
		    else if(che -> color == BLACK)
			printf("| "KMAG "P" RESET" ");
                    break;
                default:
                    printf("|   ");
                    break;
            }
        }
	printf("| %d",boardnum[j]);
        printf("\n");
	for(int i = WIDTH - 1; i >= 0; i--){
		printf("----");
	}
	printf("\n");
    }
    printf("  a   b   c   d   e   f   g   h\n\n");

}
void rdisplayBoard(ChessBoard* cb)
{
    int boardnum[8] = {8,7,6,5,4,3,2,1};
    assert(cb);
    for(int i = WIDTH - 1; i >= 0; i--){
                printf("----");
    }
    printf("\n");
    for(int j = 0; j <= HEIGHT - 1; j++)
    {
        for(int i = WIDTH - 1; i >= 0; i--)
        {
	    Chess* che = getPosition(cb, i, j);
            switch(getPosition(cb, i, j) -> type)
            {
                case KING:
                    if(che -> color == WHITE)
                        printf("| "KRED "K" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "K" RESET" ");
                    break;
                case QUEEN:
                    if(che -> color == WHITE)
                        printf("| "KRED "Q" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "Q" RESET" ");
                    break;
                case BISHOP:
                    if(che -> color == WHITE)
                        printf("| "KRED "B" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "B" RESET" ");
                    break;
                case ROOK:
                    if(che -> color == WHITE)
                        printf("| "KRED "R" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "R" RESET" ");
                    break;
                case KNIGHT:
                    if(che -> color == WHITE)
                        printf("| "KRED "k" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "k" RESET" ");
                    break;
                case PAWN:
                    if(che -> color == WHITE)
                        printf("| "KRED "P" RESET" ");
                    else if(che -> color == BLACK)
                        printf("| "KMAG "P" RESET" ");
                    break;
                default:
                    printf("|   ");
                    break;
            }
        }
	printf("| %d",boardnum[j]);
        printf("\n");
	for(int i = WIDTH - 1; i >= 0; i--){
		printf("----");
	}
	printf("\n");
    }
    printf("  a   b   c   d   e   f   g   h\n\n");
}

ChessBoard* copyChessBoard(ChessBoard* cb)
{
    ChessBoard* ret_cb = createChessBoard();
    for(int i =0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            if(cb -> board[i][j] -> type != 0)
                ret_cb -> board[i][j] = createChess(cb -> board[i][j] -> type, cb -> board[i][j] -> color);
            else
                ret_cb -> board[i][j] = createEmpty();
        }
    }

    return ret_cb;
}


#ifdef DEBUG
int main()
{
    ChessBoard* cb = createChessBoard();
    putChessAtGameStart(cb);
    ChessBoard* cbb = copyChessBoard(cb);
    displayBoard(cbb);
    deleteChessBoard(cb);
    deleteChessBoard(cbb);
    return 0;
}
#endif
