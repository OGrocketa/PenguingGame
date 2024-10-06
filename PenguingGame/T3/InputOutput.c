# include <stdio.h>
# include "InputOutput.h"

int dim_x, dim_y; //board's dimensions
int x, y; // variables for penguin coordinates
int current_player; //chosen player
int penguin; //chosen penguin

int ask_number_penguins_and_board_dimensions()
{
    int number_penguins; //number of penguins
    printf("Input number of penguins between 2 and 5 \n");
    scanf("%d", &number_penguins);
    printf("Input coordinates for x and y dimensions between 5 and 20\n");
    scanf("%d", &dim_x);
    scanf("%d", &dim_y);
    return number_penguins;
}

void show_board(char** board) {   
    for (int i = 0; i < dim_x; i++){
        for(int j = 0; j< 2*dim_y; j++){
            printf("%c", board[i][j]);
    }
    printf("\n");
}
printf("\n\n");
}

void ask_for_coordinates()
{
    printf("Provide the x and y coordinates:\n");
    scanf("%d", &x);
    scanf("%d", &y);
}

void update_score(int current_player, int sumPoints, int *score1, int *score2)
{
    if(current_player==1){
        if(sumPoints==1){
            *score1= *score1+1;
        }else if(sumPoints==2){
            *score1=*score1+2;
        }else{
            *score1=*score1+3;
        }    
    }else{
        if(sumPoints==1){
            *score2=*score2+1;
        }else if(sumPoints==2){
            *score2=*score2+2;
        }else{
            *score2=*score2+3;
        }
    }
    printf("\t--Score--\nPlayer1: %d\nPlayer2: %d\n", *score1, *score2);
}


int ask_which_penguin_to_move(int number_penguins)
{   
    do{
        printf("Provide which penguin to move:\n");
        scanf("%d", &penguin);
        if(penguin > number_penguins){
            printf("Incorrect argument, try again\n");
        }
    }while(penguin > number_penguins);
    return penguin;
}

void announce_winner(int *score1, int *score2)
{
    printf("\t--The game has ended--\n");
    if (*score1>*score2)
        printf("Player 1 has won!\n");
    else if (*score2>*score1)
        printf("Player 2 has won!\n");
        else printf("The game resulted in a draw!\n");
}
