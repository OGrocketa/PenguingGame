#include <stdio.h>
#include <stdbool.h>
#include "InputOutput.h"
#include "Operations.h"
#include "Check.h"
//char **board; //[5][5] = {"#####","#####","#####","#####","#####"};//just to test



int main()
{
    int dim_x, dim_y; /*Coordinates for x and y dimensions*/
    int x, y;
    int pen_x, pen_y;
    int fish=0;
    int penguin;
    int *score1=0, *score2=0;
    int current_player=1;
    int *penguins_placed=0;
       //placement phase
    do{
        ask_number_penguins_and_board_dimensions();
    } while(check_number_penguins_and_board_dimensions()==0);

    generate_board();
    while (check_any_penguins_left_to_place()==1)
    {
        if (check_board()==0)
        {
            printf("the board ran out of valid tiles");
            return 0;
        }
            do{
                show_board(generate_board()); 
                ask_for_coordinates();
            }while(check_placement_coordinates()==0);
            place_penguin();
            update_score(current_player, fish, score1, score2); 
            switch_player();
    }
    //movement phase
    while (check_any_valid_moves_left()==1)
    {
        show_board(generate_board());
        if (check_current_player_has_moves()==1)
        {
            do{
                do{
                    ask_which_penguin_to_move(); 
                }while(check_if_penguin_can_move==0);
                ask_for_coordinates();
            }while (check_if_move_is_valid==0);
            move_penguin();
            update_score(fish, score1, score2);
            remove_fish_and_delete_floe();
        }
        switch_player();
    }
    announce_winner(score1, score2);
    return 0;
}
