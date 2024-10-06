#include "Text_format_of_game.h"
#include <stdio.h>

void WriteBoardToFile(char **board, int dim_x, int dim_y,char* player1_name, char* player2_name, int player1_score, int player2_score){
    FILE* file;
    file = fopen("game.txt","w");
    fprintf(file,"%d %d",dim_x,dim_y);
    fputs("\n",file);
    for (int i = 0; i < dim_x; i++)
    {
        for ( int j = 0; j < dim_y; j++)
        {
            if (board[i][j]== 'A')
            {
                fprintf(file,"01 ");
            }
            else if (board[i][j]== 'B')
            {
                fprintf(file,"02 ");
            }
            else
                fprintf(file, "%c0 ",board[i][j]);
        }
        fputs("\n",file);
        
    }
    fprintf(file,"%s 1 %d\n",player1_name,player1_score);
    fprintf(file,"%s 2 %d\n",player2_name,player2_score);

    
}
