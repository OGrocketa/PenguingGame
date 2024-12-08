#include <stdio.h>
#include <stdbool.h>

int number_penguins;
int dim_x, dim_y; /*Coordinates for x and y dimensions*/
int x, y;
int fish;
int penguin;
int score1=0, score2=0;
int current_player=1;

void ask_number_penguins_and_board_dimensions()
{
    printf("Input number of penguins between 2 and 5 \n");
    scanf("%d", &number_penguins);
    printf("Input coordinates for x and y dimensions between 5 and 20\n");
    scanf("%d", &dim_x);
    scanf("%d", &dim_y);
}

bool check_number_penguins_and_board_dimensions()
{
    if (number_penguins < 2 || number_penguins > 5){
        printf("Input values are incorrect\n");
        return 0;
    }
    if (dim_x<5 || dim_x>20 || dim_y<5 || dim_y>20)
     {
        printf("Input values are incorrect\n");
        return 0;
     }
     return 1;
}

void generate_board()
{

}

bool any_penguins_left()
{

}

bool check_board()
{

}

bool check_current_player_has_penguins()
{

}

void show_board()
{

}

int ask_for_coordinates()
{
    printf("Provide the x and y coordinates:\n");
    scanf("%d", &x);
    scanf("%d", &y);
}

bool check_coordinates()
{

}

void place_penguin()
{

}

void update_score()
{

}

void remove_fish()
{

}

void switch_player()
{
    if (current_player==1)
        current_player=2;
    else current_player=1;
}

void display_score()
{
    printf("\t--Score--\nPlayer1: %d\nPlayer2: %d\n", score1, score2);
}

bool check_any_valid_moves_left()
{
    return 0; //to avoid an infinite loop (for now)
}

bool check_current_player_has_moves()
{

}

int ask_which_penguin_to_move()
{
    printf("Provide which penguin to move:\n");
    scanf("%d", &penguin);
}

bool check_if_penguin_can_move()
{

}

bool check_if_move_is_valid()
{

}

void move_penguin()
{

}

void remove_ice_floe()
{

}

void announce_winner()
{
    printf("\t--The game has ended--\n");
    if (score1>score2)
        printf("Player 1 has won!\n");
    else if (score2>score1)
        printf("Player 2 has won!\n");
        else printf("The game resulted in a draw!\n");
}

int main()
{   //placement phase
    do{
        ask_number_penguins_and_board_dimensions();
    } while(check_number_penguins_and_board_dimensions()==0);

    generate_board();
    while (any_penguins_left()==1)
    {
        if (check_board()==0)
        {
            printf("the board ran out of valid tiles");
            return 0;
        }
        if (check_current_player_has_penguins()==1)
        {
            do{
                show_board();
                ask_for_coordinates();
            }while(check_coordinates()==0);
            place_penguin();
            update_score();
            remove_fish();
        }
            switch_player();
    }
    //movement phase
    while (check_any_valid_moves_left()==1)
    {
        show_board();
        display_score();
        if (check_current_player_has_moves()==1)
        {
            do{
                do{
                    ask_which_penguin_to_move();
                }while(check_if_penguin_can_move==0);
                ask_for_coordinates();
            }while (check_if_move_is_valid==0);
            move_penguin();
            update_score();
            remove_fish();
            remove_ice_floe();
        }
        switch_player();
    }
    announce_winner();
    return 0;
}
