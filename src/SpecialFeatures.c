//
// Created by David Yao on 2019-01-27.
// Editied by Hayley Sperber
//test
#include "SpecialFeatures.h"

void Timer(){
    /*clock_t start = clock(), diff;
    ProcessIntenseFunction();
    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds", msec/1000, msec%1000);*/
	/*int time = 300;*/
	
/*	printf("Timer activated. You have 5 minutes starting now!\n");

	for(int i = 300; i > 0; i--){
		if(i == 240){
			printf("You have 4 minutes remaining!\n");
		}else if(i == 180){
			printf("You have 3 minutes remaining!\n");
		}else if(i == 120){
			printf("You have 2 minutes remaining!\n");
		}else if(i == 60){
			printf("You have 1 minute remaining!\n");
		}else if(i == 30){
			printf("You have 30 seconds remaining!\n"); 
		}else if(i == 10){
			printf("You have 10 seconds remaining!\n");
		}
	}
	printf("Time is up!");*/
     int i;
     while(i != 0)
    {
       // min = i/60;
      //  sec = i%60;
       // printf(" There are %d minutes and %d seconds left" , min, sec);
       printf("\n\n\n\t%d", i);
        i--;
        sleep(1);
        system("clear");
    }
    return 0;
}

Hints()
{
   char Logic_fx = 'a', Logic_tx = 'a';
   int Logic_fy = 1, Logic_ty = 1;
   int difficulty;
   int valid = 0;
   char hints = 'y';
   int HintNum = 3; //3 hints for intermediater mode
  /*Hint could be the first valid move or the best move depends on the difficulty*/
	/*Beginner mode*/
   if((difficulty == 1) || (difficulty == 2))
     {
       printf("Do you need any hint? y/n");
       scanf("%d",&hints);
       }
   else break;
   if((difficulty == 1)&&((hints == 'y' )||(hints == 'Y'))){
                /*# of hints is unlimited*/        
                   do {
                        valid = 0;
	                    	srand(time(0));
	                     	int fx = rand();
	                    	int fy = rand();
                        //Pick a random location
	                    	fx = fx%8;
	                    	fy = fy%8;               
                        if(cb->board[fx][fy]->color == color)
                        {
    	                 	  int tx = rand();
		                      int ty = rand();
                          tx = tx%8;
		                      ty = ty%8;
		                      valid = check_valid_move(cb,fx,fy,tx,ty);
                        }	
                      } while (valid == 0)               
                }
        /*Intermediate mode*/
   else if((difficulty == 2)&&((hints == 'y' )||(hints == 'Y'))){
                /*3 hints available*/
                /*otherwise print error message "No more hints available."*/
                if(HintNum > 0)
                {             
                // check color, type, and then provide the first valid move
	                  valid = 0;
	                  while(valid == 0)
                      {
	                    	srand(time(0));
	                     	int fx = rand();
	                    	int fy = rand();
                        //Pick a random location
	                    	fx = fx%8;
	                    	fy = fy%8;               
                        
                        if(cb->board[fx][fy]->color == color)
                        {
    	                 	  int tx = rand();
		                      int ty = rand();
                          tx = tx%8;
		                      ty = ty%8;
		                      valid = check_valid_move(cb,fx,fy,tx,ty);
                        }	
                      }                             
                 HintNum--;             
                }
                else 
                {
                    printf("You have no more hint. Good luck!\n");
                    break;                
                }}
    else break;         // input 'n', exit    
        }
        Logic_fx = (char)(fx + 49);
        Logic_fy = fy + 1;
        Logic_tx = (char)(tx + 49);
        Logic_ty = ty + 1;
        printf("Hints: %c%d %c%d",&Logic_fx, &Logic_fy, &Logic_tx, Logic_ty);
}

