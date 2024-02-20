//James Connolly
//Dr. Steinberg
//COP3223 Section 1
//Large Program 4

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//max amount students in gradebook
#define MAX_STUDENTS 5

// Struct for student
typedef struct {
    char fullName[50];
    double homeworkAvg;
    double quizAvg;
    double examAvg;
} student_t;

// Array to hold students
student_t gradeBook[MAX_STUDENTS];
int currentStudents = 0;

// Function prototypes
void addStudent(); //add student to grade book
void removeStudent(); //remove student from grade book
void updateGrades(); //update a students grades
void printGrades(); //print all students grades
void missingGrades(); //display students with missing grades
void displayMenu(); //displays the selection choices
void searchStudent(); //search for a student individually
bool isGradeBookFull(); //checks if grade book is full

int main() //main function
{
    int choice;

    //Brings up choice menu if not exiting program
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            updateGrades();
            break;
        case 4:
            printGrades();
            break;
        case 5:
            missingGrades();
            break;
        case 6:
            searchStudent();
            break;
        case 7:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    FILE* file = fopen("gradebook.txt", "w");

    //If the file does not exist
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    //Prints information to file

    fprintf(file, "Student Grades:\n");
    for (int i = 0; i < currentStudents; i++)
    {
        fprintf(file, "Name: %s\n", gradeBook[i].fullName);
        fprintf(file, "Homework Average: %.2lf\n", gradeBook[i].homeworkAvg);
        fprintf(file, "Quiz Average: %.2lf\n", gradeBook[i].quizAvg);
        fprintf(file, "Exam Average: %.2lf\n", gradeBook[i].examAvg);
        double weightedAverage = (gradeBook[i].homeworkAvg * 0.5) + (gradeBook[i].quizAvg * 0.2) + (gradeBook[i].examAvg * 0.3);
        fprintf(file, "Weighted Average: %.2lf\n\n", weightedAverage);
    }

    fclose(file); //closes file

    return 0;
}

// Function to display the menu
void displayMenu() 
{
    printf("\nMenu:\n");
    printf("1. Add a student\n");
    printf("2. Remove a student\n");
    printf("3. Update student's grades\n");
    printf("4. Print all students' grades\n");
    printf("5. Students with missing grades\n");
    printf("6. Search for a student\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

// Function to check if the grade book is full
bool isGradeBookFull() 
{
    return currentStudents >= MAX_STUDENTS;
}

// Function to add a student
void addStudent() 
{
    if (isGradeBookFull()) 
    {
        printf("Grade book is full. Cannot add more students.\n");
        return;
    }

    printf("Enter student's full name: ");
    scanf(" %[^\n]s", gradeBook[currentStudents].fullName);
    gradeBook[currentStudents].homeworkAvg = 0.0;
    gradeBook[currentStudents].quizAvg = 0.0;
    gradeBook[currentStudents].examAvg = 0.0;

    //adds a student
    currentStudents++;

    printf("Student added successfully.\n");
}

// Function to remove a student
void removeStudent() 
{
    if (currentStudents == 0) 
    {
        printf("No students in the grade book.\n");
        return;
    }

    char nameToRemove[50];
    printf("Enter student's full name to remove: ");
    scanf(" %[^\n]s", nameToRemove);

    bool found = false;
    for (int i = 0; i < currentStudents; i++) 
    {
        if (strcmp(nameToRemove, gradeBook[i].fullName) == 0) 
        {
            for (int j = i; j < currentStudents - 1; j++) 
            {
                gradeBook[j] = gradeBook[j + 1];
            }
            found = true;
            break;
        }
    }

    if (found) 
    {
        currentStudents--;
        printf("Student removed successfully.\n");
    }
    else {
        printf("Student not found in the grade book.\n");
    }
}

// Function to update student's grades
void updateGrades() 
{
    if (currentStudents == 0) 
    {
        printf("No students in the grade book.\n");
        return;
    }

    char nameToUpdate[50];
    printf("Enter student's full name to update grades: ");
    scanf(" %[^\n]s", nameToUpdate);

    bool found = false;
    for (int i = 0; i < currentStudents; i++) 
    {
        if (strcmp(nameToUpdate, gradeBook[i].fullName) == 0) 
        {
            printf("Enter homework average: ");
            scanf("%lf", &gradeBook[i].homeworkAvg);
            printf("Enter quiz average: ");
            scanf("%lf", &gradeBook[i].quizAvg);
            printf("Enter exam average: ");
            scanf("%lf", &gradeBook[i].examAvg);

            found = true;
            printf("Grades updated successfully.\n");
            break;
        }
    }

    if (!found) 
    {
        printf("Student not found in the grade book.\n");
    }
}

// Function to print all students' grades
void printGrades() 
{
    if (currentStudents == 0) 
    {
        printf("No students in the grade book.\n");
        return;
    }
   

    printf("Student Grades:\n");
    for (int i = 0; i < currentStudents; i++) 
    {
        
        //If student does not have their grades entered
        if (gradeBook[i].homeworkAvg == 0 || gradeBook[i].examAvg == 0 || gradeBook[i].quizAvg == 0)
        {
            printf("%s does not have all of their grades entered yet\n", gradeBook[i].fullName);
            break;
        }
        //Prints if they do have grades
        printf("Name: %s\n", gradeBook[i].fullName);
        printf("Homework Average: %.2lf\n", gradeBook[i].homeworkAvg);
        printf("Quiz Average: %.2lf\n", gradeBook[i].quizAvg);
        printf("Exam Average: %.2lf\n", gradeBook[i].examAvg);
        //Calculates final average
        double weightedAverage = (gradeBook[i].homeworkAvg * 0.5) + (gradeBook[i].quizAvg * 0.2) + (gradeBook[i].examAvg * 0.3);
        printf("Weighted Average: %.2lf\n\n", weightedAverage);
    }
}

// Function to find students with missing grades
void missingGrades() 
{
    if (currentStudents == 0) 
    {
        printf("No students in the grade book.\n");
        return;
    }

    printf("Students with Missing Grades:\n");
    bool missing = false;
    for (int i = 0; i < currentStudents; i++) 
    {
        if (gradeBook[i].homeworkAvg == 0.0 || gradeBook[i].quizAvg == 0.0 || gradeBook[i].examAvg == 0.0) {
            printf("%s\n", gradeBook[i].fullName);
            missing = true;
        }
    }
    //If all students has their grades
    if (!missing) 
    {
        printf("All students have entered their grades.\n");
    }
}

//Function to search for a specific student in book
void searchStudent() 
{
    if (currentStudents == 0) 
    {
        printf("No students in the grade book.\n");
        return;
    }

    char nameToSearch[50];
    printf("Enter student's full name to search: ");
    scanf(" %[^\n]s", nameToSearch);

    bool found = false;
    for (int i = 0; i < currentStudents; i++) 
    {
        if (strcmp(nameToSearch, gradeBook[i].fullName) == 0) 
        {
            printf("Student found!\n");
            printf("Name: %s\n", gradeBook[i].fullName);
            printf("Homework Average: %.2lf\n", gradeBook[i].homeworkAvg);
            printf("Quiz Average: %.2lf\n", gradeBook[i].quizAvg);
            printf("Exam Average: %.2lf\n", gradeBook[i].examAvg);
            double weightedAverage = (gradeBook[i].homeworkAvg * 0.5) + (gradeBook[i].quizAvg * 0.2) + (gradeBook[i].examAvg * 0.3);
            printf("Weighted Average: %.2lf\n", weightedAverage);
            found = true;
            break;
        }
    }

    if (!found) 
    {
        printf("Student not found in the grade book.\n");
    }
}

