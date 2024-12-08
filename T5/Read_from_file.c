#include <stdio.h>
#include <stdlib.h>

struct read{
int dim_x;
int dim_y;
int *score;
char**player_id;
int*number_player;
char*** board;
};


struct read Read_from_file(){
    FILE * inputboard = fopen("inputboard.txt", "r");
    char aux1;
    int i =0;
    int j = 0;
    int c = 0;
    int m = 0;
    int n=0;
    int value = 0;
    int close = 0;
    struct read charged;
    
    fscanf(inputboard,"%d",&charged.dim_x);
    fscanf(inputboard,"%d",&charged.dim_y);
    do{
    aux1 =fgetc(inputboard);
    }while(aux1==' ');
    
    charged.board= (char***) malloc(charged.dim_x*sizeof(char**));
        for(int k=0; k<charged.dim_x; k++)
        {
            charged.board[k]= (char**) malloc(charged.dim_y*sizeof(char*));
            for(int r = 0; r<charged.dim_y; r++){
                charged.board[k][r] = (char*) malloc(2*sizeof(char));
            }
        }
    charged.player_id=(char**) malloc(9*sizeof(char*));
        for(int f = 0; f < 9; f++){
            charged.player_id[f]=(char*)malloc(25*sizeof(char));
        }    
    charged.number_player=(int*)malloc(sizeof(int));   
    charged.score=(int*)malloc(sizeof(int));

    if(inputboard == NULL){
        perror("FILE NOT FIND");
    }
    while(c<charged.dim_y*charged.dim_x){  
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
                            charged.board[i][j][1]= aux1;
                            //printf("%c ",charged.board[i][j][1]); //TESTING VALUES
                            value++;
                            j++;
                            }
                        }    
                    else if(aux1==' ' || aux1 == 13){    
                    }else {
                        charged.board[i][j][0]= aux1;
                        //printf("%c",charged.board[i][j][0]); //TESTING VALUES
                        value++;
                    }
                }while(value<2);
        c++;
    }
    while(aux1!='\n'){
        aux1 = (char) fgetc(inputboard);
    }
    
    //printf("\n");
    do{
        do{
            aux1 = (char) fgetc(inputboard);
            if(aux1==EOF){
                if(m==0){
                    charged.player_id[0][0]='0';//INFORM NOT PLAYERS YET
                }
                close =1;
                goto CLOSE;
            }
            if(aux1 ==13 ||aux1=='\n'){
            }else{
            charged.player_id[n][m] = aux1;
            //printf("%c",charged.player_id[n][m]);
            }    
            m++;
        }while(aux1!=' ');
        fscanf(inputboard,"%d",&charged.number_player[n]);
        //printf("\n%d\n",charged.number_player[n]);
        fscanf(inputboard,"%d",&charged.score[n]);
        //printf("%d\n", charged.score[n]);
CLOSE:
        n++;
    //printf("%c",charged.player_id[0][0]); //TESTING NOT    
    }while(close==0);
    fclose(inputboard);
    return charged;
}

int check_input_mistakes(int players, int penguins, char phase, struct read charged){
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

    for (int i = 0; i<charged.dim_x; i++){
        for(int j = 0; j<charged.dim_y; j++){
            switch(charged.board[i][j][1]){
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
                perror("A player exceeds the number of penguins");
                return(2);
            }else if(charged.score[k] > penguins){
                perror("A player has more points that it is possible for phase placement");
                return(2);
            }
        }
    }
    if(phase=='m'){
        switch (players){
                    case 1: if(pen_1==0){
                                perror("Player with no penguins");
                                return 2;}
                            break;
                    case 2: if(pen_1!=penguins || pen_2!= penguins){
                                perror("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 || pen_2 == 0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 3: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins){
                                perror("Players with different number of penguins 3");
                                return 2;
                            }else if(pen_1==0 || pen_2==0 || pen_3==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 4: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4){
                                perror("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 5: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                    || penguins!=pen_5){
                                perror("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 6: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6){
                                perror("Players with different number of penguins");
                                return 2;
                            }else if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 7: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7){
                                perror("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 ||pen_7==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 8: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7 || penguins!=pen_8){
                                perror("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 || pen_7==0 ||pen_8==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    case 9: if(pen_1!=penguins || pen_2!=penguins || pen_3!= penguins ||penguins!=pen_4
                        || penguins!=pen_5 || penguins!=pen_6 || penguins!=pen_7 || penguins!=pen_8 || penguins!=pen_9){
                                perror("Players with different number of penguins");
                                return 2;
                            }if(pen_1==0 ||pen_2==0 || pen_3==0|| pen_4==0 ||pen_5==0
                        ||pen_6==0 || pen_7==0 ||pen_8==0 || pen_9==0){
                                perror("Player with no penguins");
                                return 2;
                            }break;
                    default:break;
                }
        for(int k=0; k<players;k++){        
                if(charged.score[k]<0){
                perror("There is a negative score");
                return 2;
            }
        }

    }
            
            for(int k = 0; k<players; k++){
                if(charged.number_player[k]<0 || charged.number_player[k]>players){
                perror("This player does not exist");
                 return 2;
                }
            }
        
        
    for (int i = 0; i < charged.dim_x; i++){
        for (int j = 0; j<charged.dim_y; j++){
            if(charged.board [i][j][0]>51){
                perror("More than three fishes in a tile");
                return(2);
            }else if(charged.board [i][j][1]> (players+48)){
                perror("There is a penguin of a player which doesn't exist");
                return (2);
            }
        }
    }

}
