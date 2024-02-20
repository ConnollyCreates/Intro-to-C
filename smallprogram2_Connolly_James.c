//James Connolly
//Dr. Steinberg
//COP 3223 Section 001
//Small Program 2

#include <stdio.h>
#include <math.h>

//declaring all functions used for problems
double calcHypotenuse(double val1, double val2);
double rentalPrices();
int timeDisplay(int totalSeconds);
double mathFunction(double n);

int main()
{
	//problem 1
	double num1, num2;
	printf("Enter the value for a: ");
	scanf("%lf", &num1);
	printf("Enter the value for b: ");
	scanf("%lf", &num2);
	double answer = calcHypotenuse(num1, num2);
	printf("If a = %0.3lf and b = %0.3lf, then that means the hypotenuse is %0.3lf.\n", num1, num2, answer);


	//problem 2
	rentalPrices();


	//problem 3
	int seconds;
	printf("Enter the seconds: ");
	scanf("%d", &seconds);
	timeDisplay(seconds);


	//problem 4
	int n;
	double answer2;
	printf("Enter the value for n: ");
	scanf("%d", &n);
	answer2 = mathFunction(n);
	printf("The function computes the value %.3lf.\n", answer2);



	return 0;
}


double calcHypotenuse(double val1, double val2)
{
	//calculating values under the sqrt
	double c = (val1 * val1) + (val2 * val2);

	//calculating sqrt the value
	double answer = sqrt(c);

	return answer;
}


double rentalPrices()
{

	int days;

	printf("Hello Luis!\n");
	printf("Thank you for considering Hertz for your car rental needs.\n");
	printf("You have asked to compare prices for three vehicles.\n");

	//taking user input for amount of days needed
	printf("Please enter the number of days you plan to rent the vehicle: ");
	scanf("%d", &days);

	//Calculating Prices per rental vehicle
	double teslaModel = 46.48 * days;
	double chevyMalibu = 49.53 * days;
	double nissanRogue = 50.72 * days;

	//Returning those values
	printf("Here are the prices excluding tax.\n");
	printf("Tesla Model 3 Standard Range: $%0.2lf\n", teslaModel);
	printf("Chevrolet Malibu: $%0.2lf\n", chevyMalibu);
	printf("Nissan Rogue: $%0.2lf\n", nissanRogue);


	return 0;
}

int timeDisplay(int totalSeconds)
{
	int seconds = totalSeconds;
	int hoursTime = totalSeconds / 3600; //3600 seconds in a hour
	seconds = seconds % 3600;   //taking the leftover of that calculation
	int minutesTime = seconds / 60;  //that leftover is turned into minutes
	seconds %= 60; //the final leftover is the seconds that are left from the minute calculation

	if (totalSeconds >= 1 && totalSeconds <= 86400)  //making sure they enter a value in the range of 1 full day
	{
		printf("%d seconds is %d hours, %d minutes, and %d seconds.\n", totalSeconds, hoursTime, minutesTime, seconds);
	}
	else
	{
		printf("Please enter a value between 1 and 86400!\n");
	}

	return 0;
}

double mathFunction(double n)
{
	double number1, number2, number3, number4;

	number1 = (pow(n, n)) - (pow(2, n));
	number2 = (sqrt(n)) * (pow(n, 4));
	number3 = (exp(n - 2)) + 9;
	number4 = n * 8;

	return((number1 / (number2 / number3)) - number4);

}



