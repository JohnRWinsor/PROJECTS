#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
// Structures 
typedef struct Player
{
    char name[15];
    int wins;
} player;

// Global Varibles
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Functions used in code
void resetBoard();
void displayBoard();
int checkOpenSquare();
void playerMove();
void computerMove();
char checkWin();
void printWinner(char);
int def;
int input;

int main()
{
    player p1;
    printf("Enter a name: ");
    scanf("%s", p1.name);
    p1.wins = 0;

    char winner = ' ';
    char response;
    input = 1;

    switch (input)
    {
    case 1:
        printf("Welcome to the Amazing game of TIC TAC TOE\n");
        printf("1. Play\n");
        printf("2. How to play\n");
        printf("3. Exit\n");
        printf("\n%s has won %d times\n\n", p1.name, p1.wins);

        printf("Select a Number: ");
        scanf("%d", &def);
        // Play game switch
        if (def == 1)
        {
            do
            {

                winner = ' ';
                response = ' ';
                resetBoard();

                while (winner == ' ' && checkOpenSquare() != 0)
                {
                    displayBoard();

                    playerMove();
                    winner = checkWin();
                    if (winner != ' ' || checkOpenSquare() == 0)
                    {
                        break;
                    }

                    computerMove();
                    winner = checkWin();
                    if (winner != ' ' || checkOpenSquare() == 0)
                    {
                        break;
                    }
                }

                displayBoard();
                printWinner(winner);

                printf("\nWould you like to play to again? (Y / N): ");
                scanf("%c");
                scanf("%c", &response);
                response = toupper(response);
            } while (response == 'Y');
            return 0;
        }
    }
    // instrutions for the game
    if (def == 2)
    {
        printf("How to play Tic Tac Toe");
        printf("\nThis is a game of patterns you must get your tokens in a line of 3 horizontal, vertical, or diagonal");
        printf("\n Players will be 'X' and Computer will be 'O'");
        printf("\nWhat the board will look like: ");
        printf("\n %c | %c | %c ");
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ");
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ");

        // To exit the game
        if (def == 3)
        {
            printf("Thanks For Playing!!!");
            return 0;
        }
    }
}
void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
// Too display the game board
void displayBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    // printf("/n");
}
// This code will check the board for open squares
int checkOpenSquare()
{
    int squares = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                squares--;
            }
        }
    }
    return squares;
}
/*
    This will allow the players to pick where they want to play but selecting the Row and Column number
    or give them an invaild inpput when that square is used
*/
void playerMove()
{
    int x;
    int z;

    do
    {
        printf("Enter Row Number [1-3]: ");
        scanf("%d", &x);
        x--;
        printf("Enter Column Number [1-3]: ");
        scanf("%d", &z);
        z--;

        if (board[x][z] != ' ')
        {
            printf("Invaild move );\n");
        }
        else
        {
            board[x][z] = PLAYER;
            break;
        }
    } while (board[x][z] != ' ');
}

void computerMove()
{
    srand(time(0));
    int x;
    int z;

    if (checkOpenSquare() > 0)
    {
        do
        {
            x = rand() % 3;
            z = rand() % 3;
        } while (board[x][z] != ' ');

        board[x][z] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

// This function checks the board for wins on the columns and rows
char checkWin()
{
    // Check Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // Check Colums
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // Check diggonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("WINNER WINNER CHICKEN DINNER ");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOST ");
    }
    else
    {
        printf("TIE GAME ");
    }
}
