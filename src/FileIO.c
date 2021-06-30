//
// Created by Entropy Xu on 2019-01-30.
//

#include "FileIO.h"


int saveChessBoard(ChessBoard* cb, ChessColor current_turn, char* filename)
{
    FILE* fp;
    fp = fopen(filename, "w");
    fprintf(fp, "%d\n", (int)current_turn);
    for(int i = HEIGHT - 1; i >= 0; i--)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(cb -> board[j][i] -> color == WHITE)
                fprintf(fp, "%d,", (int)cb -> board[j][i] -> type);
            else if(cb -> board[j][i] -> color == BLACK)
                fprintf(fp, "%d,", ((int)cb -> board[j][i] -> type) + 6);
            else if(cb -> board[j][i] -> color == 0)
                fprintf(fp, "%d,", 0);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 1;
}

ChessBoard* loadChessBoard(char* filename)
{

    FILE* fp;
    fp = fopen(filename, "r");

    ChessBoard* cb = createChessBoard();

    int turn;
    fscanf(fp, "%d\n", & turn);

    for(int i = HEIGHT - 1; i >= 0; i--)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            int num;
            fscanf(fp, "%d,", & num);
            if(num == 0)
                cb -> board[j][i] = createEmpty();
            else if(num > 0 && num <= 6)
                cb -> board[j][i] = createChess((ChessType)num, WHITE);
            else if(num > 6)
                cb -> board[j][i] = createChess((ChessType)(num - 6), BLACK);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
    return cb;
}

ChessColor loadChessTurn(char* filename)
{
    FILE* fp;
    fp = fopen(filename, "r");

    int turn;

    fscanf(fp, "%d\n", & turn);

    fclose(fp);
    return (ChessColor)turn;
}

int saveGame(ChessBoard* cb, ChessColor current_side, char* game_name, int turn_num)
{
    char filename[20];

    for(int i = 0; i < 20; i++)
        filename[i] = 0;

    sprintf(filename, "%s_%d.sav", game_name, turn_num);

#ifdef DEBUG
    printf("%s\n", filename);
    fflush(stdout);
#endif

    return saveChessBoard(cb, current_side, filename);
}

ChessBoard* loadGameChessBoard(char* game_name, int turn_num)
{
    char filename[20];

    for(int i = 0; i < 20; i++)
        filename[i] = 0;

    sprintf(filename, "%s_%d.sav", game_name, turn_num);

#ifdef DEBUG
    printf("%s\n", filename);
    fflush(stdout);
#endif

    return loadChessBoard(filename);
}

ChessColor loadGameCurrentTurn(char* game_name, int turn_num)
{
    char filename[20];

    for(int i = 0; i < 20; i++)
        filename[i] = 0;

    sprintf(filename, "%s_%d.sav", game_name, turn_num);

#ifdef DEBUG
    printf("%s\n", filename);
    fflush(stdout);
#endif

    return loadChessTurn(filename);
}


#ifdef DEBUG
int main()
{
    ChessBoard* cb = createChessBoard();
    putChessAtGameStart(cb);

    saveGame(cb, 1, "game1", 1);

    ChessBoard* cbb = loadGameChessBoard("game1", 1);
    displayBoard(cbb);

    printf("Current side: %d\n", loadGameCurrentTurn("game1", 1));
}
#endif
