//
// Created by entropy on 1/31/19.
// editd by samuel wong 2/6/19

#include "Move.h"
#include <stdio.h>

// return 1 for a valid move, return 0 for a invalid move
// return 2 for when the pawn can do a promotion
int check_valid_move(ChessBoard* cb, int from_x, int from_y, int to_x, int to_y)
{
    assert(from_x >= 0);
    assert(from_x < WIDTH);
    assert(from_y >= 0);
    assert(from_y < HEIGHT);
    assert(to_x >= 0);
    assert(to_x < WIDTH);
    assert(to_y >= 0);
    assert(to_y < HEIGHT);

    Chess* che = cb -> board[from_x][from_y];
    int castle;
    // Check it is a valid move
    if(from_x == to_x && from_y == to_y)
        return 0;

    // Check if the piece is not killing its own piece
    if(cb -> board[to_x][to_y] -> color == che -> color)
        return 0;

    if(che->type == PAWN)
    {
        // PAWN
        assert(che->color != 0);
        if(che->color == WHITE)
        {
            // WHITE
            if(from_y == 7)
                return 2;
            if(from_y == 1)
            {
                // the pawn hasn't been moved
                if(to_x == from_x && to_y == from_y + 2)
                    return 1;
            }
	    // not working en pessant
//	    if(to_x == from_x +1 && to_y == from_y +1 && cb -> board[from_x + 1][from_y] -> color == BLACK && cb -> board[from_x + 1][from_y] -> LastMove == 1)
//	    {
//		cb -> board[from_x + 1][from_y] -> LastMove += 1;
//		return 1;
//	    }
//	    if(to_x == from_x - 1 && to_y == from_y + 1 && cb -> board[from_x - 1][from_y] -> color == BLACK && cb -> board[from_x - 1][from_y] -> LastMove == 1)
//	    {
//		cb -> board[from_x - 1][from_y] -> LastMove += 1;
//		return 1;
//	    }
            if(to_x == from_x + 1 && to_y == from_y + 1
               && cb -> board[to_x][to_y] -> color == BLACK)
                return 1;
            if(to_x == from_x - 1 && to_y == from_y + 1
               && cb -> board[to_x][to_y] -> color == BLACK)
                return 1;

            if(to_x == from_x && to_y == from_y + 1)
            {
                if(cb->board[to_x][to_y] -> color == WHITE)
                    return 0;
                return 1;
            } else
            {
                return 0;
            }
        } else
        {
            // BLACK
            if(from_y == 0)
                return 2;
            if(from_y == 6)
            {
                // the pawn hasn't been moved
                if(to_x == from_x && to_y == from_y - 2)
                    return 1;
            }

            if(to_x == from_x + 1 && to_y == from_y - 1
               && cb -> board[to_x][to_y] -> color == WHITE)
                return 1;
            if(to_x == from_x - 1 && to_y == from_y - 1
               && cb -> board[to_x][to_y] -> color == WHITE)
                return 1;


            if(to_x == from_x && to_y == from_y - 1)
            {
                if(cb->board[to_x][to_y] -> color == BLACK)
                    return 0;
                return 1;
            } else
            {
                return 0;
            }
        }
    } else if(che->type == KING)
    {
        // KING
	// White king castle
	
	if( cb->board[5][0]->isEmpty==1 && cb->board[6][0]->isEmpty==1 && cb->board[7][0]->type==ROOK){
		if(che->LastMove==0 && cb->board[7][0]->LastMove==0 && to_x==6 && to_y==0){
			movement(cb,1,1,'e','f');
			castle = White_check_check(cb);
			if(castle > 0){
				movement(cb,1,1,'f','e');
				return 0;
			}
			movement(cb,1,1,'f','g');
			castle=White_check_check(cb);
			if(castle>0){
				movement(cb,1,1,'g','e');
				return 0;
			}
			movement(cb,1,1,'g','e');
			movement(cb, 1, 1, 'h', 'f');
	        	return 1;
	        }
	        else
			return 0;
	}
	if(cb->board[1][0]->isEmpty==1 && cb->board[2][0]->isEmpty==1 && cb->board[3][0]->isEmpty==1 && cb->board[0][0]->type==ROOK){        
		if(che->LastMove==0 && cb->board[0][0]->LastMove==0 && to_x==2 && to_y==0){
			movement(cb,1,1,'e','d');
			castle=White_check_check(cb);
			if(castle>0){
				movement(cb,1,1,'d','e');
				return 0;
			}
			movement(cb,1,1,'d','c');
			castle=White_check_check(cb);
			if(castle>0){
				movement(cb,1,1,'c','e');
				return 0;
			}
			movement(cb,1,1,'c','b');
			castle=White_check_check(cb);
			if(castle>0){
				movement(cb,1,1,'b','e');
				return 0;
			}
			movement(cb,1,1,'b','e');
			movement(cb, 1, 1, 'a', 'd');
			return 1;
		}
		else
			return 0;
	}
	// Black kind castle
	if(cb->board[5][7]->isEmpty==1 && cb->board[6][7]->isEmpty==1 && cb->board[7][7]->type==ROOK){
		if(che->LastMove==0 && cb->board[7][7]->LastMove==0 && to_x==6 && to_y==7){
                        movement(cb,1,1,'e','f');
                        castle = Black_check_check(cb);
                        if(castle > 0){
                                movement(cb,8,8,'f','e');
                                return 0;
                        }
                        movement(cb,8,8,'f','g');
                        castle=Black_check_check(cb);
                        if(castle>0){
                                movement(cb,8,8,'g','e');
                                return 0;
                        }
                        movement(cb,8,8,'g','e');
			movement(cb, 8, 8, 'h', 'f');
			return 1;
		}
		else
			return 0;
	}
	if(cb->board[1][7]->isEmpty==1 && cb->board[2][7]->isEmpty==1 && cb->board[3][7]->isEmpty==1 && cb->board[0][7]->type==ROOK){
		if(che->LastMove==0 && cb->board[0][7]->LastMove==0 && to_x==2 && to_y==7){
                        movement(cb,8,8,'e','d');
                        castle=Black_check_check(cb);
                        if(castle>0){
                                movement(cb,8,8,'d','e');
                                return 0;
                        }
                        movement(cb,8,8,'d','c');
                        castle=Black_check_check(cb);
                        if(castle>0){
                                movement(cb,8,8,'c','e');
                                return 0;
                        }
                        movement(cb,8,8,'c','b');
                        castle=Black_check_check(cb);
                        if(castle>0){
                                movement(cb,8,8,'b','e');
                                return 0;
                        }
                        movement(cb,8,8,'b','e');
			movement(cb, 8, 8, 'a', 'd');
			return 1;
		}
		else
			return 0;
	}
        if(abs(to_x - from_x) <= 1 && abs(to_y - from_y) <= 1)
        {
            if(che->color == cb -> board[to_x][to_y] ->color)
                return 0;
            return 1;
        }
        return 0;	
    } else if(che->type == QUEEN)
    {
        // QUEEN
        int x_del = to_x - from_x;
        int y_del = to_y - from_y;

        // check when the piece is not moving diagnally or +
        if(abs(x_del) != abs(y_del) && x_del != 0 && y_del != 0)
            return 0;

        int x_dir, y_dir;
        if(x_del == 0)
            x_dir = 0;
        else
            x_dir = x_del / abs(x_del);

        if(y_del == 0)
            y_dir = 0;
        else
            y_dir = y_del / abs(y_del);

        int x_cur = x_dir + from_x;
        int y_cur = y_dir + from_y;


        if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
        {
            if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                return 1;
            // the road is not empty
            return 0;
        }

        while(x_cur != to_x || y_cur != to_y)
        {
            // if the road is empty
            x_cur += x_dir;
            y_cur += y_dir;

            if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
            {
                if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                    return 1;
                // the road is not empty
                return 0;
            }
        }
        return 1;
    } else if(che->type == ROOK)
    {
        // ROOK
        int x_del = to_x - from_x;
        int y_del = to_y - from_y;

        // check when the piece is moving +
        if(x_del != 0 && y_del != 0)
            return 0;

        int x_dir, y_dir;
        if(x_del == 0)
            x_dir = 0;
        else
            x_dir = x_del / abs(x_del);

        if(y_del == 0)
            y_dir = 0;
        else
            y_dir = y_del / abs(y_del);


        int x_cur = x_dir + from_x;
        int y_cur = y_dir + from_y;
        if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
        {
            if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                return 1;
            // the road is not empty
            return 0;
        }
        while(x_cur != to_x || y_cur != to_y)
        {
            // if the road is empty
            x_cur += x_dir;
            y_cur += y_dir;

            if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
            {
                if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                    return 1;
                // the road is not empty
                return 0;
            }
        }
        return 1;
    } else if(che->type == BISHOP)
    {
        // BISHOP
        int x_del = to_x - from_x;
        int y_del = to_y - from_y;

        // check when the piece is not moving diagnally or +
        if(abs(x_del) != abs(y_del))
            return 0;


        int x_dir, y_dir;
        if(x_del == 0)
            x_dir = 0;
        else
            x_dir = x_del / abs(x_del);

        if(y_del == 0)
            y_dir = 0;
        else
            y_dir = y_del / abs(y_del);

        int x_cur = x_dir + from_x;
        int y_cur = y_dir + from_y;
        if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
        {
            if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                return 1;
            // the road is not empty
            return 0;
        }
        while(x_cur != to_x || y_cur != to_y)
        {
            // if the road is empty
            x_cur += x_dir;
            y_cur += y_dir;

            if(cb -> board[x_cur][y_cur] -> isEmpty != 1)
            {
                if(cb -> board[x_cur][y_cur] ->color != che -> color && x_cur == to_x && y_cur == to_y)
                    return 1;
                // the road is not empty
                return 0;
            }
        }
        return 1;
    } else if(che->type == KNIGHT)
    {
        // KNIGHT
        int x_del_abs = abs(from_x - to_x);
        int y_del_abs = abs(from_y - to_y);

        if((x_del_abs == 1 && y_del_abs == 2) | (x_del_abs == 2 && y_del_abs == 1)) {
            if (cb->board[to_x][to_y]->color == che->color)
                return 0;
            return 1;
        }
        else
            return 0;
    } else if(che->type == 0)
    {
        // EMPTY
        return -1;
    }
    assert(0);
    return -1;
}

int char_to_index(char ch)
{
    int index = -1;
    switch (ch) {
        case 'a':
            index = 0;
            break;
        case 'b':
            index = 1;
            break;
        case 'c':
            index = 2;
            break;
        case 'd':
            index = 3;
            break;
        case 'e':
            index = 4;
            break;
        case 'f':
            index = 5;
            break;
        case 'g':
            index = 6;
            break;
        case 'h':
            index = 7;
            break;
    }
    assert(index != -1);
    return index;
}

int check_valid_move_logic(ChessBoard* cb, char from_x, int from_y, char to_x, int to_y)
{
    int from_x_index = char_to_index(from_x);
    int to_x_index = char_to_index(to_x);
    int from_y_index = from_y - 1;
    int to_y_index = to_y - 1;

    return check_valid_move(cb, from_x_index, from_y_index, to_x_index, to_y_index);
}

int displayPossibleMoves(ChessBoard* cb, int x, int y)
{
    for(int j = HEIGHT - 1; j >= 0; j--)
    {
        for(int i = 0; i < WIDTH; i++)
        {
            printf("%c|", check_valid_move(cb, x, y, i, j)==0 ? ' ' : '+');
            fflush(stdout);
        }
        printf("\n");
    }
    return 1;
}
int PawnPromotion(ChessBoard* cb, char to_x, int to_y){
	Chess* che = getPosition_logic(cb, to_x, to_y);
	//ChessColor* ccolor = che -> color;	
		
	int newp;
	if(to_y == 8 || to_y ==1){
		printf("Pawn is being promoted select what piece\n");
		printf("1 for Queen, 2 for Bishop, 3 for Rook, 4 for Knight:\n");
		scanf("%d",&newp);
		while(newp > 4 || newp < 1){
			printf("Invalid selection\n");
			printf("1 for Queen, 2 for Bishop, 3 for Rook, 4 for Knight:\n");
			scanf("%d",&newp);
		}
		newp = newp + 1;
		che -> type = newp;
		//setPosition_logic(cb, che, to_x, to_y);
		return 1;
	}
	return 0;	
}

int White_check_check(ChessBoard*cb){
	//find king position
	int kx=0;
	int ky=0;
	int check=0;
	int upcheck=0;
	int downcheck=0;
	int leftcheck=0;
	int ritecheck=0;
	int uprtcheck=0;
	int uplftcheck=0;
	int drtcheck=0;
	int dlftcheck=0;
	int nitecheck=0;
	int checkmate=0;
	int kempty=0;
	for(int x=0;x<=7;x++){ //find king
		for(int y=0;y<=7;y++){
			if(cb->board[x][y]->type==KING&&cb->board[x][y]->color==WHITE){
				kx=x;
				ky=y;
			}
		}
	}
	if(cb->board[kx+1][ky]->isEmpty==0){
		if((kx+1)<=7){
			kempty++;
			WiHorrite_Check(cb, ky ,kx);		
		}
	}

	if(cb->board[kx-1][ky]->isEmpty==0){
		if((kx-1)>=0){
			kempty++;
			WiHorleft_Check(cb, ky, kx);		
		}
	}
	
	if(cb->board[kx][ky+1]->isEmpty==0){
		if((ky+1)<=7){
			kempty++;
			WiVertup_Check(cb, ky, kx);
		}
	}
	
	if(cb->board[kx][ky-1]->isEmpty==0){
		if((ky-1)>=0){
			kempty++;		
			WiVertdown_Check(cb, ky, kx);
		}
	}
	
	
	if(cb->board[kx+1][ky+1]->isEmpty==0){
		if(((kx+1)<=7)||((ky+1)<=7)){
			kempty++;
			WiDiagUpRt_Check(cb, kx, ky);
		}
	}
	
	if(cb->board[kx+1][ky-1]->isEmpty==0){
		if(((kx+1)<=7)||((ky-1)>=0)){
			kempty++;
			WiDiagDownRt_Check(cb, kx, ky);
		}
	}
	
	if(cb->board[kx-1][ky+1]->isEmpty==0){
		if(((kx-1)>=0)||((ky-1)>=0)){
			kempty++;
			WiDiagUpLft_Check(cb, kx,ky);
		}
	}
	
	if(cb->board[kx-1][ky-1]->isEmpty==0){
		if(((kx-1)>=0)||((ky+1)<=7)){
			kempty++;
			WiDiagDownLft_Check(cb, kx, ky);			
		}
	}	
	Winite_check(cb,kx,ky);
	check=upcheck+downcheck+leftcheck+ritecheck+uprtcheck+uplftcheck+drtcheck+dlftcheck+nitecheck;
	if(check==kempty){
		checkmate=1;
		return checkmate;
	}
	//if checkmate=1, king is in checkmate
	return check; //if check is greater than 1, king is in check
}

int WiVertup_Check(ChessBoard*cb,int kx, int ky){
	//check back and front for queen and rook
	int upcheck;
	for(int j=ky;j<=6;j++){
		if(cb->board[kx][j+1]->type==QUEEN&&cb->board[kx][j+1]->color==BLACK){
			upcheck=1;
		}else if(cb->board[kx][j+1]->type==ROOK&&cb->board[kx][j+1]->color==BLACK){
			upcheck=1;
		}else{
			upcheck=0;
		}	
	}
	return upcheck;
}
int WiVertdown_Check(ChessBoard*cb,int kx, int ky){
	int downcheck;		
	for(int j=ky;j>=1;j--){
		if(cb->board[kx][j-1]->type==QUEEN&&cb->board[kx][j-1]->color==BLACK){
			downcheck=1;
		}else if(cb->board[kx][j-1]->type==ROOK&&cb->board[kx][j-1]->color==BLACK){
			downcheck=1;
		}else{
			downcheck=0;
		}	
	}
	return downcheck;
}

int WiHorrite_Check(ChessBoard*cb,int kx, int ky){
	//check left or right for queen and rook
	int ritecheck;
	for(int i=kx;i<=6;i++){
		if(cb->board[i+1][ky]->type==QUEEN&&cb->board[i+1][ky]->color==BLACK){
			ritecheck=1;
		}else if(cb->board[i+1][ky]->type==ROOK&&cb->board[i+1][ky]->color==BLACK){
			ritecheck=1;
		}else{
			ritecheck=0;
		}
	}	
	return ritecheck;
}
int WiHorleft_Check(ChessBoard*cb,int kx, int ky){
	int leftcheck;
	for(int i=kx;i>=1;i--){
		if(cb->board[i-1][ky]->type==QUEEN&&cb->board[i-1][ky]->color==BLACK){
			leftcheck=1;
		}else if(cb->board[i-1][ky]->type==ROOK&&cb->board[i-1][ky]->color==BLACK){
			leftcheck=1;
		}else{
			leftcheck=0;
		}
	}
	return leftcheck;
}

int WiDiagUpRt_Check(ChessBoard*cb, int kx, int ky){	
	//check diagonals for bishop and queen
	int uprtcheck;
	for(int h=0;h<=7;h++){
		if(((kx+h)>7)||((kx-h)<0)){
			break;
		}else if(((ky+h)<7)||((ky-h<0))){
			break;
		}else if(cb->board[kx+h][ky+h]->type==BISHOP&&cb->board[kx+h][ky+h]->color==BLACK){
			uprtcheck=1;
		}else if(cb->board[kx+h][ky+h]->type==QUEEN&&cb->board[kx+h][ky+h]->color==BLACK){
			uprtcheck=1;
		}else{
			uprtcheck=0;
		}
	}
	return uprtcheck;
}

int WiDiagUpLft_Check(ChessBoard*cb, int kx, int ky){
	int uplftcheck;
        for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx-h][ky+h]->type==BISHOP&&cb->board[kx-h][ky+h]->color==BLACK){
                        uplftcheck=1;
                }else if(cb->board[kx-h][ky+h]->type==QUEEN&&cb->board[kx-h][ky+h]->color==BLACK){
                        uplftcheck=1;
                }else{
                        uplftcheck=0;
                }
        }
	return uplftcheck;
}
	
int WiDiagDownRt_Check(ChessBoard*cb,int kx, int ky){
	int drtcheck;
        for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx+h][ky-h]->type==BISHOP&&cb->board[kx+h][ky-h]->color==BLACK){
                        drtcheck=1;
                }else if(cb->board[kx+h][ky-h]->type==QUEEN&&cb->board[kx+h][ky-h]->color==BLACK){
                        drtcheck=1;
                }else{
                        drtcheck=0;
                }
        }
	return drtcheck;
}

int WiDiagDownLft_Check(ChessBoard*cb, int kx, int ky){
	int dlftcheck;
        for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx-h][ky-h]->type==BISHOP&&cb->board[kx-h][ky-h]->color==BLACK){
                        dlftcheck=1;
                }else if(cb->board[kx-h][ky-h]->type==QUEEN&&cb->board[kx-h][ky-h]->color==BLACK){
                        dlftcheck=1;
                }else{
                        dlftcheck=0;
                }
        }
	return dlftcheck;
}


int Winite_check(ChessBoard*cb,int kx, int ky){
	int nitecheck;
	//check L-shape moves for knight
		//move sideways three spaces first
	
	if(cb->board[kx+2][ky+1]->type==KNIGHT&&cb->board[kx+2][ky+1]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx+2][ky-1]->type==KNIGHT&&cb->board[kx+2][ky-1]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx-2][ky+1]->type==KNIGHT&&cb->board[kx-2][ky+1]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx-2][ky-1]->type==KNIGHT&&cb->board[kx-2][ky-1]->color==BLACK){
		nitecheck=1;
	}
		//move three space vertically first
	if(cb->board[kx+1][ky+2]->type==KNIGHT&&cb->board[kx+1][ky+2]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx+1][ky-2]->type==KNIGHT&&cb->board[kx+1][ky-2]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx-1][ky+2]->type==KNIGHT&&cb->board[kx-1][ky+2]->color==BLACK){
		nitecheck=1;
	}
	if(cb->board[kx-1][ky-2]->type==KNIGHT&&cb->board[kx-1][ky-2]->color==BLACK){
		nitecheck=1;
	}else{
		nitecheck=0;
	}
	return nitecheck;
}

int Black_check_check(ChessBoard*cb){
	//find king position
	int kx=0;
	int ky=0;
	int bcheck=0;
	int kempty=0;
	int bcheckmate=0;
	int bupcheck=0;
	int bdcheck=0;
	int brtcheck=0;
	int blftcheck=0;
	int buprtcheck=0;
	int buplftcheck=0;
	int bdrtcheck=0;
	int bdlftcheck=0;
	int bnitecheck=0;
	for(int x=0;x<=7;x++){ //find king
		for(int y=0;y<=7;y++){
			if(cb->board[x][y]->type==KING&&cb->board[x][y]->color==BLACK){
				kx=x;
				ky=y;
			}
		}
	}
	if(cb->board[kx+1][ky]->isEmpty==0){
		if((kx+1)<=7){
			kempty++;
			BVertup_Check(cb, kx, ky);		
		}
	}			
	
	if(cb->board[kx-1][ky]->isEmpty==0){
		if((kx-1)>=0){
			kempty++;
			BVertdown_Check(cb, kx, ky);
		}
	}
	
	if(cb->board[kx][ky+1]->isEmpty==0){
		if((ky+1)<=7){
			kempty++;
			BHorrite_Check(cb, kx, ky);
		}
	}
	
	if(cb->board[kx][ky-1]->isEmpty==0){
		if((ky-1)>=0){
			kempty++;		
			BHorleft_Check(cb,  kx,  ky);
		}
	}
	
	if(cb->board[kx+1][ky+1]->isEmpty==0){
		if(((kx+1)<=7)||((ky+1)<=7)){
			kempty++;
			BDiagUpRt_Check(cb, kx, ky);
		}
	}
	
	if(cb->board[kx+1][ky-1]->isEmpty==0){
		if(((kx+1)<=7)||((ky-1)>=0)){
			kempty++;
			BDiagUpLft_Check(cb,kx,ky);
		}
	}
	
	if(cb->board[kx-1][ky+1]->isEmpty==0){
		if(((kx-1)>=0)||((ky-1)>=0)){
			kempty++;
			BDiagDownRt_Check(cb,kx,ky);
		}
	}
	
	if(cb->board[kx-1][ky+1]->isEmpty==0){
		if(((kx-1)>=0)||((ky+1)<=7)){
			kempty++;
			BDiagDownLft_Check(cb,kx,ky);
		}
	}
	Bnite_check(cb,kx,ky);
	bcheck=	bupcheck+bdcheck+brtcheck+blftcheck+buprtcheck+buplftcheck+bdrtcheck+bdlftcheck+bnitecheck;
	if(bcheck==kempty){
		bcheckmate=1;
		return bcheckmate;
	}
	return bcheck;
	//return bcheckmate;
}

int BVertup_Check(ChessBoard*cb,int kx, int ky){
	//check back and front for queen and rook
	int bupcheck;
	for(int j=ky;j<=6;j++){
		if(cb->board[kx][j+1]->type==QUEEN&&cb->board[kx][j+1]->color==WHITE){
			bupcheck=1;
		}else if(cb->board[kx][j+1]->type==ROOK&&cb->board[kx][j+1]->color==WHITE){
			bupcheck=1;
		}else{
			bupcheck=0;
		}	
	}
	return bupcheck;
}
int BVertdown_Check(ChessBoard*cb,int kx, int ky){		
	int bdcheck;
	for(int j=ky;j>=1;j--){
		if(cb->board[kx][j-1]->type==QUEEN&&cb->board[kx][j-1]->color==WHITE){
			bdcheck=1;
		}else if(cb->board[kx][j-1]->type==ROOK&&cb->board[kx][j-1]->color==WHITE){
			bdcheck=1;
		}else{
			bdcheck=0;
		}	
	}
	return bdcheck;
}

int BHorrite_Check(ChessBoard*cb,int kx, int ky){
	//check left or right for queen and rook
	int brtcheck;
	for(int i=kx;i<=6;i++){
		if(cb->board[i+1][ky]->type==QUEEN&&cb->board[i+1][ky]->color==WHITE){
			brtcheck=1;
		}else if(cb->board[i+1][ky]->type==ROOK&&cb->board[i+1][ky]->color==WHITE){
			brtcheck=1;
		}else{
			brtcheck=0;
		}
	}
	return brtcheck;
}

int BHorleft_Check(ChessBoard*cb,int kx, int ky){
	int blftcheck;
	for(int i=kx;i>=1;i--){
		if(cb->board[i-1][ky]->type==QUEEN&&cb->board[i-1][ky]->color==WHITE){
			blftcheck=1;
		}else if(cb->board[i-1][ky]->type==ROOK&&cb->board[i-1][ky]->color==WHITE){
			blftcheck=1;
		}else{
			blftcheck=0;
		}
	}
	return blftcheck;	
}	

int BDiagUpRt_Check(ChessBoard*cb,int kx, int ky){	
//check diagonals for bishop and queen
	int buprtcheck;
	for(int h=0;h<=7;h++){
		if(((kx+h)>7)||((kx-h)<0)){
			break;
		}else if(((ky+h)<7)||((ky-h<0))){
			break;
		}else if(cb->board[kx+h][ky+h]->type==BISHOP&&cb->board[kx+h][ky+h]->color==WHITE){
			buprtcheck=1;
		}else if(cb->board[kx+h][ky+h]->type==QUEEN&&cb->board[kx+h][ky+h]->color==WHITE){
			buprtcheck=1;
		}else{
			buprtcheck=0;
		}
	}
	return buprtcheck;		
}

int BDiagUpLft_Check(ChessBoard*cb,int kx, int ky){
        int buplftcheck;
	for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx-h][ky+h]->type==BISHOP&&cb->board[kx-h][ky+h]->color==WHITE){
                        buplftcheck=1;
                }else if(cb->board[kx-h][ky+h]->type==QUEEN&&cb->board[kx-h][ky+h]->color==WHITE){
                        buplftcheck=1;
	        }else{
                        buplftcheck=0;
                }
	}
	return buplftcheck;
}

int BDiagDownRt_Check(ChessBoard*cb,int kx, int ky){
        int bdrtcheck;
	for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx+h][ky-h]->type==BISHOP&&cb->board[kx+h][ky-h]->color==WHITE){
                        bdrtcheck=1;
                }else if(cb->board[kx+h][ky-h]->type==QUEEN&&cb->board[kx+h][ky-h]->color==WHITE){
                        bdrtcheck=1;
                }else{
                        bdrtcheck=0;
                }
        }
	return bdrtcheck;
}

int BDiagDownLft_Check(ChessBoard*cb,int kx, int ky){
        int bdlftcheck;
	for(int h=0;h<=7;h++){
                if(((kx+h)>7)||((kx-h)<0)){
                        break;
                }else if(((ky+h)<7)||((ky-h<0))){
                        break;
                }else if(cb->board[kx-h][ky-h]->type==BISHOP&&cb->board[kx-h][ky-h]->color==WHITE){
                        bdlftcheck=1;
                }else if(cb->board[kx-h][ky-h]->type==QUEEN&&cb->board[kx-h][ky-h]->color==WHITE){
                        bdlftcheck=1;
                }else{
                        bdlftcheck=0;
                }
        }
	return bdlftcheck;
}

int Bnite_check(ChessBoard*cb,int kx, int ky){
//check L-shape moves for knight
		//move sideways three spaces first
	int bnitecheck;
	if(cb->board[kx+2][ky+1]->type==KNIGHT&&cb->board[kx+2][ky+1]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx+2][ky-1]->type==KNIGHT&&cb->board[kx+2][ky-1]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx-2][ky+1]->type==KNIGHT&&cb->board[kx-2][ky+1]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx-2][ky-1]->type==KNIGHT&&cb->board[kx-2][ky-1]->color==WHITE){
		bnitecheck=1;
	}
		//move three space vertically first
	if(cb->board[kx+1][ky+2]->type==KNIGHT&&cb->board[kx+1][ky+2]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx+1][ky-2]->type==KNIGHT&&cb->board[kx+1][ky-2]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx-1][ky+2]->type==KNIGHT&&cb->board[kx-1][ky+2]->color==WHITE){
		bnitecheck=1;
	}
	if(cb->board[kx-1][ky-2]->type==KNIGHT&&cb->board[kx-1][ky-2]->color==WHITE){
		bnitecheck=1;
	}else{
		bnitecheck=0;
	}	
	return bnitecheck;
}



#ifdef DEBUG
int main()
{
    ChessBoard* cb = createChessBoard();
    Chess* che = createChess(PAWN, BLACK);
    setPosition(cb, che, 4, 6);
    Chess* che1 = createChess(QUEEN, WHITE);
    setPosition(cb, che1, 3, 5);
    Chess* che2 = createChess(QUEEN, WHITE);
    setPosition(cb, che2, 5, 5);

    displayBoard(cb);
    displayPossibleMoves(cb, 4, 6);

    printf("%d\n", check_valid_move_logic(cb, 'e', 7, 'a', 7));
}
#endif
