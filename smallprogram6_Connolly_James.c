//Gabriel Connolly
//Dr. Steinberg
//COP3223 Section 001
//Small Program 6

#include<stdio.h> 

void salesInfo(int arr[]); 
void testScoreInfo(double arr1[], int len); 
int removeDuplicates(int arr2[]); 
void mergeValues(int arr1[], int arr2[], int arr3[]);

int main() 
{
    //Problem 1

    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; 

    salesInfo(arr); //uses arr to fulfill sales info function

    //for loop to print the array indexes
    for (int i = 0; i < 9; i++) 
    {
        printf("sales[%d] = %d\n", i, arr[i]); 
    }

    //Problem 2

    double arr1[250] = {}; 

    double testScore = 0; //stores the test score
    int index = 0; 
    int length = 0;

    while (testScore >= 0 && index < 250) //input valid && still room in array
    {
        printf("Enter a score: ");

        //prompts user for test score
        scanf(" %lf", &arr1[index]); 

        testScore = arr1[index]; 

        length++; //adds 1 to the length

        //if input is invalid
        if (arr1[index] < 0) 
        {
            arr1[index] = -1;  
        }

        index++; //adds 1 to the index if valid
    }

    
    testScoreInfo(arr1, length); //takes user input and passes it to the function

    //Problem 3

    int arr2[15];

    //prompts user for input 15 times
    for (int i = 0; i < 15; i++)
    {
        printf("Enter an integer: ");

        scanf(" %d", &arr2[i]);
    }

    printf("Array before removing duplicates.\n");

    //prints array user just entered
    for (int i = 0; i < 15; i++)
    {
        printf("nums[%d] = %d\n", i, arr2[i]);
    }

    int var = removeDuplicates(arr2);

    printf("Array after removing duplicates.\n");

    for (int i = 0; i < var; i++)
    {
        printf("nums[%d] = %d\n", i, arr2[i]);
    }

    //Problem 4

    int arr1[5] = {};
    int arr2[5] = {};
    int arr3[5] = {};

    for (int i = 0; i < 5; i++)
    {
        printf("Enter an integer for arr1: ");

        scanf(" %d", &arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Enter an integer for arr2: ");

        scanf(" %d", &arr2[i]);
    }

    mergeValues(arr1, arr2, arr3);

    for (int i = 0; i < 5; i++)
    {
        printf("arr1[%d] = %d\t", i, arr1[i]);

        printf("arr2[%d] = %d\t", i, arr2[i]);

        printf("arr3[%d] = %d\n", i, arr3[i]);
    }

    return 0; 
}

void salesInfo(int arr[]) 
{
    double sale = 0; //total sales

    while (sale >= 0) //while input is valid
    {
        printf("Enter gross sale: ");

        scanf(" %lf", &sale); //prompts user to enter sale

        int total = 200 + (sale * 0.09); //calculates salary from input

        if (total <= 299) 
        {
            arr[0]++; //adds 1
        }
        else if (total <= 399) 
        {
            arr[1]++; 
        }
        else if (total <= 499) 
        {
            arr[2]++;
        }
        else if (total <= 599) 
        {
            arr[3]++; 
        }
        else if (total <= 699) 
        {
            arr[4]++; 
        }
        else if (total <= 799) 
        {
            arr[5]++; 
        }
        else if (total <= 899) 
        {
            arr[6]++; 
        }
        else if (total <= 999) 
        {
            arr[7]++; 
        }
        else 
        {
            arr[8]++; 
        }
    }
    arr[0]--; //subtracts 1 
}

void testScoreInfo(double arr1[], int len) 
{
    double highScore = arr1[0]; 

    double lowScore = arr1[0]; 

    double total = arr1[0];  

    int count = 1; //counts valid scores

    for (int i = 1; i < len; i++) 
    {
        if (arr1[i] > highScore) //if value is highest
        {
            highScore = arr1[i];  //set highscore to value
        }

        if (arr1[i] != 0) //if value is not 0
        {
            if (arr1[i] < lowScore) //if it is the lowest value
            {
                lowScore = arr1[i]; //set low score to new value
            }
            count++; //count + 1
        }

        total += arr1[i]; //adds value to total
    }

    printf("Highest Score: %.2lf\n", highScore); 

    printf("Lowest Score: %.2lf\n", lowScore); 

    printf("Average: %.2lf\n", total / count); //prints the average of the two values
}

int removeDuplicates(int arr2[])
{
    int num;

    for (int i = 0; i < 15; i++)
    {
        for (int p = 0; p < 15 - i; p++)
        {
            if (arr2[p] > arr2[p + 1])
            {
                num = arr2[p];
                arr2[p] = arr2[p + 1];
                arr2[p + 1] = num;
            }
        }
    }

    int size = 15;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr2[i] == arr2[j])
            {
                for (int p = j; p < size - 1; p++)
                {
                    arr2[p] = arr2[p + 1];
                }

                size--;

                j--;
            }
        }
    }

    return size;
}

void mergeValues(int arr1[], int arr2[], int arr3[])
{
    //merges values into diff arrays.
    for (int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}
