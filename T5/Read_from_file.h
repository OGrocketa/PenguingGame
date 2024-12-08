#include <stdio.h>
#include <stdlib.h>
#ifndef __READFROMFILE_H
#define __READFROMFILE_H

struct read Read_from_file();
/*
Reads a .txt file, stores the boards value, the size,
the player's id, his number, and his score
Returns a struct containing:
int dim_x: x board's dimension
int dim_y: y board's dimension
int score:  current player's score
char* player_id:    current player's id
int number_player:  current player's number
char*** board: current board
*/

int check_input_mistakes(int players, int penguins, char phase, struct read charged);
/*
Check for possible mistakes in the input .txt file
int players: number of players
int penguins: penguins per player
char phase: 'p' for placement, 'm' for movement
struct read charged: struct with board's dimensions and values,
player_id, score and player's number
*/

#endif
