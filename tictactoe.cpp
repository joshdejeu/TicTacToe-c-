// TicTacToe game versus computer
// P1 - User | P2 - Computer

// Josh Dejeu
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int SIZE = 3;
void display_table(char board[SIZE][SIZE]);
void clear_table(char board[SIZE][SIZE]);
bool check_table_full(char board[SIZE][SIZE]);
bool check_legal_option(char board[SIZE][SIZE], int r, int c);
void generate_player2_move(char board[SIZE][SIZE]);
int check_three_in_a_row(char board[SIZE][SIZE]);
bool check_end_of_game(char board[SIZE][SIZE]);
void get_player1_move(char board[SIZE][SIZE]);
void print_winner(char board[SIZE][SIZE]);
void callme(char board[SIZE][SIZE]);
int main()
{
    srand(time(NULL));  // Initialize random number generator.
    // Declare the tic-tac-toe board
    char board[SIZE][SIZE];
    // The row and column of the move for either player 1 or 2
    int row, col;
    // Clear the table
    clear_table(board);
    // Display the table
    display_table(board);
    do
    {
        // Have player 1 enter their move
        get_player1_move(board);
        // Generate player 2 move
        generate_player2_move(board);
        // Do this while the game hasn't ended
    } while (check_end_of_game(board) == false);
    // After the game is over, print who won
    print_winner(board);
    return 0;
}
void display_table(char board[SIZE][SIZE]){
    cout << "The current state of the game is:"<<endl;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
void clear_table(char board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = '_';
        }
    }
    return;
}
bool check_table_full(char board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j]=='_'){
                return false;//false if NOT full 
            }
        }
    }
    return true;//true if full
}
bool check_legal_option(char board[SIZE][SIZE], int r, int c){
    if(board[r-1][c-1]!='_'){
        return false;//if space is taken it will return false
    }
    return true;
}
void generate_player2_move(char board[SIZE][SIZE]){
    //generate random number between 0 and 2:
    int randRow = (rand() % 3)+1, randCol = (rand() % 3)+1;
    if(!check_legal_option(board, randRow, randCol)){
        generate_player2_move(board);
    }else{
        cout << "Player 2 has entered [row, col]: " << randRow << " " << randCol <<endl;
        board[randRow-1][randCol-1]='X';//set board piece to bot selection
        display_table(board);
    }
    return;
}
int check_three_in_a_row(char board[SIZE][SIZE]){
    if(
        board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X'||
        board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X'||
        board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X'||

        board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X'||
        board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X'||
        board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X'||        
        
        board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X'||
        board[2][0]=='X' && board[1][1]=='X' && board[0][2]=='X')
    {
        return 2;//player 2 has won
    }
    else if(
        board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O'||
        board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O'||
        board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O'||

        board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O'||
        board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O'||
        board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O'||        
        
        board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O'||
        board[2][0]=='O' && board[1][1]=='O' && board[0][2]=='O')
    {
        return 1;//player 1 has won
    }
    else{
        return 0;//neither player has won
    }
}
bool check_end_of_game(char board[SIZE][SIZE]){
    if(check_three_in_a_row(board)==1 || check_three_in_a_row(board)==2){
        return true;//game is over
    }
    else{
        return false;//game is NOT over
    }
    if(check_three_in_a_row(board)==0){
        return true;//game over on a draw
    }
}
void get_player1_move(char board[SIZE][SIZE]){
    int r, c;
    cout << "Player 1 enter your selection [row col]: ";
    cin >> r >> c;
    if(!check_legal_option(board, r, c)){
        cout << "Invalid move, try again." << endl;
        get_player1_move(board);
    }else{
        board[r-1][c-1]='O';//set board piece to player selection
        display_table(board);
    }
    return;
}
void print_winner(char board[SIZE][SIZE]){
    switch(check_three_in_a_row(board)){
        case(0):
            cout << "Game over, no player wins." << endl;
            break;
        case(1):
            cout << "Player 1 wins" << endl;
            break;
        case(2):
            cout << "Player 2 wins" << endl;
            break;
    }
    return;
}