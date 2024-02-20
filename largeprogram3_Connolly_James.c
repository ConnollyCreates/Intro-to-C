//James Connolly
//Dr. Steinberg
//COP 3223 Section 203
//Large Program 3

#include<stdio.h> 

#include<string.h> 

#include<ctype.h> 

void maskWord(char starword[], int size); //mask word with stars to display
int playRound(char starword[], char answer[]); //play a round of hangman
int occurencesInWord(char userguess, char answer[]); //times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective *
int guessTheWord(char answer[]); //guess the word
void playAgain(int* play); //ask user to play again

int main() 
{
    printf("\033[1;37m");
    printf("##########################################################################################\n\n");
    printf("\033[0;37m");
    printf("Hello Hangman Enthusiast!\n\n");
    printf("Welcome to Hang Man!\n\n");
    printf("You will be asked to guess the letters you think are in the hidden word!\n\n");
    printf("If you are correct, you will reveal the letters in the hidden word.\n\n");
    printf("If you are wrong your strike counter will increase!\n\n");
    printf("Be weary, once you have 6 strikes the round is OVER and you will LOSE!\n\n");
    printf("Once you have revealed enough letters, make a guess at the secret word!\n\n");
    printf("However, if you guess wrong... YOU LOSE!\n\n");
    printf("Good Luck!\n\n");
    printf("\033[1;37m");
    printf("##########################################################################################\n\n");
    printf("\033[0;37m");

    int play = 1; //create play condition set to 1
    int* ptr = &play; 
    FILE* inp = fopen("words.txt", "r"); //creates input from words

    while (play == 1) //while user wants to keep playing
    {
        char answer[20]; //create answer string
        fscanf(inp, "%s", answer); //scans for answer from words.txt
        int answerSize = strlen(answer); //answerSize is what the user input
        char starword[20]; //creates starword string
        maskWord(starword, answerSize); 
        int win = playRound(starword, answer); 

        if (win == 1) //if user wins
        {
            printf("Congrats! You beat Hangman!\n\n");
            printf("\033[1;37m");
            printf("##########################################################################################\n\n");
            printf("\033[0;37m");
        }
        else //user loses
        {
            printf("Uh oh... YOU LOST!\n\n");
            printf("\033[1;37m");
            printf("##########################################################################################\n\n");
            printf("\033[0;37m");
        }
        playAgain(ptr); //calls function
    }

    printf("Thank you for playing Hangman!\n\n");
    printf("\033[1;37m");
    printf("##########################################################################################\n");
    printf("\033[0;37m");

    return 0; 
}



int playRound(char starword[], char answer[]) 
{
    char guess; //create char
    int numCorrect = 0; //create numCorrect and set to 0
    int strikes = 0; //create strikes and set to 0
    int correctGuesses = 0; //create correctGuesses and set to 0
    int answerSize = strlen(answer); //create answerSize and set to length of answer
    int inRow = 0; //create inRow and set to 0

    printf("Welcome to a NEW ROUND!\n\n");

    printf("The word you are guessing is %d letter(s) long.\n\n", answerSize);

    printf("\033[1;37m");

    printf("##########################################################################################\n\n");

    printf("\033[0;37m");

    while ((strikes < 6) && (numCorrect != strlen(answer))) //while user hasnt won or lost
    {
        int makeGuess; //create makeGuess
        printf("Your strike count is now %d strike(s)...\n\n", strikes);
        printf("Your hidden word is: \n\n");
        printf("%s\n\n", starword);
        printf("\033[1;37m");
        printf("##########################################################################################\n\n");
        printf("\033[0;37m");
        printf("Guess a letter!\n\n");
        scanf(" %c", &guess); //scans for user inp
        printf("\n");
        printf("\033[1;37m");
        printf("##########################################################################################\n\n");
        printf("\033[0;37m");

        int occurences = occurencesInWord(guess, answer); //creates occurences and calls function

        if (occurences != 0) //if guess occurs in the answer
        {
            printf("%c was correct!\n\n", toupper(guess));

            for (int i = 0; i < occurences; i++) //for the amount of occurences
            {
                numCorrect++; //add 1 to numcorrect
            }

            inRow++; 
            printf("\033[1;37m");
            printf("##########################################################################################\n\n");
            printf("\033[0;37m");
            updateStarWord(starword, answer, guess); //calls function

            if ((inRow % 2 == 0) && (numCorrect != strlen(answer))) //if user got 2 in a row && has not won
            {
                printf("You have gotten 2 in a row!\n\n");
                printf("Do you want to make a guess?\n\n");
                printf("Yes (1)\n");
                printf("No (0)\n\n");
                scanf(" %d", &makeGuess); //scans for input
                printf("\n");
                printf("\033[1;37m");
                printf("##########################################################################################\n\n");
                printf("\033[0;37m");

                if (makeGuess == 1) //chooses 1
                {
                    int correct = guessTheWord(answer); //call guessing function

                    if (correct == 1) //if user guesses word
                    {
                        return 1; //win
                    }
                    else //if user is incorrect
                    {
                        printf("THAT IS WRONG!\n\n");
                    }
                }
                else //if user doesnt choose 1
                {
                    while (getchar() != '\n') //clear buffer
                    {

                    }
                }
            }
        }
        else
        {
            printf("%c is not the correct guess!\n\n", toupper(guess));
            printf("\033[1;37m");
            printf("##########################################################################################\n\n");
            printf("\033[0;37m");
            inRow = 0; //set in row to 0
            strikes++; //add 1 to strike
        }

    }

    if (strikes == 6) //if user has 6 strikes
    {
        return 0; //return lose
    }
    else // if user has less than 6 strikes
    {
        return 1; //return win
    }
} 

int guessTheWord(char answer[]) 
{
    char userGuess[20]; //creates array for user guess
    printf("Enter your guess.\n\n");
    scanf(" %s", userGuess); //scans for string
    printf("\n");
    printf("\033[1;37m");
    printf("##########################################################################################\n\n");
    printf("\033[0;37m");


    for (int i = 0; i < strlen(userGuess); i++) //for length of user guess
    {
        userGuess[i] = tolower(userGuess[i]); //set all letters to lower case
    }

    if (strcmp(userGuess, answer) == 0) //if the guess equals answer
    {
        return 1;
    }
    else //if the guess not equal answer
    {
        return 0;
    }
} 

int occurencesInWord(char userguess, char answer[]) 
{
    int num = 0; 

    for (int i = 0; i < strlen(answer); i++) //for the length of answer
    {
        if (answer[i] == userguess) //if guess equals letter in answer
        {
            num++; 
        }
    }

    return num; //returns num value
} 

void updateStarWord(char starword[], char answer[], char userguess) 
{
    for (int i = 0; i < strlen(answer); i++) //for length of answer
    {
        if (answer[i] == userguess) //if letter guessed equals letter in answer
        {
            starword[i] = userguess; //set starword to the letter
        }
    }
} 

void maskWord(char starword[], int size)
{
    for (int i = 0; i < size; i++) //for the size of the string 
    {
        starword[i] = '*'; //conceal with stars
    }
}



void playAgain(int* play) 
{
    int temp; //creates temp variable

    printf("Would you like to play again?\n\n");

    printf("If yes, press 1.\n\n");

    printf("If no, press any key other than 1.\n\n");

    scanf(" %d", &temp); //scans for user input

    printf("\n");

    printf("\033[1;37m");

    printf("##########################################################################################\n\n");

    printf("\033[0;37m");

    if (temp == 1) //if int is 1
    {
        *play = 1; //play again
    }
    else //if int is not 1
    {
        *play = 0; //does not play again
    }
}