//James Connolly
//Dr. Steinberg
//COP3223 Section 001
//Small Program 7


#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chomp(char word[]);
void lastWordLength(char sentence[]);
void truncateSentence(char sentence[], int n);
int strongPasswordCheck(char password[]);
int romanNumeral(char roman[]);
int main()
{

    //Problem 1
    char input_sentence[500]; // Assuming a maximum sentence length of 500 characters
    printf("Enter a sentence: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);
    chomp(input_sentence);
    // Call the function to determine the length of the last word
    lastWordLength(input_sentence);

    //Problem 2
    char trun_input[500];
    int trunLen = 0;
    printf("Enter a sentence: ");
    fgets(trun_input, sizeof(trun_input), stdin);
    chomp(trun_input);
    printf("Truncate sentence to how many words: ");
    scanf("%d", &trunLen);
    truncateSentence(trun_input, trunLen);

    //Problem 3
    char password[500];
    printf("Enter your password: ");
    scanf(" %s", password);
    chomp(password);
    
    int check = strongPasswordCheck(password);
    if (check)
    {
        printf("%s is a strong password.\n", password);
    }
    else {
        printf("%s is not a strong password.\n", password);
    }

    //Problem 4
    char romanNum[30]; //create roman number string
    printf("Enter a roman numeral: ");
    scanf(" %s", romanNum); //scan for string
    int convertedNum = romanNumeral(romanNum); //call function
    printf("%s = %d\n", romanNum, convertedNum);



	return 0;
}

void chomp(char word[]) 
{
    if (word[strlen(word) - 1] == '\n') //if last character is a new line character
    {
        word[strlen(word) - 1] = '\0'; //replace with null
    }
} 


void lastWordLength(char sentence[]) {
    int count, temp = 0; //counting variables

    for (int i = 0; i < strlen(sentence); i++) //traverse sentence from left to right
    {
        if (isalpha(sentence[i]) != 0) //if there is a letter
        {
            temp++; //add to temporary counter

            if (sentence[i + 1] == '\0') //if there is a null value
            {
                count = temp; //set counter to temporary value
            }
        }
        else if (isalpha(sentence[i]) == 0) //if there is no letter
        {
            if (temp != 0) //if temp is != 0
            {
                count = temp; //set counter to temp
            }

            temp = 0; //reset temp counter
        }
    }

    printf("Length of last word in \"");
    fputs(sentence, stdout); //output sentence
    printf("\" is %d.\n", count);
}

void truncateSentence(char sentence[], int n)
{
    int length = strlen(sentence);
    int wordCount = 0;

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            wordCount++;
            if (wordCount == n) {
                sentence[i] = '\0'; // Replace the space with null character to truncate the sentence
                break;
            }
        }
    }
    printf("Truncated sentence is \"");
    fputs(sentence, stdout); //output sentence
    printf("\" \n");

}

int strongPasswordCheck(char password[]) 
{
    int length = strlen(password);
    int characters = 0, lowerCase = 0, upperCase = 0, numbers = 0, repeat = 0;

    for (int i = 0; i < strlen(password); i++) 
    {
        if (isalpha(password[i]) != 0) //if it is a letter
        {
            characters++; 

            if (isupper(password[i]) != 0) //if it is uppercase
            {
                upperCase++; 
            }
            else //it is lowercase
            {
                lowerCase++; 
            }
        }

        if (isdigit(password[i]) != 0) //if it is a digit
        {
            numbers++; 
        }
    }

    for (int i = 0; i < length - 2; i++) //for length of password minus 2
    {
        //If three consecutive characters are equal to each other
        if ((toupper(password[i]) == toupper(password[i + 1])) && (toupper(password[i + 1]) == toupper(password[i + 2])))
        {
            repeat = 1; //set repeat to 1
        }
    }

    if (length >= 6 && length <= 20) //checking password to make sure it fits size parameters
    {
        if (lowerCase >= 1) //it has 1 or more lowercase
        {
            if (upperCase >= 2) //it has 2 or more uppercase
            {
                if (numbers >= 3) //it has 3 or more numbers
                {
                    if (repeat == 0) //it never repeated itself
                    {
                        return 1; //password is strong
                    }
                    else
                    {
                        return 0; //password is weak
                    }
                }
                else
                {
                    return 0; 
                }
            }
            else
            {
                return 0; 
            }
        }
        else
        {
            return 0; 
        }
    }
    else
    {
        return 0; 
    }
} 

int romanNumeral(char roman[])
{
    int result = 0;
    int i = 0;

    while (roman[i] != '\0') {
        // Check for subtractive pairs
        if (roman[i] == 'I' && (roman[i + 1] == 'V' || roman[i + 1] == 'X')) {
            result -= 1;
        }
        else if (roman[i] == 'X' && (roman[i + 1] == 'L' || roman[i + 1] == 'C')) {
            result -= 10;
        }
        else if (roman[i] == 'C' && (roman[i + 1] == 'D' || roman[i + 1] == 'M')) {
            result -= 100;
        }
        else {
            // Add the value of the current Roman numeral character
            switch (roman[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                printf("Invalid Roman numeral character: %c\n", roman[i]);
                return -1; // Error code for invalid input
            }
        }
        i++;
    }

    return result;
}
