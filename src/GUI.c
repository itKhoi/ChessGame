/*GUI.c file by Hayley Sperber*/
//edited by Samuel Wong and Hayley Sperber

#include "GUI.h"
#include <gtk/gtk.h>
#include "string.h"


int main(int argc, char *argv[]){
        char str[MAX_MSGLEN];

        gtk_init(&argc, &argv);
        ResetBoard();

        /*new window*/
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
        gtk_widget_set_size_request(window, WINDOW_WIDTH, WINDOW_HEIGHT) ;
        gtk_container_set_border_width (GTK_CONTAINER(window), WINDOW_BORDER) ;
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER) ;
        gtk_window_set_title(GTK_WINDOW(window), "Chess Program") ;
        gtk_window_set_resizable(GTK_WINDOW(window), FALSE) ;

}
enum GRID Board[8][8];

void InitBoard(){
	

}
void ResetBoard(){
	for(int i=0;i<=7;i++){
		for(int j=0;j<=7;j++){
			if((i+j)%2==1){
				Board[i][j]=WHITE;
			}else if((i+j)%2==0){
				Board[i][j]=BLACK;
			}
		}
	}
}

//need to figure out how to identify piece being moved
void Move(Che*cb, int from_x, int from_y, int to_x, int to_y){ //how to distinguish between black and white piece
	if(che->type==KING){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=KING;
	}
	else if(che->type==QUEEN){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=QUEEN;
	}
	else if(che->type==ROOK){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=ROOK;
	}
	else if(che->type==KNIGHT){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=KNIGHT;
	}
	else if(che->type==BISHOP){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=BISHOP;
	}
	else if(che->type==PAWN){
		Board[from_x][from_y]=0;
		Board[to_x][to_y]=PAWN;
	}
}

void DrawChessBoard(){
        int i, j;

        for(i = 0; i < 7; i ++){
                for(j = 0; j < 7; j ++){
                        switch(Board[i][j]){
                                case BLACK:
                                        chess_icon = gtk_image_new_from_file("./chess_icon/Bsquare.jpg");
                                        break;
                                case WHITE:
                                        chess_icon = gtk_image_new_from_file("./chess_icon/Wsquare.jpg");
                                        break;
                                case KING:
                                        chess_icon = gtk_image_new_from_file("./chess_icon/WKing.jpg");
                                        break;
                                case QUEEN:
                                        chess_icon = gtk_image_new_from_file("");
                                        break;
                                case BISHOP:
                                        chess_icon = gtk_image_new_from_file("");
                                        break;
                                case KNIGHT:
                                        chess_icon = gtk_image_new_from_file("");
                                        break;
                                case ROOK:
                                        chess_icon = gtk_image_new_from_file("");
                                        break;
                                case PAWN:
                                        chess_icon = gtk_image_new_from_file("");
                                        break;
                                default:
                                        break;

                                /*if (x,y) = some position white otherwise black*/

                        }
                        gtk_table_attach(GTK_TABLE(table), chess_icon, i, i + 1, j, j + 1, GTK_FILL, GTK_FILL, 0, 0) ;
                }
        }
}

void CoordToGrid(int c_x, int c_y, int *g_x, int *g_y)
{
        *g_x = (c_x - BOARD_BORDER) / SQUARE_SIZE;
        *g_y = (c_y - BOARD_BORDER) / SQUARE_SIZE;
}

static gboolean
on_delete_event (GtkWidget *widget,
         GdkEvent  *event,
         gpointer   data)
{
  /* If you return FALSE in the "delete_event" signal handler,
 *    * GTK will emit the "destroy" signal. Returning TRUE means
 *       * you don't want the window to be destroyed.
 *          *
 *             * This is useful for popping up 'are you sure you want to quit?'
 *                * type dialogs.
 *                   */

  g_print ("delete event occurred\n");
  gtk_main_quit();
  return TRUE;
}

gint area_click (GtkWidget *widget,
                 GdkEvent  *event,
                 gpointer  data)
{
  int x1, y1 ;
  char words[MAX_MSGLEN] ;

  int coord_x, coord_y, grid_x, grid_y;

  struct BOARD *chess_board ;
  struct SQUARE *chess_piece ;
  struct SQUARE *piece_dest ;

  GdkModifierType state ;

  gdk_window_get_pointer(widget->window, &coord_x, &coord_y, &state) ;

  CoordToGrid(coord_x, coord_y, &grid_x, &grid_y);

  printf("coord_x = %d, coord_y = %d, grid_x = %d, grid_y = %d \n", coord_x, coord_y, grid_x, grid_y);

  MoveTheKing(grid_x, grid_y);


    gtk_container_remove(GTK_CONTAINER(window), fixed) ;
    table = gtk_table_new (2, 2, TRUE) ;
    gtk_widget_set_size_request (table, BOARD_WIDTH, BOARD_HEIGHT) ;
    DrawBoard();

    /*set fixed*/

    fixed = gtk_fixed_new() ;
    gtk_fixed_put(GTK_FIXED(fixed), table, 0, 0) ;
    gtk_container_add(GTK_CONTAINER(window), fixed) ;
    gtk_widget_show_all(window) ;

  return TRUE ;
}




}



