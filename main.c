/*header file inclusion for different purposes in the program like input/output*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_output.h"//header file inclusion provided by the professor

player players[PLAYERS_NUM];
//function definition of popping the element and returns the ascii value of character
int pop(square *);
char test2[]="Enter the position you want to pick chips up from\n";
int max = 5;//defining the maximum of a stack
int dec(int);//function definition to decrement an integer
void showline(char a[]){
    printf("%s",a);//prints the sentence
}
void show(char c){
    printf("%c ", c);//prints the character
}
int inc(int);//function definition to increment an integer
void push(piece *,char);//function signature to push the peices
int main()
{
    square board[BOARD_SIZE][BOARD_SIZE];//board initialization
    initialize_players(players);//initializes the players
    printf("The name of the first player is :");
    char test3[]="Wrong input!! Enter again!\n";
    puts(players[0].name);//puts the first player name in the array
    printf("\nThe name of the second player is:");
    puts(players[1].name);//puts the second player name in the array
    printf("Color for first player is : %c",players[0].player_color);
    printf("\nColor for second player is : %c",players[1].player_color);
    printf("\n");
    initialize_board(board);// initialization of board
    print_board(board);//board is printed
    int ITE=0;
    int x= 1000;
     while (ITE<x)
     {
        printf("Player %d's chance\nEnter the no. of chips you wanna move\n", (ITE & 1) + 1);//prints whose chance
        int num;
        scanf("%d", &num);//accepts the no of choice
         if (num == 1)
         {
            showline("Enter the position you want to pick chips up from\n");
            int init_i = 0,init_j=0;
            while (num)
            {
                scanf("%d %d", &init_i, &init_j);//accepts the position u want to place
                char a1=players[ITE & 1].player_color;
                char a2=board[init_i][init_j].stack->color;
                if (a1 != a2)//checks if the user is pickin up his chips
                    showline("Wrong input!! Enter again!\n");//asks the user to enter the position again
                else
                    break;
            }
            int fin_i = init_i;
            int fin_j = init_j;
            piece * temp = (piece *) malloc(sizeof(piece));

            printf("Enter the direction :\n");//asks the user where he wants to move his peice
            printf("'T' for going to top ,\n");//T for top
            printf("'B' to go below,\n");//B for down
            printf("'L' to go left ,\n");//L for left
            printf("'R' to go right.\n");//R for right
            getchar();
            temp->color = players[ITE & 1].player_color;
            char c = getchar();
                if(c=='T')
                 {
                    fin_i=dec(fin_i);//decrements it
                }
                else if(c=='B')
                {
                    fin_i=inc(fin_i);//increments it
                }
                if(c=='L') {
                    fin_j=dec(fin_j);//decrements it
                }
                if(c=='R'){
                    fin_j=inc(fin_j);//increments it
            }
            temp->next = NULL;
                char c1=board[init_i][init_j].stack->color;
                char c2=players[ITE & 1].player_color;
                //checks the color and makes it blank
            if (c1==c2)
            {
                board[init_i][init_j].stack->color = ' ';//makes it blank
            }
            printf("** The Board **\n");//board is printed
            for (int i = 0; i < BOARD_SIZE; i++) { //looping
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j].valid==1)  //checks the validity
                     {
                        if ((i == fin_i && j == fin_j && (i+j)==(fin_i+fin_j)))//checks the condition of position
                         {
                            int tempsum = temp->head;
                            tempsum += board[i][j].stack->head;
                            temp->head = tempsum;
                            piece *test = board[i][j].stack;
                            while (!(test->next == NULL)) {
                                test = test->next;
                            }
                            if(1){
                            test->next = temp;
                            printf("| ");
                            piece *copy = board[i][j].stack;
                            while (!(copy == NULL)) {
                                printf("%c "copy->color);
                                copy = copy->next;
                            }
                            }
                            continue;
                        }
                        if (!(board[i][j].stack != NULL))
                            printf("|   ");
                        else {
                            printf("| ");
                            piece *t = board[i][j].stack;
                            while (t != NULL) {
                                show(t->color);
                                show(' ');
                                show(' ');
                                t = t->next;
                            }
                        }
                    } else
                        printf("| - ");
                }
                printf("|\n");
            }
        } else {
          // code for moving the stack
            char test1[]="Enter the position you want to place chips on\n";
            int init_i = 0,init_j=0;
            int condition = 0;
            //asks the user his/her choice
            showline("Enter 1 to get chips from your reserve OR\n");
            showline("0 to continue as it is\n");
            scanf("%d", &condition);
            if (condition!=0)
            {
                showline(test1);//prints on board and asks the user to enter the position
                scanf("%d %d", &init_i, &init_j);//gets the input
            } else if (condition==0)
             {
                showline(test2);
                while (1) {
                    scanf("%d %d", &init_i, &init_j);//takes the chips from this position
                    if (players[ITE & 1].player_color != board[init_i][init_j].stack->color)//checks the color compatibility
                        showline(test3);//asks him to enter again
                    else
                        break;
                }
            }
            int fin_i;
            int fin_j;
            int ictr = board[init_i][init_j].num_pieces; //counts store the no of peices on initial pos
            printf("Enter the final position \n");//asks the user to enter the final position
            scanf("%d %d", &fin_i, &fin_j);//accepts the input
            int count = board[fin_i][fin_j].num_pieces;  //counts store the no of peices on final pos
            int left = count;
            left+=ictr;
            left-=max;
            //when the stck has more than 5 elements
            if (!(left <= 0)) {
                for (int i = 1; i <= left; i=inc(i)) {
                    char t = pop(&board[fin_i][fin_j]);//pops the elemnets after 5 elements
                    if (players[ITE & 1].player_color == t) {
                        players[ITE & 1].own=inc(players[ITE & 1].own);//increments the players own peices
                    } else {
                        players[ITE & 1].ad=inc(players[ITE & 1].ad);//increments the players adversary peices
                    }
                }
            }
            int q=0;
            while( q++ < num)
            {
                push(board[fin_i][fin_j].stack,(char) pop(&board[init_i][init_j]));//pushes the elements on board's final position
            }
            printf("\n*** The Board ***\n");
            //loop to traverse through the board
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                //prints the board
                    if (board[i][j].valid==1) {//checks the squares validity
                        if (!board[i][j].stack)
                            printf("|  ");
                        else {
                            printf("| ");
                            for(piece *t = board[i][j].stack;t!=NULL;t=t->next)
                            {
                                printf("%c ", t->color);//prints the color's peice
                            }
                        }
                    } else
                        printf("| - ");
                }
                printf("|\n");
            }
        }
        int plc = ITE & 1;
        plc=inc(plc);//increments the pls
        //for 1st player
        if (players[plc].ad == (2*BOARD_SIZE+PLAYERS_NUM))
        {
            printf("Game ends! and winner is %s ,player %d ", players[plc].name, plc);//winner decalration
        }
        if (plc)
            plc=dec(plc);
            //for player 2
        else if (players[plc].ad == (2*BOARD_SIZE+PLAYERS_NUM)) {
            printf("Game ends! and winner is %s ,player %d ", players[plc].name, plc);//winner declaration
        }
        ITE++;//increments ITE
    }
    return 0;
}//end of the code
//decrement function
int dec(int x)
{
    return x-1;//decrements x
}
//increment function
int inc(int x)
{
    return x+1;//increments x
}
//pops the element
int pop(square *x)
{
    char c = (x)->stack->color;//stores the stack color in c
    (x)->num_pieces = dec(x->num_pieces) ;//decrements it
    (x)->stack = (x)->stack->next;//travels to the next position
    return (int)c;//returns the ascii value of the character
}//end of the function
/*pushes the element on top  of the stack*/
void push(piece *x, char c) {

    piece *temp = (piece *) malloc(sizeof(piece));
    (temp)->next = NULL;
    (temp)->color = c;//stores the value of c in temp
    piece * copy;
    for(copy=x;copy->next!=NULL;copy=copy->next);
    copy->next = temp;
}//end of the function
