// James Connolly
// Dr . Steinberg
// COP3223 Section 001
// Small Program 1

#include <stdio.h>

void someFunction();
void what(double* ptrx, double* ptry);

int main() {
	//Problem 1
	/*
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--------------\n");
	printf("--------------\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");

	//Problem 2

	
	int c1, c2, c3, c4, c5; //initializing all variables needed for problem 2

	printf("Enter the amount of eggs laid for each of the 5 chickens.\n");
	//chicken 1 input
	printf("Chicken 1: ");
	scanf_s("%d", &c1);

	//chicken 2 input
	printf("Chicken 2: ");
	scanf_s("%d", &c2);

	//chicken 3 input
	printf("Chicken 3: ");
	scanf_s("%d", &c3);

	//chicken 4 input
	printf("Chicken 4: ");
	scanf_s("%d", &c4);

	//chicken 5 input
	printf("Chicken 5: ");
	scanf_s("%d", &c5);

	int answer = (c1 + c2 + c3 + c4 + c5) / 12; //calculating the dozen(s)
	int remainder = (c1 + c2 + c3 + c4 + c5) % 12; //calculating the left over eggs
	
	printf("There are %d dozen(s) and %d egg(s) total. \n", answer, remainder);


	//Problem 3
	double interest, answer2, balance; //initializing all vars for problem 3

	printf("Let's calculate simple interest for an amount based on a duration of 5 years\nwith a rate of interest equal to 12.5%%.\n");
	
	printf("Enter the amount: ");
	scanf_s("%lf", &interest); //taking input for the interest

	 //calculating the total balance for the account and the interest that is added to the principal
	 answer2 = (interest * 12.5 * 5) / 100;
	 balance = answer2 + interest;

	printf("The interest for a principal amount of $%.2lf is $%.2lf. \n", interest, answer2);
	printf("The total balance will be $%.2lf.\n", balance);
	




	//Problem 4
	
	//initializing all necessary variables for problem 4
	double cradius, pbase, pheight, tbase, theight; 
	double pi = 3.141592;

	printf("Let's calculate the area of the 2D car drawing.\n");
	
	//circle prompt
	printf("Let's start with the 4 circles.\n");
	printf("Enter the radius: ");
	scanf_s("%lf", &cradius);
	double carea = (cradius * cradius) * pi * 4; //calculate circle area

	//parallelogram prompt
	printf("Now lets get the info on the parallelogram.\n");
	printf("Enter the base: ");
	scanf_s("%lf", &pbase);
	printf("Enter the height: ");
	scanf_s("%lf", &pheight);
	double parea = pbase * pheight;	//calculate parallelogram area

	//triangle prompt
	printf("Last, lets enter the information on the triangle.\n");
	printf("Enter the base: ");
	scanf_s("%lf", &tbase);
	printf("Enter the height: ");
	scanf_s("%lf", &theight);
	double tarea = (tbase * theight) / 2; 	//calculate triangle area


	//add up all areas to get answer for problem
	double answer4 = tarea + parea + carea;
	printf("The area of the 2D car is %.5lf units. ", answer4);
	

	*/
	someFunction();
	

double x;
double y;

printf("&x = %p\n", &x); //61FE1C
printf("&y = %p\n", &y); //61FE18

double* ptrx = &x;
double* ptry = &y;

printf("&ptrx = %p\n", &ptrx); //61FE10
printf("&ptry = %p\n", &ptry); //61FE08

what(ptrx, ptry);

printf("ptrx = %p\n", ptrx); // ??????
	//end program
	return 0;
}

void what(double* ptrx, double* ptry) {
	ptrx = ptry;

}


void someFunction()
{
	for (int i = 5; i > 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%d", i);
			printf("*");
		}
		printf("\n");
	}
}