#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FileInputOutput.h"
#include "GameStateOperations.h"

int main(int argc, char *argv[])
{
    char* player_name="Team-E";
    int i=0;
    int penguins;
    int ExitCode;
    int current_player;
    int number_of_players;
    int number_of_penguins;
    if(argc<2 || argc==3 || argc>5)
    {
        printf(" *incorrect number of arguments*\n");
        return 3;
    }

    if(argv[1][0]=='n' && argv[1][1]=='a' && argv[1][2]=='m' && argv[1][3]=='e')
        {
            printf("%s\n", player_name);
            return 0;
        }

    if (argc==5)
    {//placement phase
        if(argv[1][6]!='p' || argv[1][7]!='l' || argv[1][8]!='a' || argv[1][9]!='c' || argv[1][10]!='e')
        {
            printf(" *incorrect program arguments - 4 arguments but phase is not placement*\n");
            return 3;
        }
        if(argv[2][9]!='1' && argv[2][9]!='2' && argv[2][9]!='3' && argv[2][9]!='4' && argv[2][9]!='5')
        {
            printf(" *incorrect program arguments - the number of penguins is incorrect*\n");
            return 3;
        }
        struct read Game_state = Read_from_file(argv[3]);
        struct read *pointer_game_state = &Game_state;
        if(Game_state.player_id[0][0]=='0')
        {
            number_of_players=0;
        }
        else
        {
            number_of_players=1;
        }
        number_of_penguins=argv[2][9]-48;
        char phase = 'p';
        i=0;
        while(Game_state.number_player[i+1]==Game_state.number_player[i]+1 && Game_state.number_player[0] < 10)
        {
            number_of_players++;
            i++;
        }
        ExitCode = check_input_mistakes(number_of_players, number_of_penguins, phase, Game_state);
        if(ExitCode == 2)
        {
            printf("\n");
            return 2;
        }
        current_player = Input_player_data(pointer_game_state, player_name, &number_of_players, phase);
        Place_penguin(pointer_game_state, number_of_penguins, current_player);
        WriteToFile(Game_state, number_of_players, current_player, phase, argv[4]);
        return 0;
    }

    if (argc==4)
    {//movement phase
        if(argv[1][6]!='m' || argv[1][7]!='o' || argv[1][8]!='v' || argv[1][9]!='e')
        {
            printf(" *incorrect program arguments - 3 arguments but phase is not movement*\n");
            return 3;
        }
        char phase = 'm';
        struct read Game_state = Read_from_file(argv[2]);
        struct read *pointer_game_state = &Game_state;
        if(Game_state.player_id[0][0]=='0')
        {
            printf(" *movement phase but no players*\n");
            return 2;
        }
        number_of_players=1;
        number_of_penguins=0;
        while(Game_state.number_player[i+1]==Game_state.number_player[i]+1 && Game_state.number_player[0] < 10)
        {
            number_of_players++;
            i++;
        }
        ExitCode = check_input_mistakes(number_of_players, number_of_penguins, phase, Game_state);
        if(ExitCode == 2)
        {
            printf("\n");
            return 2;
        }
        current_player = Input_player_data(pointer_game_state, player_name, &number_of_players, phase);
        Make_move(pointer_game_state, current_player);
        WriteToFile(Game_state, number_of_players, current_player, phase, argv[3]);
        return 0;

    }
}
