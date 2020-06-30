//
// Created by Lili on 26/03/2020.
//
//
// Created by Lili on 24/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_init.h"

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->valid=0;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->valid=1;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->valid = 1;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->color='G';
s->stack->head =0;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->valid=1;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->head =1;
s->stack->color='R';
s->stack->next = NULL;
s->num_pieces = 1;
}
void initialize_players(player players[]){
    printf("Enter the player names for player 1\n");
    char aname[10];
    scanf("%s",aname);
    strcpy(players[0].name,aname);
    printf("Enter the player names for player 2\n");
    char bname[10];
    scanf("%s",bname);
    strcpy(players[1].name,bname);
    getchar();
    printf("Enter the color for player 1\n");
    char c=getchar();
    switch (c)
    {
        case 'G' :
        players[0].player_color=c;
        players[1].player_color='R';
        break;
        case 'R':
        players[0].player_color='R';
        players[1].player_color='G';
        break;
    }
}
//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }
}

