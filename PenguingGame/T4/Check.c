#include "Check.h"

bool check_number_penguins_and_board_dimensions(int number_penguins, int dim_x, int dim_y)
{
    if (number_penguins < 1 || number_penguins > 5 || dim_x < 4 || dim_y < 4 || dim_x > 20 || dim_y > 20)
    {
        printf(" *Incorrect values*\n\n");
        return 0;
    }
    return 1;
}

bool check_board(char **board, int dim_x, int dim_y)
{
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]=='1')
                return 1;
        }
    }
}

bool check_any_penguins_left_to_place(int number_penguins, int *penguins_placed)
{
    if(*penguins_placed>=2*number_penguins)
        return 0;
    else
    {
        *penguins_placed+= 1;
        return 1;
    }
}

bool check_placement_coordinates(char** board, int dim_x, int dim_y, int x, int y)
{
    if(x>=dim_y || y>=dim_x || x<0 || y<0 || board[y][x]!='1')
    {
        printf(" *Selected coordinates are invalid for placement*\n\n");
        return 0;
    }
    return 1;
}

bool check_any_valid_moves_left(char** board, int dim_x, int dim_y)
{
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]=='A' || board[i][j]=='B')
            {
                if(i!=0)
                    if(board[i-1][j]=='3' || board[i-1][j]=='2' || board[i-1][j]=='1')
                        return 1;
                if(i!=dim_x-1)
                    if(board[i+1][j]=='3' || board[i+1][j]=='2' || board[i+1][j]=='1')
                        return 1;
                if(j!=0)
                    if(board[i][j-1]=='3' || board[i][j-1]=='2' || board[i][j-1]=='1')
                        return 1;
                if(j!=dim_y-1)
                    if(board[i][j+1]=='3' || board[i][j+1]=='2' || board[i][j+1]=='1')
                        return 1;
            }

        }
    }
    return 0;
}

bool check_current_player_has_moves(char** board, int dim_x, int dim_y, int current_player)
{
    char letter;
    if(current_player==1)
        letter = 'A';
    else letter = 'B';
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]==letter)
            {
                if(i!=0)
                    if(board[i-1][j]=='3' || board[i-1][j]=='2' || board[i-1][j]=='1')
                        return 1;
                if(i!=dim_x-1)
                    if(board[i+1][j]=='3' || board[i+1][j]=='2' || board[i+1][j]=='1')
                        return 1;
                if(j!=0)
                    if(board[i][j-1]=='3' || board[i][j-1]=='2' || board[i][j-1]=='1')
                        return 1;
                if(j!=dim_y-1)
                    if(board[i][j+1]=='3' || board[i][j+1]=='2' || board[i][j+1]=='1')
                        return 1;
            }

        }
    }
    return 0;
}

bool check_if_penguin_can_move(char** board, int dim_x, int dim_y, int pen_x, int pen_y)
{
    return 1;
}

bool check_if_move_is_valid(char** board, int dim_x, int dim_y, int pen_x, int pen_y, int x, int y)
{
    return 1;
}
