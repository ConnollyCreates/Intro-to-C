//James Connolly
//Dr. Steinberg
//COP 3223 C Section 001
//Small Program 3
#include <stdio.h>
#include <ctype.h>

int creditCheck(double price);
void universityAdmissions(double gpa , int testScore);
void keyPad();
double carpenter();

int main()
{
	//Problem 1
	double pricePoint;
	int result;
	
	//Prompting User and storing price.
	printf("Enter the price: ");
	scanf("%lf", &pricePoint);

	//The variable result is equal to what the function produces given the price the user entered
	result = creditCheck(pricePoint);

	//Giving results based upon what the user entered and function determined
	if(result == 1) 
	{
		printf("Approved!\n");
	} 
	else if(result == 0)
	{
		printf("Not Approved!\n");
	}

	//Problem 2

	double gpaHolder;
	int tsHolder;
	printf("Welcome to the University Admission System!\n");
	
	//Collecting the gpa and storing it in a variable
	printf("Enter the GPA: ");
	scanf("%lf", &gpaHolder);

	//Collecting the test score an storing it in a variable
	printf("Enter the test score: ");
	scanf("%d", &tsHolder);
	
	//Calling the function using the 2 values input by the user
	universityAdmissions(gpaHolder, tsHolder);
		

	//Problem 3
	
	keyPad();


	//Problem 4
	double totalCost = carpenter();

	if (totalCost < 0) 
	{
		printf("Could not compute cost...\n");
	}
	else 
	{
		printf("Bruce will charge $%.2lf.\n", totalCost);
	}


	return 0;
}

int creditCheck(double price)
{
	//Checking if purchase falls within credit range
	if (price <= 9000 && price >= 0)
	{
		return 1;
	
	}
	//Checking for invalid input
	else if (price < 0)
	{
		printf("Error!\n");

	}
	//If input is valid but too much returns false and is not approved
	else 
	{
		return 0;
	}
	
	
	
}

//Function returns nothing so void is used, takes 2 arguments
void universityAdmissions(double gpa, int testScore)
{
	//Checking requirements for admission
	if (gpa >= 3.00 && testScore >= 60)
	{
		printf("Admissions is Approved!\n");

		//Checking requirements for scholarship if admission is approved
		if (gpa >= 3.50 && testScore >= 70)
		{
			printf("Consider for Scholarship Award!\n");
		}
	} 
	//Checking lower requirements for admission without scholarship considertaion
	else if (gpa < 3.00 && gpa >= 2.00 && testScore >= 80)
	{
		printf("Admissions is Approved!\n");
	}

	//Checking for invalid input
	else if (gpa < 0 || testScore < 0) 
	{
		printf("Invalid Input!\n");
	}
	
	//If input is valid but doesnt meet requirements admission is denied
	else 
	{
		printf("Admissions is Denied!\n");
	}
	
}

//Function returns nothing so void is used
void keyPad()
{
	int optionSelect;

	//Prompting user to input
	printf("Welcome to the Crazy Keypad!\n");
	printf("Select one of the following options for a message.\n");
	printf("Option 1\n");
	printf("Option 2\n");
	printf("Option 3\n");
	printf("Option 4\n");
	printf("Option 5\n");

	//Collecting User Input for option selected
	printf("Option Selected: "); 
	scanf("%d", &optionSelect);

	//Creating a switch statement for each case of the option selected
	switch (optionSelect)
	{
	case 1:
		printf("Opening Vault 712...\n");
		break;

	case 2:
		printf("Opening Secret Elevator...\n");
		break;

	case 3:
		printf("Calling the Boss...\n");
		break;

	case 4:
		printf("Backup on the way...\n");
		break;
	
	case 5:
		printf("Alarm activated...\n");
		break;

		//If none of the options or chosen or invalid input then the system stays locked
	default:
		printf("System Locked...\n");
	}
}

double carpenter() {

	//declaring all variables needed
	double baseCharge = 30;
	double oakCharge = 15;
	double charCost = 2;
	double gldLeafCost = 12;
	double totalCost = baseCharge;
	char oakChoice, gldLeafChoice;
	int numCharacters;

	//Initial Prompt
	printf("Welcome to Bruce's Carpentry Services!\n");
	printf("Would you like the sign made out of oak?\n");

	//Collecting Input for Oak choice
	printf("Enter y for yes or n for no: ");
	scanf(" %c", &oakChoice); 

	//Making sure that Y is case INsensitive 
	if (tolower(oakChoice) == 'y') 
	{
		totalCost += oakCharge;
		//adding the oak charge to total cost if they say yes
	}

	//Checking for invalid input (any other letter than N or n)
	else if (tolower(oakChoice) != 'n') 
	{
		return -1.0; //return a negative value to terminate
	}

	//Prompting for total amount of characters
	printf("Enter the number of characters on the sign: ");
	scanf("%d", &numCharacters);

	//Checking for invalid input
	if (numCharacters != 1 || numCharacters < 0) 
	{
		return -1.0; //return a negative value
	}

	//Calculating total cost if total characters is above 5
	if (numCharacters > 5) 
	{
		totalCost += (numCharacters - 5) * charCost;
	}

	//Prompting for gold leaf lettering
	printf("Would you like gold-leaf lettering?\n");
	printf("Enter y for yes or n for no: ");
	scanf(" %c", &gldLeafChoice); 
	
	//Adding to toal cost if chosen yes
	if (tolower(gldLeafChoice) == 'y') 
	{
		totalCost += gldLeafCost;
	}
	
	//Checking for invalid input 
	else if (tolower(gldLeafChoice) != 'n') 
	{
		return -1.0; //Return the negative value
	}

	//return the total cost back to the main function when called
	return totalCost;
}

