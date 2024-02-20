//James Connolly
//Dr. Steinberg
//COP3223 Section 1
//Large Program 2

#include <stdio.h>


void greeting(); //welcome the user to the coffee shop
void order(double* balance); //user will make a purchase
void viewAccount(double* balance); //display current account balance of user
void transaction(double* balance, double price); //transaction with user account
void reload(double* balance); //reload your account balance
void displayMenu(); //display beverage/food options and prices

int main() 
{
    int userInput;
    double balance = 0.00;
    double* total = &balance;
    
	greeting();
   

    while (userInput != 0)
    {

        printf("--------------\n");
        printf("Choose an option below\n");
        printf("0: Exit Knightro's :(\n");
        printf("1: View the Menu\n");
        printf("2: Place an order\n");
        printf("3: View your account\n");
        printf("4: Reload your account balance\n");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 0:
            printf("Have a good one!");
            break;
        case 1:
            displayMenu();
            break;
        case 2:
            order(total);
            break;
        case 3:
            viewAccount(total);
            break;
        case 4:
            reload(total);
            break;
        default:
            printf("Please choose a valid option\n");
            break;

        }
    }
    return 0;
}

//greets user
void greeting() 
{
	printf("Welcome to Knightro's Coffee Shop!!! :)))\n");

}


//allows user to order 
void order(double* balance) 
{
    int selection;
    printf("Please order from the choices below!\n");
    printf("1-Hot Coffee is $3.53\n");
    printf("2-Iced Coffee is $4.20\n");
    printf("3-Hot Latte is $3.13\n");
    printf("4-Iced Latte is $4.12\n");
    printf("5-Bagel(includes cream cheese) is $3.99\n");
    printf("6-Big Scone is $4.99\n");
    printf("7-Frozen Coffee is $5.03\n");
    printf("8-Bottle Water is $1.50\n\n");
    scanf(" %d", &selection); //stores users selection

    switch (selection) //switch statement for all possible cases
    {
    case 1:
        printf("You ordered coffee!\n");
        transaction(balance, 3.53);
        break;
    case 2:
        printf("You ordered an Ice Coffee!\n");
        transaction(balance, 4.20);
        break;
    case 3:
        printf("You ordered a hot latte!\n");
        transaction(balance, 3.13);
        break;
    case 4:
        printf("You ordered an Iced latte!\n");
        transaction(balance, 4.12);
        break;
    case 5:
        printf("You ordered a bagel with cream cheese!\n");
        transaction(balance, 3.99);
        break;
    case 6:
        printf("You ordered a big scone!\n");
        transaction(balance, 4.99);
        break;
    case 7:
        printf("You ordered a frozen coffee!\n");
        transaction(balance, 5.03);
        break;
    case 8:
        printf("You ordered a bottle water!\n");
        transaction(balance, 1.50);
        break;
    default:
        printf("Please enter a valid input;\n");
        break;
    }


}

void viewAccount(double* balance)  //allows user to view account balance
{

    printf("-----------------------------------------------\n");
    printf("The current balance of your account is $%.2lf.\n", *balance); //prints balance of account currently

}

//handles the process of making a transaction with a user
void transaction(double* balance, double price) 
{
    //if they do not have enough money
    while (price > *balance)
    {
        printf("You cannot purchase this! Please reload your account!\n");
        reload(balance);
    }

    //successful purchase message
    *balance -= price;
    printf("You have successfully purchased an item!\n");
}

void reload(double* balance) 
{
    double money = 0;
    printf("How much money would you like to put in your account?\n");
    scanf(" %lf", &money); //collects users input on how much they would like to add
    *balance += money; //adds the money the user just input to the balance

}


//displays the menu for the user
void displayMenu() 
{
    printf("This is our menu!!\n\n");
    printf("Hot Coffee is $3.53\n");
    printf("Iced Coffee is $4.20\n");
    printf("Hot Latte is $3.13\n");
    printf("Iced Latte is $4.12\n");
    printf("Bagel(includes cream cheese) is $3.99\n");
    printf("Big Scone is $4.99\n");
    printf("Frozen Coffee is $5.03\n");
    printf("Bottle Water is $1.50\n\n");

}