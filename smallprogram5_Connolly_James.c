// James Connolly
// Dr . Steinberg
// COP3223 Section 001
// Small Program 5

#include <stdio.h>

//Prototyping all functions
void pickButton(int* selectedButton);
void match();
void blockbuster();
void numberFacts();


int main()
{
    //Problem 1
    int selectedButton = 0;
    int* sbp = &selectedButton;
    pickButton(sbp);

    //Problem 2
    match();

    
    //Problem 3
    blockbuster();

    //Problem 4
    numberFacts();
    return 0;
}

//Problem 1
void pickButton(int* selectedButton) {
    printf("Choose a button.\n");
    printf("1. Blue Button\n");
    printf("2. Green Button\n");
    printf("3. Yellow Button\n");
    printf("4. Red Button\n");
    printf("5. Gold Button\n");
    printf("6. Black Button\n");
    printf("7. White Button\n");
    printf("Selection: ");

    scanf(" %d", selectedButton); //Gathering user input for selection

    if (*selectedButton > 7 || *selectedButton <1) 
    {
        printf("Invalid Button Selected!\n");
        *selectedButton = -1;  // Use -1 to show an invalid selection

    }
    else 
    {   //Run through all the possible selection options
        switch (*selectedButton)
        {
        case 1:
            printf("Blue Button Selected!\n");
            break;
        case 2:
            printf("Green Button Selected!\n");
            break;
        case 3:
            printf("Yellow Button Selected!\n");
            break;
        case 4:
            printf("Red Button Selected!\n");
            break;
        case 5:
            printf("Gold Button Selected!\n");
            break;
        case 6:
            printf("Black Button Selected!\n");
            break;
        case 7:
            printf("White Button Selected!\n");
            break;
        }
    }
}

//Problem 2
void match()
{
    //Creating the file pointers
    FILE *mput1; 
    FILE *mput2; 
    FILE *mput3; 

    //Giving the input files access to the grades
    mput1 = fopen("grades1.txt", "r"); 
    mput2 = fopen("grades2.txt", "r"); 
    mput3 = fopen("grades3.txt", "r"); 

    char grade1, grade2, grade3; //creating placeholders to check grades
    

    int status = 0; //true or false int

    //while the scanner hasnt reached the end of the file
    while ((fscanf(mput1, " %c", &grade1) != EOF) && (fscanf(mput2, " %c", &grade2) != EOF) && (fscanf(mput3, " %c", &grade3) != EOF))
    {
        if (!(grade1 == grade2 && grade1 == grade3)) //if the letter grades are not equal
        {
            status = 1; //update value to not equal
        }
    }

    if (status == 1) //if the grades arent equal
    {
        printf("No Match!\n");
    }
    else //if the grades are equal
    {
        printf("Match!\n");
    }
}

void blockbuster() 
{
    //Creating input and output file pointers
    FILE* input; 
    FILE* output; 

    input = fopen("sales.txt", "r"); //allows input to read the sales file
    output = fopen("recordsales.txt", "w"); //allows output to write to recordsales

    int customerID, videos; 
    
    double cost = 2.99; //total cost to rent vid
    double total = 0.00; //total of how much customer spent
    double customerSpent; //shows how much each individual spent

    printf("Retrieving the Records from today's sale!\n");

    //while input hasnt reached the end of the file
    while (fscanf(input, " %d %d", &customerID, &videos) != EOF)
    {
        customerSpent = videos * cost; //calculates how myc
        total += customerSpent; //adds how much each customer spent to the total

        //terminal
        printf("Customer: %d\t", customerID);
        printf("Spent: $%.2lf\n", customerSpent);

        //text file
        fprintf(output, "Customer: %d\t", customerID);
        fprintf(output, "Spent: $%.2lf\n", customerSpent);
    }

    //terminal
    printf("-----------------------------\n");
    printf("$%.2lf was made today.\n", total);

    //text file
    fprintf(output, "-----------------------------\n");
    fprintf(output, "$%.2lf was made today.\n", total);
}


void numberFacts() 
{
    FILE* output;
    output = fopen("numfact.txt", "w"); //allows output to write to numfact

    int numberChoice; 
    
    printf("Number\tPart A\tPart B\tPart C\n"); 
    fprintf(output, "Number\tPart A\tPart B\tPart C\n"); 

    while (1) //while true
    {
        printf("Enter a positive integer: ");
        scanf(" %d", &numberChoice); //user enters a number

        if (numberChoice < 1) //invalid choice
        {
            break; 
        }
        else //valid choice
        {
            printf("%d\t", numberChoice); //print to console
            fprintf(output, "%d\t", numberChoice); //print to text file

            //checking for multiples of 7, 11, or 13
            if ((numberChoice % 7 == 0) || (numberChoice % 11 == 0) || (numberChoice % 13 == 0))
            {
                printf("Yes!\t"); 
                fprintf(output, "Yes!\t"); 
            }
            else //not a multiple 
            {
                printf("No!\t"); 
                fprintf(output, "No!\t"); 
            }

            if (numberChoice % 2 == 0) //even number
            {
                printf("Even\t"); 
                fprintf(output, "Even\t"); 
            }
            else //odd number
            {
                printf("Odd\t"); 
                fprintf(output, "Odd\t"); 
            }

            int choice = 0;
            for (int i = 2; i < numberChoice; i++) //counts from 2 to given number
            {
                if (numberChoice % i == 0) //if i is a multiple of the number
                {
                    choice = 1; //sets to 1
                }
            }

            if (choice == 1) //if number is composite
            {
                printf("Composite\n"); 
                fprintf(output, "Composite\n"); 
            }
            else //if number is prime
            {
                printf("Prime\n"); 
                fprintf(output, "Prime\n"); 
            }
        }
    }
}