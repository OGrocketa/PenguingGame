#include <stdio.h>

char ** generate_board(int dim_x, int dim_y, int penguins);
/*
Creates a 2d array and randomly fills it with values up to 3 according to guidelines based on the number of penguins and board dimensions

Int dim_x - number of rows previously input by player
Int dim_y - number of columns previously input by player
Int penguins - number of penguins previously input by player

Returns the created board
*/ 


void place_penguin(int dim_board_r, int dim_board_c,char *board[dim_board_r][dim_board_c],int row, int column,int current_player){
    if(current_player==1){
        board[row][column]= "A";
    }
    else board[row][column]= "B";
}
/*
If current player==1, changes value of the floe with x,y coordinates to "A".
If current player==2, changes value of the floe with x,y coordinates to "B"
int dim_board_r, int dim_board_c- row/column sizes of the board array
int row,column - row,column coordinates of the penguin
current player - number of the current player
*/

void remove_fish_and_delete_floe(int dim_board_r, int dim_board_c,char *board[dim_board_r][dim_board_c],int previous_row_of_peng, int previous_column_of_peng){
    board[previous_row_of_peng][previous_column_of_peng] = "-";
}
/*
Floe value chnages to "-"
int dim_board_r,int dim_board_c - row/column sizes of the board array
char *board[dim_board_r][dim_board_c] - pointer to a board array
int previous_row_of_peng, int previous_column_of_peng - previous row/cplumn coordinates of the penguin
*/


void switch_player(int *current_player)
{
    if (*current_player==1)
        *current_player=2;
    else *current_player=1;
}
/*
changes the player who makes the move
int *current_player - pointer to the number of the current player
*/


void move_penguin (int new_x, int new_y, int *fish, int *x, int *y);
/*
Moves chosen penguin from old x,y coordinates to new_x,new_y coordinates provided by the player and saves amount of the fish of the new floe.
new_x, new_y - coordinates for new placement of the penguin
*fish - pointer to the amount of the fish on the floe
*x,*y - pointers to the old coordinates of the penguin
*/












