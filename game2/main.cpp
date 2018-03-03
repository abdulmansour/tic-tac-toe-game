#include <iostream>
using namespace std;

bool player_move(int * gameptr, char letter);
bool end_game(int* gameptr, char letter, string winner);
void print_board(int*gameptr);
bool robot_move(int *gameptr, bool * valid_play_ptr, char letter,char robot_letter, bool victory);

int main() {
    char letter = ' ';
    char robot_letter = ' ';//the int value of X is 88, the int value of O is 79
    int game[9];
    int * gameptr = game;
    bool victory = false;
    int move = 0;
    srand(int(time(NULL)));
    bool valid_play[24];
    bool * valid_play_ptr = valid_play;
    
    for (int i = 0; i < 24; i++ ) {// used to assist the robot to know if he can play a good move or not
        valid_play[i] = true;
    }
    
    for (int i = 0; i < 9; i++) { //building the playing field
        game[i] = i+1;
    }
    
    do {
    cout << "Do you want to be X or O: " << flush; //player X or O choice
    cin >> letter;
        if (letter == 'x' || letter == 'X') {
            letter = 'X';
            robot_letter = 'O';
        }
        if (letter == 'o' || letter == 'o') {
            letter = 'O';
            robot_letter = 'X';
        }
    }while( letter != 'X' && letter != 'O');
    
    while(victory == false) { // match begins
        print_board(gameptr);
        victory = player_move(gameptr,letter);
        move++;
        if(move == 9 && victory == false) {
            print_board(gameptr);
            cout << "DRAW GAME!" << endl;
            break;
        }
        victory = robot_move(gameptr,valid_play_ptr,letter,robot_letter,victory);
        move++;
    }
    
}

bool robot_move(int *gameptr, bool * valid_play_ptr, char letter,char robot_letter, bool victory) {
    int robot_choice;
    bool valid = false;
    do {
        if (victory == true) {
            break;
        }
        robot_choice = rand()%9;
        if((gameptr[1] == letter && gameptr[2] == letter && valid_play_ptr[0] == true)) {
            robot_choice = 0;
            valid_play_ptr[0] = false;
        }
        else if((gameptr[3] == letter && gameptr[6] == letter && valid_play_ptr[1] == true)) {
            robot_choice = 0;
            valid_play_ptr[1] = false;
        }
        else if((gameptr[4] == letter && gameptr[8] == letter && valid_play_ptr[2] == true)) {
            robot_choice = 0;
            valid_play_ptr[2] = false;
        }
        else if((gameptr[0] == letter && gameptr[1] == letter && valid_play_ptr[3] == true)) {
            robot_choice = 2;
            valid_play_ptr[3] = false;
        }
        else if((gameptr[6] == letter && gameptr[4] == letter && valid_play_ptr[4] == true)) {
            robot_choice = 2;
            valid_play_ptr[4] = false;
        }
        else if((gameptr[8] == letter && gameptr[5] == letter && valid_play_ptr[5] == true)) {
            robot_choice = 2;
            valid_play_ptr[5] = false;
        }
        else if((gameptr[0] == letter && gameptr[3] == letter && valid_play_ptr[6] == true)) {
            robot_choice = 6;
            valid_play_ptr[6] = false;
        }
        else if((gameptr[7] == letter && gameptr[8] == letter && valid_play_ptr[7] == true)) {
            robot_choice = 6;
            valid_play_ptr[7] = false;
        }
        else if((gameptr[4] == letter && gameptr[2] == letter && valid_play_ptr[8] == true)) {
            robot_choice = 6;
            valid_play_ptr[8] = false;
        }
        else if((gameptr[2] == letter && gameptr[5] == letter && valid_play_ptr[9] == true)) {
            robot_choice = 8;
            valid_play_ptr[9] = false;
        }
        else if((gameptr[6] == letter && gameptr[7] == letter && valid_play_ptr[10] == true)) {
            robot_choice = 8;
            valid_play_ptr[10] = false;
        }
        else if((gameptr[0] == letter && gameptr[4] == letter && valid_play_ptr[11] == true)) {
            robot_choice = 8;
            valid_play_ptr[11] = false;
        }
        else if((gameptr[0] == letter && gameptr[2] == letter && valid_play_ptr[12] == true)) {
            robot_choice = 1;
            valid_play_ptr[12] = false;
        }
        else if((gameptr[4] == letter && gameptr[7] == letter && valid_play_ptr[13] == true)) {
            robot_choice = 1;
            valid_play_ptr[13] = false;
        }
        else if((gameptr[0] == letter && gameptr[6] == letter && valid_play_ptr[14] == true)) {
            robot_choice = 3;
            valid_play_ptr[14] = false;
        }
        else if((gameptr[4] == letter && gameptr[5] == letter && valid_play_ptr[15] == true)) {
            robot_choice = 3;
            valid_play_ptr[15] = false;
        }
        else if((gameptr[2] == letter && gameptr[8] == letter && valid_play_ptr[16] == true)) {
            robot_choice = 5;
            valid_play_ptr[16] = false;
        }
        else if((gameptr[3] == letter && gameptr[4] == letter && valid_play_ptr[17] == true)) {
            robot_choice = 5;
            valid_play_ptr[17] = false;
        }
        else if((gameptr[1] == letter && gameptr[4] == letter && valid_play_ptr[18] == true)) {
            robot_choice = 7;
            valid_play_ptr[18] = false;
        }
        else if((gameptr[6] == letter && gameptr[8] == letter && valid_play_ptr[19] == true)) {
            robot_choice = 7;
            valid_play_ptr[19] = false;
        }
        else if((gameptr[0] == letter && gameptr[8] == letter && valid_play_ptr[20] == true)) {
            robot_choice = 4;
            valid_play_ptr[20] = false;
        }
        else if((gameptr[2] == letter && gameptr[6] == letter && valid_play_ptr[21] == true)) {
            robot_choice = 4;
            valid_play_ptr[21] = false;
        }
        else if((gameptr[3] == letter && gameptr[5] == letter && valid_play_ptr[22] == true)) {
            robot_choice = 4;
            valid_play_ptr[22] = false;
        }
        else if((gameptr[1] == letter && gameptr[7] == letter && valid_play_ptr[23] == true)) {
            robot_choice = 4;
            valid_play_ptr[23] = false;
        }
        
        
        
        
        
        //Adjust 'if statements' to ensure that robot plays winning move instead of defending opponent from winning
        else if((gameptr[1] == letter && gameptr[2] == letter && valid_play_ptr[24] == true)) {
            robot_choice = 0;
            valid_play_ptr[0] = false;
        }
        else if((gameptr[3] == letter && gameptr[6] == letter && valid_play_ptr[25] == true)) {
            robot_choice = 0;
            valid_play_ptr[1] = false;
        }
        else if((gameptr[4] == letter && gameptr[8] == letter && valid_play_ptr[26] == true)) {
            robot_choice = 0;
            valid_play_ptr[2] = false;
        }
        else if((gameptr[0] == letter && gameptr[1] == letter && valid_play_ptr[27] == true)) {
            robot_choice = 2;
            valid_play_ptr[3] = false;
        }
        else if((gameptr[6] == letter && gameptr[4] == letter && valid_play_ptr[4] == true)) {
            robot_choice = 2;
            valid_play_ptr[4] = false;
        }
        else if((gameptr[8] == letter && gameptr[5] == letter && valid_play_ptr[5] == true)) {
            robot_choice = 2;
            valid_play_ptr[5] = false;
        }
        else if((gameptr[0] == letter && gameptr[3] == letter && valid_play_ptr[6] == true)) {
            robot_choice = 6;
            valid_play_ptr[6] = false;
        }
        else if((gameptr[7] == letter && gameptr[8] == letter && valid_play_ptr[7] == true)) {
            robot_choice = 6;
            valid_play_ptr[7] = false;
        }
        else if((gameptr[4] == letter && gameptr[2] == letter && valid_play_ptr[8] == true)) {
            robot_choice = 6;
            valid_play_ptr[8] = false;
        }
        else if((gameptr[2] == letter && gameptr[5] == letter && valid_play_ptr[9] == true)) {
            robot_choice = 8;
            valid_play_ptr[9] = false;
        }
        else if((gameptr[6] == letter && gameptr[7] == letter && valid_play_ptr[10] == true)) {
            robot_choice = 8;
            valid_play_ptr[10] = false;
        }
        else if((gameptr[0] == letter && gameptr[4] == letter && valid_play_ptr[11] == true)) {
            robot_choice = 8;
            valid_play_ptr[11] = false;
        }
        else if((gameptr[0] == letter && gameptr[2] == letter && valid_play_ptr[12] == true)) {
            robot_choice = 1;
            valid_play_ptr[12] = false;
        }
        else if((gameptr[4] == letter && gameptr[7] == letter && valid_play_ptr[13] == true)) {
            robot_choice = 1;
            valid_play_ptr[13] = false;
        }
        else if((gameptr[0] == letter && gameptr[6] == letter && valid_play_ptr[14] == true)) {
            robot_choice = 3;
            valid_play_ptr[14] = false;
        }
        else if((gameptr[4] == letter && gameptr[5] == letter && valid_play_ptr[15] == true)) {
            robot_choice = 3;
            valid_play_ptr[15] = false;
        }
        else if((gameptr[2] == letter && gameptr[8] == letter && valid_play_ptr[16] == true)) {
            robot_choice = 5;
            valid_play_ptr[16] = false;
        }
        else if((gameptr[3] == letter && gameptr[4] == letter && valid_play_ptr[17] == true)) {
            robot_choice = 5;
            valid_play_ptr[17] = false;
        }
        else if((gameptr[1] == letter && gameptr[4] == letter && valid_play_ptr[18] == true)) {
            robot_choice = 7;
            valid_play_ptr[18] = false;
        }
        else if((gameptr[6] == letter && gameptr[8] == letter && valid_play_ptr[19] == true)) {
            robot_choice = 7;
            valid_play_ptr[19] = false;
        }
        else if((gameptr[0] == letter && gameptr[8] == letter && valid_play_ptr[20] == true)) {
            robot_choice = 4;
            valid_play_ptr[20] = false;
        }
        else if((gameptr[2] == letter && gameptr[6] == letter && valid_play_ptr[21] == true)) {
            robot_choice = 4;
            valid_play_ptr[21] = false;
        }
        else if((gameptr[3] == letter && gameptr[5] == letter && valid_play_ptr[22] == true)) {
            robot_choice = 4;
            valid_play_ptr[22] = false;
        }
        else if((gameptr[1] == letter && gameptr[7] == letter && valid_play_ptr[23] == true)) {
            robot_choice = 4;
            valid_play_ptr[23] = false;
        }
        
        if (gameptr[robot_choice] == 88 || gameptr[robot_choice] == 79) {
            valid = false;
        }
        else {
            gameptr[robot_choice] = robot_letter;
            valid = true;
        }
        victory = end_game(gameptr,robot_letter,"Robot");
    }
    while(valid == false);
    return victory;
}
bool player_move(int * gameptr, char letter) {
    bool victory = false;
    bool valid = false;
    int choice;
    do {
        cout << endl << "TIC TAC TOE! Enter #: " << flush;
        cin >> choice;
        if (gameptr[choice-1] == 88 || gameptr[choice-1] == 79) {
            cout << "Cannot choose this position..." << endl;
            valid = false;
        }
        else {
            gameptr[choice-1] = letter;
            valid = true;
            victory = end_game(gameptr,letter,"Player");
        }
    }
    while(valid == false);
    
    return victory;
}

bool end_game(int* gameptr, char letter,string winner) {
    bool victory = false;
    if ((gameptr[0] == letter && gameptr[1] == letter && gameptr[2] == letter) || (gameptr[3] == letter && gameptr[4] == letter && gameptr[5] == letter) || (gameptr[6] == letter && gameptr[7] == letter && gameptr[8] == letter)) {
        print_board(gameptr);
        cout << winner << " WINS!" << endl;
        victory = true;
    }
    else if ((gameptr[0] == letter && gameptr[3] == letter && gameptr[6] == letter) || (gameptr[1] == letter && gameptr[4] == letter && gameptr[7] == letter) || (gameptr[2] == letter && gameptr[5] == letter && gameptr[8] == letter)) {
        print_board(gameptr);
        cout << winner << " WINS!" << endl;
        victory = true;
    }
    else if ((gameptr[0] == letter && gameptr[4] == letter && gameptr[8] == letter) || (gameptr[2] == letter && gameptr[4] == letter && gameptr[6] == letter)) {
        print_board(gameptr);
        cout << winner << " WINS!" << endl;
        victory = true;
    }
    return victory;
}

void print_board(int * gameptr) {
    for (int i = 0; i < 9; i++) {
        if (gameptr[i] == 88 || gameptr[i] == 79) {
            cout << "| " << char(gameptr[i]) << " |";
        }
        else {
            cout << "| " << gameptr[i] << " |";
        }
        if (i == 2 || i == 5 || i == 8) {
            cout << endl;
        }
    }
}
