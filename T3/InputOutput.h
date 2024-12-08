# include <stdio.h>

int ask_number_penguins_and_board_dimensions();
/*
Asks player number of penguins and board's dimensions
Stores board's width and heigh in 
dim_x and dim_y respectively 
returns number of penguins
*/

void show_board(char board[dim_x][dim_y]);
/*
Displays the current board
char board: array which contains the current board's value 
*/

void ask_for_coordinates();
/*
Asks player for the coordinates to move the penguin
Stores the horizontal and vertical dimensions of the chosen  
field in variables x and y respectively
*/

void update_score(int sumPoints, int *score1, int *score2);
/*
Updates the value of one player's scorer depending on wich one is selected
in 1, 2 or 3 points
Displays the scorer of each player
int sumPoints: parameter which indicates how many points do we have to sum to the scorer
int *score1: pointer to player's 1 scorer
int *score2: pointer to player's 2 scorer
*/

int ask_which_penguin_to_move(int number_penguins);
/*
Asks current player which penguin to move,
then if the chosen penguin does not exist for ex: chosen
penguin is 7 and there are only 3, it repeats the  operation
return wich penguin is the choosen
int number_penguins: value of number of penguins needed to check that the chosen 
penguin exists
*/

void announce_winner(int *score1, int *score2);
/*
Inform the game ended, and depending of the scorers prints the winner
or if there is a draw
int *score1: pointer to player's 1 scorer
int *score2: pointer to player's 2 scorer
*/

