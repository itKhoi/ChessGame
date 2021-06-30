//
// 1/28/2019
//

#include "AI.h"
#include <assert.h>
#include <time.h> 

//Initial moves are random. No need for the thinky
void bestMove(ChessBoard* cb, int AIcolor){
	static int lemon = 8;
	
if(lemon>0){
	int valid = 0;
	int fx,fy;
	int d;
	int dx;
	if (AIcolor ==1){
		fx = 2;
		dx = 1;
	}else{
		fx = 7;
		dx = -1;
	}
	while(valid != 1){
		srand(time(0));
		fy = rand();
		d = rand();
    //Pick a random location
		fy = fy%8;
		d = (d%2)+1;
    //Make sure that piece selected randomly is not the players piece
    //Check if piece and color passed into AI are the same color
	valid = check_valid_move(cb,fy,fx-1,fy,fx+(dx*d)-1);
	//printf("Entropy coordinates %d %d %d %d\n",fy,fx-1,fy,fx+(dx*d)-1);
	//printf("Khoi    coordinates %d %d %d %d\n",fx,fy,fx+(dx*d),fy);
	//printf("%d\n",valid);
 }
	fy += 97;
	movement(cb,fx,fx+(dx*d),fy,fy);

	lemon--;
}else{
  int move;

	//AI will prioritize killing pieces
  //First search if a piece can move to a location with an an enemy piece
  //Then check if it is valid
  
  //Call function to see if AI is in check

    move = notInCheck(cb,AIcolor);
	printf("%d\n",move);
	printf("Khoi Coordinates %d %d %d %d\n",8-decodefx(move),decodefy(move),8-decodetx(move),decodety(move));
    movement(cb,8-decodefx(move),8-decodetx(move),decodefy(move),decodety(move));
  
}	

}//End of best move function

int notInCheck(ChessBoard* cb, int AIcolor){
  int fx,fy,tx,ty;
  int i,j;
  //Scan board for a piece of the same color as the AI
  int bestMoveScore = 0;
  int tempMoveScore;
  
  	
  
  for(i = 0; i<8;i++){
    for(j = 0; j<8; j++){
      if(cb->board[i][j]->color == AIcolor){
        if(cb->board[i][j]->type == PAWN){
          tempMoveScore = scorePawnCapture(cb,i,j,AIcolor);
          if(decodeScore(tempMoveScore)>decodeScore(bestMoveScore)){
			printf("Move score updated by Pawn\n");
            bestMoveScore = tempMoveScore;
          }
        }
        if(cb->board[i][j]->type == ROOK){
          tempMoveScore = scoreRookCapture(cb,i,j,AIcolor);
          if(decodeScore(tempMoveScore)>decodeScore(bestMoveScore)){
			printf("Move score updated by Rook\n");
            bestMoveScore = tempMoveScore;
          }
        }
        if(cb->board[i][j]->type == BISHOP){
          tempMoveScore = scoreBishopCapture(cb,i,j,AIcolor);
          if(decodeScore(tempMoveScore)>decodeScore(bestMoveScore)){
			  printf("Move score updated by Bishop\n");
            bestMoveScore = tempMoveScore;
          }
        }
        
        if(cb->board[i][j]->type == QUEEN){
          tempMoveScore = scoreQueenCapture(cb,i,j,AIcolor);
          if(decodeScore(tempMoveScore)>decodeScore(bestMoveScore)){
			  printf("Move score updated by Queen\n");
            bestMoveScore = tempMoveScore;
          }
        }
        if(cb->board[i][j]->type == KNIGHT){
          tempMoveScore = scoreKnightCapture(cb,i,j,AIcolor);
          if(decodeScore(tempMoveScore)>decodeScore(bestMoveScore)){
			  printf("Move score updated by Knight\n");
            bestMoveScore = tempMoveScore;
          }
        }
      }
    }
  }
  
  if(bestMoveScore == 0){
	  printf("Now finding random valid move\n");
    int valid = 0;
	  while(valid != 1){
  		srand(time(0));
  		fx = rand();
  		fy = rand();
      //Pick a random location
  		fx = fx%8;
  		fy = fy%8;
      //Make sure that piece selected randomly is not the players piece
      //Check if piece and color passed into AI are the same color
      if(cb->board[fx][fy]->color == AIcolor){
      		tx = rand();
  		    ty = rand();
            tx = tx%8;
  		    ty = ty%8;
  		    valid = check_valid_move(cb,fy,7-fx,ty,7-tx);
      }	
   }
   
   printf("Entropy coordinates %d %d %d %d\n",fy,7-fx,ty,7-tx);
   return(fx*1000+fy*100+tx*10+ty);
  }else{
    return(bestMoveScore);  
  }
}

int scoreKnightCapture(ChessBoard* cb, int x, int y, int AIcolor){
    int knight[16]={-2,1,-1,2,1,2,2,1,-2,-1,-1,-2,1,-2,2,-1};
    int knightScore = 0;
    int tempScore;
    int a = 0;
    int b = 0;
    
    int i;
    
    for(i = 0; i<=7;i++){
    if(x+knight[2*i]>7){
        //x coordinate out of bounds. Do nothing here
    }
    else if(x+knight[2*i]<0){
        //x coordinate out of bounds. Do nothing here
    }
    else if(y+knight[2*i+1]>7){
        //y coordinate out of bounds. Do nothing here
    }
    else if(y+knight[2*i+1]<0){
        //y coordinate out of bounds. Do nothing here
    }else{
		if(cb->board[x][y] != cb->board[x+knight[2*i]][y+knight[2*i+1]]){
		  tempScore = appraise(cb,x+knight[2*i],y+knight[2*i+1])-appraise(cb,x,y);
		  if(tempScore == -3){
			tempScore = 0;}
		  if(tempScore<0){
			tempScore = (tempScore+1)*-1;
		  }
		  if(tempScore>knightScore){
			knightScore = tempScore;
			a = x+knight[2*i];
			b = y+knight[2*i+1];
		  } 
		}
    } 
}
return(knightScore*10000+x*1000+y*100+a*10+b);
}

int scoreQueenCapture(ChessBoard* cb, int x, int y, int AIcolor){
  int straightMoveScore;
  int diagonalMoveScore;
  
  straightMoveScore = scoreRookCapture(cb,x,y,AIcolor);
  
  diagonalMoveScore = scoreBishopCapture(cb,x,y,AIcolor);
  
  if(straightMoveScore > diagonalMoveScore){
    return(straightMoveScore);
  }else{
    return(diagonalMoveScore);
  }

}

int scoreBishopCapture(ChessBoard* cb, int x, int y, int AIcolor){
  int bishopScore = 0;
  int tempScore;
  int a,b,inca,incb;
  int f,g;
  
  int i,j;
  
  int cc = 1;
  
  for (i = 1; i<=3; i+=2){
    for(j = 1; j<=3; j+=2){
        cc = 1;
        inca = i -2;
        incb = j -2;
        a = x;
        b = y; 
        while(cc == 1){
          if(check_valid_move(cb,x,y,a,b) == 1){
			if(cb->board[x][y]->color != cb->board[a][b]->color){
				tempScore = appraise(cb,a,b)-appraise(cb,x,y);
				if(tempScore == -3){
				  tempScore = 0;}
				if(tempScore<0){
				  tempScore = (tempScore+1)*-1;
				}
				if(tempScore>bishopScore){
				  bishopScore = tempScore;
				  f = a;
				  g = b;
				}
			}
          }
        }
        a+= inca;
        b+= incb;
        if(a>7){
            cc = 0;}
        if(a<0){
            cc = 0;}
    
        if(b>7){
            cc = 0;}
        if(b<0){
            cc = 0;}
        }
    }
      return(bishopScore*10000+x*1000+y*100+f*10+g);
  }

int scoreRookCapture(ChessBoard* cb, int x, int y, int AIcolor){
  int rookScore = 0;
  int tempScore;
  int a = 0;
  int b = 0;
  int i;
  
  for(i = 0; i<8;i++){
    if(check_valid_move(cb,x,y,i,y) == 1){
		if(cb->board[x][y]->color != cb->board[i][y]->color){
		  tempScore = appraise(cb,i,y)-appraise(cb,x,y);
		  if(tempScore == -5){
			tempScore = 0;}
		  if(tempScore<0){
			tempScore = (tempScore+1)*-1;
		  }
		  if(tempScore > rookScore){
			rookScore = tempScore;
			a = i;
			b = y;
		  }
	    }
    }
  }
  
  for(i = 0; i<8;i++){
    if(check_valid_move(cb,x,y,x,i) == 1){
		if(cb->board[x][y]->color != cb->board[i][y]->color){
		  tempScore = appraise(cb,x,i)-appraise(cb,x,y);
		  if(tempScore == -5){
			tempScore = 0;}
		  if(tempScore<0){
			tempScore = (tempScore+1)*-1;
		  }
		  if(tempScore > rookScore){
			rookScore = tempScore;
			a = x;
			b = i;
		  }
	    }
    }
  }
  
  return(rookScore*10000+x*1000+y*100+a*10+b);
  
}


int scorePawnCapture(ChessBoard* cb, int x, int y, int AIcolor){
  int pawnMovement;
  int a,b;
  //Determine in which direction the pawn can move
  if (AIcolor == BLACK){
    pawnMovement = -1;
  }
  else{
    pawnMovement = 1;
  }
  
  int pawnScore= 0;
  
  if (y==0){
    //Do not check left diagonal movement because it is out of bounds
    //Check if right diagonal movement can capture a piece
    if(check_valid_move(cb,x,y,x+pawnMovement,y+1) == 1){
      //If can capture a piece, min max the piece the pawn kills
      if(appraise(cb,x+pawnMovement,y+1)-appraise(cb,x,y) > pawnScore){
        pawnScore = appraise(cb,x+pawnMovement,y+1)-appraise(cb,x,y);
        return(pawnScore*10000+x*1000+y*100+(x+pawnMovement)*10+y+1);
        }
      }
    }else if(y==7){
    //Do not check right diagonal movement because it is out of bounds
    //Check if right diagonal movement can capture a piece
    if(check_valid_move(cb,x,y,x+pawnMovement,y-1) == 1){
      //If can capture a piece, min max the piece the pawn kills
      if(appraise(cb,x+pawnMovement,y-1)-appraise(cb,x,y) > pawnScore){
        pawnScore = appraise(cb,x+pawnMovement,y-1)-appraise(cb,x,y);
        return(pawnScore*10000+x*1000+y*100+(x+pawnMovement)*10+y-1);
        }
      }
  }else{//Check the diagonals of the pawn movement
  
      if(check_valid_move(cb,x,y,x+pawnMovement,y+1) == 1){
      //If can capture a piece, min max the piece the pawn kills
        if(appraise(cb,x+pawnMovement,y+1)-appraise(cb,x,y) > pawnScore){
          pawnScore = appraise(cb,x+pawnMovement,y+1)-appraise(cb,x,y);
          a = x+pawnMovement;
          b = y+1;
          }
        }
      if(check_valid_move(cb,x,y,x+pawnMovement,y-1) == 1){
        //If can capture a piece, min max the piece the pawn kills
        if(appraise(cb,x+pawnMovement,y-1)-appraise(cb,x,y) > pawnScore){
          pawnScore = appraise(cb,x+pawnMovement,y-1)-appraise(cb,x,y);
          a = x+pawnMovement;
          b = y-1;
          }
        }
  }
  return(pawnScore*10000+x*1000+y*100+a*10+b);
}



int appraise(ChessBoard* cb, int x, int y){
  if (cb->board[x][y]->type == PAWN){
    return 1;
  }
  if (cb->board[x][y]->type == KNIGHT){
    return 3;
  }
  if (cb->board[x][y]->type == BISHOP){
    return 3;
  }
  if (cb->board[x][y]->type == ROOK){
    return 5;
  }
  if (cb->board[x][y]->type == QUEEN){
    return 9;
  }
  
  else{
    return 0;
  }
}



int decodeScore(int x){
  return(x%10000);

}

int decodefx(int x){
  return((x/1000)%10);

}

int decodefy(int x){
  return((x/100)%10);
}

int decodetx(int x){
  return((x/10)%10);

}

int decodety(int x){
  return(x%10);
}
