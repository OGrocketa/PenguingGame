#include <stdio.h>
#include <stdbool.h>
#include "InputOutput.h"
#include "Operations.h"
#include "Check.h"



int main()
{
    int dim_x, dim_y; /*Coordinates for x and y dimensions*/
    int x, y;
    int pen_x, pen_y;
    int fish=1;
    int number_penguins;
    int score1=0, score2=0;
    int current_player=2;
    int penguins_placed=0;
    char **board;
    //game setup
    do{
        ask_number_penguins_and_board_dimensions(&number_penguins, &dim_x, &dim_y);
    } while(check_number_penguins_and_board_dimensions(number_penguins, dim_x, dim_y)==0);

    board = generate_board(dim_x, dim_y, number_penguins);
    //placement phase
    printf("\n\t--Placement Phase--\n");
    while (check_any_penguins_left_to_place(number_penguins, &penguins_placed)==1)
    {
        if (check_board(board, dim_x, dim_y)==0)
        {
            printf(" *The board ran out of valid tiles*\n");
            printf(" adjust the board dimensions and/or number of penguins for more consistent generation\n");
            return 0;
        }
            switch_player(&current_player);
            do{
                show_board(board, dim_x, dim_y);
                ask_for_coordinates(&x, &y);
            }while(check_placement_coordinates(board, dim_x, dim_y, x, y)==0);
            place_penguin(board, x, y, current_player);
            update_score(fish, current_player, &score1, &score2);
    }
    //movement phase
    printf("\n\t--Movement Phase--\n\n");
    while (check_any_valid_moves_left(board, dim_x, dim_y)==1)
    {
        switch_player(&current_player);
        if (check_current_player_has_moves(board, dim_x, dim_y, current_player)==0)
        {
            printf("This player can no longer make any valid moves\n");
            continue;
        }
        show_board(board, dim_x, dim_y);
            do{
                do{
                    ask_which_penguin_to_move(&pen_x, &pen_y);
                }while(check_if_penguin_can_move(board, dim_x, dim_y, pen_x, pen_y)==0);
                ask_for_coordinates(&x, &y);
            }while (check_if_move_is_valid(board, dim_x, dim_y, pen_x, pen_y, x, y)==0);
            move_penguin(board, x, y, current_player, &fish);
            update_score(fish, current_player, &score1, &score2);
            show_score(score1, score2);
            remove_fish_and_delete_floe(board, pen_x, pen_y);

    }
    announce_winner(score1, score2);
    return 0;
}
