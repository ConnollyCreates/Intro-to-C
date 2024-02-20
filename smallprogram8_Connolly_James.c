// James Connolly
// Dr. Steinberg
// COP3223 Section XXX
// Small Program 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LIMIT 50

typedef struct {
    char* fname; //first name
    char* lname; //last name
    char* show; //favorite show
} record_t;

record_t* createArray(int maxsize);
record_t* insert(record_t* myarray, int* maxsize, int* currentsize);
void display(record_t* myarray, int currentsize);
record_t* doubleIt(record_t* arr, int* size);
int removeRecord(record_t* arr, int* size, int index);
void freeRecords(record_t* arr, int* size);
void chomp(char word[]);
void clear_buffer();

int main(void) {
    int maxsize;
    printf("Enter a size for the dynamic array: ");
    scanf("%d", &maxsize);
    record_t* myarray = createArray(maxsize);
    int currentsize = 0;
    int option = -1;
    while (option != 0) {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Insert was selected...\n");
            myarray = insert(myarray, &maxsize, &currentsize);
            break;
        case 2:
            printf("Display was selected...\n");
            display(myarray, currentsize);
            break;
        case 3:
            printf("Remove was selected...\n");
            printf("Select an index of record to remove...\n");
            int index;
            scanf("%d", &index);
            currentsize = removeRecord(myarray, &currentsize, index);
            break;
        case 4:
            printf("Exiting...\n");
            option = 0;
            break;
        default:
            printf("Invalid Selection...\n");
        }
    }
    //calls freeRecords function
    freeRecords(myarray, &currentsize);

    //frees myarray
    free(myarray);

    myarray = NULL;
    return 0;
}

//Creates the array that user provides max size for
record_t* createArray(int maxsize) {
    record_t* arr = malloc(maxsize * sizeof(record_t));
    if (arr == NULL) {
        printf("malloc error in createArray...program exiting\n");
        exit(1);
    }
    return arr;
}

//Function that Displays array
void display(record_t* myarray, int currentsize) {
    printf("---------------------------------\n");
    for (int x = 0; x < currentsize; ++x) {
        printf("myarray[%d].fname = %s\n", x, myarray[x].fname);
        printf("myarray[%d].lname = %s\n", x, myarray[x].lname);
        printf("myarray[%d].show = %s\n", x, myarray[x].show);
    }
    printf("---------------------------------\n");
}

record_t* insert(record_t* myarray, int* maxsize, int* currentsize) {
    if (*currentsize >= *maxsize) {
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, maxsize);
        if (myarray == NULL) {
            printf("malloc error in insert...program exiting\n");
            exit(1);
        }
    }

    char temp_fname[LIMIT], temp_lname[LIMIT], temp_show[LIMIT];

    clear_buffer(); // Clear input buffer before new input
    printf("Enter the first name: ");
    fgets(temp_fname, sizeof(temp_fname), stdin); //gets input
    chomp(temp_fname);

    printf("Enter the last name: ");
    fgets(temp_lname, sizeof(temp_lname), stdin);
    chomp(temp_lname);

    printf("Enter favorite show: ");
    fgets(temp_show, sizeof(temp_show), stdin);
    chomp(temp_show);

    myarray[*currentsize].fname = strdup(temp_fname);
    myarray[*currentsize].lname = strdup(temp_lname);
    myarray[*currentsize].show = strdup(temp_show);

    (*currentsize)++; //adds to current size
    return myarray;
}

record_t* doubleIt(record_t* arr, int* size) {
    *size *= 2;
    record_t* newarr = realloc(arr, *size * sizeof(record_t));
    if (newarr == NULL) {
        printf("malloc error in doubleIt...program exiting\n");
        exit(1);
    }
    return newarr;
}

int removeRecord(record_t* arr, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid Index\n");
        return *size;
    }

    free(arr[index].fname);
    free(arr[index].lname);
    free(arr[index].show);

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    return *size;
}

//Frees outstanding memory
void freeRecords(record_t* arr, int* size) {
    for (int i = 0; i < *size; i++) {
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }
}

void chomp(char word[]) {
    if (word[strlen(word) - 1] == '\n')
        word[strlen(word) - 1] = '\0';
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
