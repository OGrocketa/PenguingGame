#indef __WRITETOFILE_H
#define __WRITETOFILE_H

void WriteToFile(struct write Write, int player_amount);
/*
Writes to file board dimensions, the board with amount of fish/players positioning data, players nicknames,their numbers and scores
struct write Write: 
    Write.board = char*** board;
    Write.dim_x = x dimension of the board;
    Write.dim_y = y dimension of the board;
    Write.player_id = player_id;
    Write.score = score;
    Write.number_player = numberofpl;
char*** board - pointer to the 2d array of the board
int dim_x,dim_y - dimensions of the board
char** player_id - pointer to the array of players id's
int* score - pointer to the array of scores of players
int* players_numbers - pointer to the array of players numbers
int player_amount - amount of players in the game
*/

#endif
