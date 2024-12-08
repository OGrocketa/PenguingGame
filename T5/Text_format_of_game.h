#ifndef __TEXTFORMATOFGAME.H
#define __TEXTFORMATOFGAME.H

void WriteBoardToFile(char **board, int dim_x, int dim_y,char* player1_name, char* player2_name, int player1_score, int player2_score);
/*
Writes board, players nicknames, players numbers and players scores to the txt file

char** board - pointer to the board
dim_x,dim_y - row,column dimensions of the board
char* player1_name, char* player2_name - pointers to the player 1 and player 2 nicknames
int player1_score, int player2_score - scores of player 1 and player 2
*/
#endif
