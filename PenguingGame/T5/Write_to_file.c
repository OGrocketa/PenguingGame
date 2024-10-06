#include<stdio.h>
#include <stdlib.h>

struct write{
int dim_x;
int dim_y;
int *score;
char**player_id;
int*number_player;
char*** board;
};struct write Write;

void WriteToFile(struct write Write, int player_amount){
        FILE* file;
        file = fopen("inputboard.txt","w");
        fprintf(file,"%d %d",Write.dim_x,Write.dim_y);
        fputs("\n",file);
        for(int r = 0; r < Write.dim_x; r++){
            for(int c = 0; c < Write.dim_y; c++){
                fprintf(file,"%c%c ", Write.board[r][c][0],Write.board[r][c][1]);
            }
            fprintf(file,"\n");
        }
        for (int i = 0; i < player_amount; i++)
        {
            fprintf(file,"%s %d %d\n",Write.player_id[i],Write.score[i],Write.number_player[i]);
        }
        
    }
