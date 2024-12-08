#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "FileInputOutput.h"


struct read Read_from_file(char* file_name){
    FILE * inputboard = fopen(file_name, "r");
    char aux1;
    int i =0;
    int j = 0;
    int c = 0;
    int m = 0;
    int n=0;
    int value = 0;
    int close = 0;
    struct read Game_state;

    fscanf(inputboard,"%d",&Game_state.dim_x);
    fscanf(inputboard,"%d",&Game_state.dim_y);
    //printf("%d %d\n", Game_state.dim_x, Game_state.dim_y);
 do{
    aux1 =fgetc(inputboard);
    }while(aux1==' ');

    Game_state.board= (char***) malloc(Game_state.dim_x*sizeof(char**));
        for(int k=0; k<Game_state.dim_x; k++)
        {
            Game_state.board[k]= (char**) malloc(Game_state.dim_y*sizeof(char*));
            for(int r = 0; r<Game_state.dim_y; r++){
                Game_state.board[k][r] = (char*) malloc(2*sizeof(char));
            }
        }
    Game_state.player_name=(char**) malloc(9*sizeof(char*));
        for(int f = 0; f < 9; f++){
            Game_state.player_name[f]=(char*)malloc(25*sizeof(char));
        }
    Game_state.player_number=(int*)malloc(9*sizeof(int));
    Game_state.score=(int*)malloc(9*sizeof(int));

    if(inputboard == NULL){
        printf("FILE NOT FOUND");
        exit(3);
    }
    while(c<Game_state.dim_y*Game_state.dim_x){
        value = 0;
                do{
                    aux1 = (char) fgetc(inputboard);
                    if(aux1 == '\n'){
                    i++;
                    j = 0;
                    //printf("\n");
                    }else if(value==1){
                        if(aux1==' ' || aux1 == 13){
                        }else{
                            Game_state.board[i][j][1]= aux1;
                            //printf("%c ",Game_state.board[i][j][1]); //TESTING VALUES
                            value++;
                            j++;
                            }
                        }
                    else if(aux1==' ' || aux1 == 13){
                    }else {
                        Game_state.board[i][j][0]= aux1;
                        //printf("%c",Game_state.board[i][j][0]); //TESTING VALUES
                        value++;
                    }
                }while(value<2);
        c++;
    }
    while(aux1!='\n'){
        aux1 = (char) fgetc(inputboard);
        if (aux1==EOF)
        {
            Game_state.player_name[0][0]='0';
            goto CLOSE;
        }
    }

    //printf("\n");
    do{
        do{
            aux1 = (char) fgetc(inputboard);
            if(aux1==EOF){
                if(m==0 & Game_state.player_number[0]!=1){
                    Game_state.player_name[0][0]='0';//INFORM NOT PLAYERS YET
                }
                goto CLOSE;
            }
            if(aux1 ==13 ||aux1=='\n'){
            }else{
            Game_state.player_name[n][m] = aux1;
            //printf("%c",Game_state.player_name[n][m]);
            }
            m++;
        }while(aux1!=' ');
        fscanf(inputboard,"%d",&Game_state.player_number[n]);
        //printf("\n%d\n",Game_state.player_number[n]);
        fscanf(inputboard,"%d",&Game_state.score[n]);
        //printf("%d\n", Game_state.score[n]);
        n++;
        m=-1;
    //printf("%c",Game_state.player_name[0][0]); //TESTING NOT
    }while(close==0);
CLOSE:
    fclose(inputboard);
    return (Game_state);
}

int check_input_mistakes(int players, int penguins, char phase, struct read Game_state){
    /*phase: p for placement, m for movement*/
    int pen_1=0;
    int pen_2 =0;
    int pen_3=0;
    int pen_4 = 0;
    int pen_5 =0;
    int pen_6=0;
    int pen_7= 0;
    int pen_8=0;
    int pen_9=0;

    for (int i = 0; i<Game_state.dim_x; i++){
        for(int j = 0; j<Game_state.dim_y; j++){
            switch(Game_state.board[i][j][1]){
                case '0':break;
                case '1': pen_1++; break;
                case '2': pen_2++; break;
                case '3': pen_3++; break;
                case '4': pen_4++; break;
                case '5': pen_5++; break;
                case '6': pen_6++; break;
                case '7': pen_7++; break;
                case '8': pen_8++; break;
                case '9': pen_9++; break;
                default: break;
            }
        }
    }
    if(phase=='p'){
        for(int k = 0; k<players; k++){
            if(pen_1>penguins ||pen_2>penguins ||pen_3>penguins
            ||pen_4>penguins ||pen_5>penguins ||pen_6>penguins
            ||pen_7>penguins ||pen_8>penguins ||pen_9>penguins){
                printf("A player exceeds the number of penguins");
                return(2);
            }else if(Game_state.score[k] > penguins){
                printf("A player has more points that it is possible for phase placement");
                return(2);
            }
        }
    }
    /*if(phase=='m'){
        switch (players){
                    case 1: if(pen_1==0){
                                printf("Player with no penguins");
                                return 2;}
                            break;
                    case 2: if(pen_1!=penguins || pen_2!= penguins){
                                printf("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 || pen_2 == 0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 3: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins){
                                printf("Players with different number of penguins 3");
                                return 2;
                            }else if(pen_1==0 || pen_2==0 || pen_3==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 4: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4){
                                printf("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 5: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                    || penguins!=pen_5){
                                printf("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 6: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6){
                                printf("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 7: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7){
                                printf("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 ||pen_7==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 8: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7 || penguins!=pen_8){
                                printf("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 || pen_7==0 ||pen_8==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    case 9: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7 || penguins!=pen_8 || penguins!=pen_9){
                                printf("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 || pen_7==0 ||pen_8==0 || pen_9==0){
                                printf("Player with no penguins");
                                return 2;
                            }break;
                    default:break;
                }

    }*/
            for(int k=0; k<players;k++){
                if(Game_state.score[k]<0){
                printf("There is a negative score");
                return 2;
            }
        }

            for(int k = 0; k<players; k++){
                if(Game_state.player_number[k]<0 || Game_state.player_number[k]>players){
                printf("This player does not exist");
                 return 2;
                }
            }


    for (int i = 0; i < Game_state.dim_x; i++){
        for (int j = 0; j<Game_state.dim_y; j++){
            if(Game_state.board [i][j][0]>51){
                printf("More than three fishes in a tile");
                return(2);
            }else if(Game_state.board [i][j][1]> (players+48)){
                printf("There is a penguin of a player which doesn't exist");
                return (2);
            }
        }
    }

}
void WriteToFile(struct read Write, int player_amount, int current_player, char phase, char* file_name){
        FILE* file;
        file = fopen(file_name,"w");
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

            if(i==player_amount-1 && current_player==player_amount && phase=='p' )
            {
                fprintf(file,"%s %d %d", Write.player_name[i], Write.player_number[i], Write.score[i]);
            }
            else
            {
                fprintf(file,"%s%d %d\n", Write.player_name[i], Write.player_number[i], Write.score[i]);
            }
        }

    }
