//James Connolly
//Dr. Steinberg
//COP3223
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //result of the overall battle

int main() //main function
{
    greeting(); //display greeting message

    //setup random generator
    int seed;
    printf("Before we start, pick a number to determine how random I will be.\n");
    scanf("%d", &seed);
    srand(seed);

    printf("All set now!\n");
    for (int x = 0; x < ROUNDS; ++x)
    {
        playRound(x + 1);
    }
    printf("********************************************************\n");
    printf("Thank you for playing!\n");

    return 0;
}




void greeting() 
{
    //greeting and explaining rules
    printf("********************************************************\n");
    printf("Welcome to rock paper scissor game!\n");
    printf("Here are the rules.\n");
    printf("You and I will get to choose rock, paper, or scissor.\n");
    printf("After we made a decision we will reveal it and determine the winner based\n");
    printf("on these rules.\n");
    printf("Rock beats Scissor!\n");
    printf("Paper beats Rock!\n");
    printf("Scissor beats Paper!\n");
    printf("If we both pick the same option, then it is a tie.\n");
    printf("Ready to play ? ...Here we go!\n");
    printf("********************************************************\n");
}



void result(int player1, int player2)
{
    if (player1 > player2) //Person player beats the computer
    {
        printf("You won! I'll get you next time!\n");
    }
    else //Computer beats Person Player
    {
        printf("I won! Haha you will never beat me!\n");
    }
}



int pickOne() //player picks rock, paper, or scissors
{
    int selectingPick;
    printf("1---Rock\n");
    printf("2---Paper\n");
    printf("3---Scissors\n");
    printf("Make your selection: ");
    scanf("%d", &selectingPick); //takes selection from user and stores it in a variable
    printf("Calculating my decision...\n");
    return selectingPick;
}



int computerPick() //computer chooses a rock paper or scissors randomly
{
    int num = rand() % 3 + 1; //generates random number between 1 and 3
    return num;
}



void playRound(int round) //plays round
{
    printf("Welcome to a new round %d!\n", round);
    printf("Best out of three...Let's go!\n");
    int p1wins = 0; //storing the amount of player 1 wins
    int p2wins = 0; //storing the amount of player 2 wins
    while (p1wins != 3 && p2wins != 3) //keeps the game going until someone gets 3 wins 
    {
        printf("********************************************************\n");
        printf("Player 1 has won %d time(s).\n", p1wins);
        printf("Player 2 has won %d time(s).\n", p2wins);
        int playerPick = pickOne();
        int computerPicks = computerPick();
        int win = battle(playerPick, computerPicks);
        if (win == 1) //player wins
        {
            p1wins++;
        }
        else if (win == 2) //computer wins
        {
            p2wins++;
        }
        else if (win == 0) //if a draw occurs
        {
            
        }
        else //user chooses an invalid choice
        {
            printf("You made an invalid choice.\n");
        }
    }
    result(p1wins, p2wins);
}



int battle(int player1, int player2)
{
    if (player1 == 1) //player selects rock
    {
        if (player2 == 1) //computer chooses rock
        {
            printf("Player 1 and Player 2 both used Rock!\n");
            printf("Draw!\n");
            printf("********************************************************\n");
            return 0;
        }
        else if (player2 == 2) //computer chooses paper
        {
            printf("Player 1 used Rock and Player 2 used Paper!\n");
            printf("Paper beats Rock!\n");
            printf("********************************************************\n");
            return 2;
        }
        else //computer chooses scissor
        {
            printf("Player 1 used Rock and Player 2 used Scissor!\n");
            printf("Rock beats Scissor!\n");
            printf("********************************************************\n");
            return 1;
        }
    }
    else if (player1 == 2) //player pick paper
    {
        if (player2 == 1) //computer picks rock
        {
            printf("Player 1 used Paper and Player 2 used Rock!\n");
            printf("Paper beats Rock!\n");
            printf("********************************************************\n");
            return 1;
        }
        else if (player2 == 2) //computer picks paper
        {
            printf("Player 1 and Player 2 both used Paper!\n");
            printf("Draw!\n");
            printf("********************************************************\n");
            return 0;
        }
        else //computer picks scissor
        {
            printf("Player 1 used Paper and Player 2 used Scissor!\n");
            printf("Scissor beats Paper!\n");
            printf("********************************************************\n");
            return 2;
        }
    }
    else if (player1 == 3) //Player chooses scissors
    {
        if (player2 == 1) //Computer chooses rock
        {
            printf("Player 1 used Scissor and Player 2 used Rock!\n");
            printf("Rock beats Scissor!\n");
            printf("********************************************************\n");
            return 2;
        }
        else if (player2 == 2) //Computer chooses paper
        {
            printf("Player 1 used Scissor and Player 2 used Paper!\n");
            printf("Scissor beats Paper!\n");
            printf("********************************************************\n");
            return 1;
        }
        else //draw statement for scissors
        {
            printf("Player 1 and Player 2 both used Scissor!\n");
            printf("Draw!\n");
            printf("********************************************************\n");
            return 0;
        }
    }
    else //player chooses invalid choice
    {
        return -1;
    }
}

