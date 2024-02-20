//James Connolly
//Dr. Steinberg
//COP3223 Section 001
//Small Program 4

#include <stdio.h>

void countEvenOdd();
void drawShape();
void toyPhone();
void costPreview(int years, int percentage);

int main()
{
	//Problem 1
	countEvenOdd();

	//Problem 2
	drawShape();

	//Problem 3
	toyPhone();

	//Problem 4
	//declaring variables needed for problem
	int years, percentage;

	//while loop to continously check for invalid input
	while (1)
	{
		printf("Enter the number years to observe: ");
		scanf("%d", &years);

		printf("Enter the percentage rate to increase by per year: ");
		scanf("%d", &percentage);

		if (years <= 0 || percentage <= 0)
		{
			printf("Invalid input.\n");
		}
		//if all is correct this executes the function and breaks out of the loop
		if (years > 0 && percentage > 0)
		{
			costPreview(years, percentage);
			break;
		}

	}


	return 0;
}

void countEvenOdd() {
	int num;
	int oddTotal = 0;
	int countOdd = 0;
	int evenTotal = 0;
	int countEven = 0;

	while (1)
	{
		//Prompt user to enter numbers and collect input
		printf("Enter a positive integer: ");
		scanf("%d", &num);

		//checking to see if it is a valid input
		if (num < 0)
		{
			printf("That's a negative number!\n");
			//tried to use break here originally and that didnt work so i looked up alternatives and tried it out
			//instead of breaking out of the loop, it just skips to next iteration in the loop
			continue;
		}

		if (num == 0)
		{
			break;  //exits the while loop if num is 0
		}
		//if num is divisible by 2 it is even
		if (num % 2 == 0)
		{
			countEven++;
			evenTotal += num;
		}
		//if num is not divisible by 2 it is odd
		else
		{
			countOdd++;
			oddTotal += num;
		}
	}

	double evenAverage;
	double oddAverage;
	//Printing even results
	if (countEven > 0) {
		double evenAverage = (double)evenTotal / countEven;
		printf("%d even numbers were entered and the average is %lf\n", countEven, evenAverage);
	}
	//if no even number was entered this executes
	else
	{
		evenAverage = 0;
		printf("%d even numbers were entered and the average is %lf\n", countEven, evenAverage);
	}
	//Checking if the odd count is above 0 then calculates average
	if (countOdd > 0)
	{
		double oddAverage = (double)oddTotal / countOdd;
		printf("%d odd numbers were entered and the average is %lf\n", countOdd, oddAverage);

	}
	//if there are no odd numbers this executes
	else
	{
		oddAverage = 0;
		printf("%d odd numbers were entered and the average is %lf\n", countOdd, oddAverage);
	}
}

void drawShape()
{
	int rows;

	while (1)
	{
		printf("How many rows would you like the shape to have?: ");
		scanf("%d", &rows);

		if (rows <= 0)
		{
			printf("Invalid Input. Please try again.\n");
		}
		else 
		{
			break;
		}
	}
	//Nested for loop to create each row and pattern
	for (int i = 1; i <= rows; i++) 
	{
		for (int j = 1; j <= rows; j++) 
		{
			if (i == 1 || i == rows || j == 1 || j == rows || i == j) 
			{
				printf("*");
			}
			//prints the spaces before and after the star is placed per row
			else 
			{
				printf(" ");
			}
		}
		//Creates the new line for the loop to run all over again
		printf("\n");
	}
}

void toyPhone() 
{
	printf("Welcome to the Toy Phone!\n");


	while (1) 
	{
		int button;
		printf("Enter a button: ");
		scanf("%d", &button);

		//switch statement for every different possibility of button
		switch (button) 
		{
		case 1:
			printf("Hello!\n");
			break;
		case 2:
			printf("Loopy Loops!\n");
			break;
		case 3:
			printf("Programming is fun!\n");
			break;
		case 4:
			printf("Semicolons can be a pain to forget!\n");
			break;
		case 5:
			printf("Are you ready for pointers?\n");
			break;
		case 6:
			printf("Goodbye!\n");
			return;  // exits the loop
		default:
			printf("Invalid option.\n");
			break;
		}
	}
}

void costPreview(int years, int percentage) 
{
	double currentTuition = 20000.00;

	//Checking for invalid input
	if (years <= 0 || percentage <= 0) 
	{
		printf("Invalid input.\n");
		return;
	}
	//Printing the starting current tuition given to us
	printf("Current Tuition: $%.2lf\n", currentTuition);

	//Iterates as many times as the user specifies years 
	for (int i = 1; i <= years; i++) 
	{
		//Calculates tuition for each new year
		currentTuition += (currentTuition * percentage / 100.0);
		printf("Year %d: $%.2lf\n", i, currentTuition);
	}
}








