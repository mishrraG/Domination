//
//

#ifndef FOCUS_GAME_INIT_H
#define FOCUS_GAME_INIT_H
#endif //FOCUS_GAME_INIT_H
#define BOARD_SIZE 8
#define PLAYERS_NUM 2
//Player
typedef struct player{
    //the color associated with the player
    char player_color;
    char name[10];
    int ad;
    int own;
    /*
     * A player should also be characterized by:
     * number of adversary's pieces captured,
     * number of own pieces kept.
    */
}player;
// A piece
typedef struct piece {
    //the color associated with a piece
    char color;
    int head;
    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece,*top,*temp;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    int valid;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);