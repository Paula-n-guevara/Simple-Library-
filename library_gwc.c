
#include <stdio.h> //input and output operations
#include <stdlib.h> //standard library - like malloc 
#include <string.h> //string manipulation 
#include <getopt.h> //command line arg parsing -- not used here 
#include <errno.h> //error handling and reporting -- not used here 
/***

Step 1: Define the data structure- Determine what data structure you need to store the book inventory:

For this, I will be defining an array to hold in the books and prompting for user input 
***/

typedef struct {
    char *title; //title of the book 
    char *status; //the current status of the book 

} Book; //name of the struct

void return_book(Book *bookArray, int size){
    int choice; 

    printf("Enter the number of the book to return (or 0 to go back): ");
    scanf("%d", &choice);

    if (choice == 0) {
        return;
    } else if (choice < 1 || choice > size) {
        printf("Invalid choice. Please enter a number between 1 and %d.\n", size);
    } else if (strcmp(bookArray[choice - 1].status, "on shelf") == 0) {
        printf("\nThis book is already on the shelf.\n");
    } else {
        bookArray[choice - 1].status = "on shelf";
        printf("\nThanks for returning %s.\n", bookArray[choice - 1].title);
    }
}
int main() { //main function 
    int size = 0; //size of the array 
    Book *bookArray = NULL;  
    //hold the array of strings 
    char newTitle[100];
    int choice; 
    int menu_choice;

    printf("\nWelcome to your local library!\n");
    
    printf("\nEnter book titles to add (enter 'end' to stop):\n");
    
    /*
        This block of code adds titles into the library and only stops when 
        the user tells it to 'end'
    */ 
    do {

        printf("Title %d: ", size + 1); //size is = 1
        fgets(newTitle, sizeof(newTitle), stdin); //get new titles 
        newTitle[strcspn(newTitle, "\n")] = '\0'; //handles new line characters  

        if (strcmp(newTitle, "end") != 0) {
            size++;
            bookArray = (Book*) realloc(bookArray, size * sizeof(Book));
            bookArray[size - 1].title = (char*) malloc(strlen(newTitle) + 1); //for titles
            strcpy(bookArray[size - 1].title, newTitle);
            bookArray[size - 1].status = "on shelf"; //the default status is on shelf 
        }
    } while (strcmp(newTitle, "end") != 0); //as long as the user doesn't 
    //type in "end" continue the while loop 

    while (1){ //dont recc
    //use a switch instead 
    
    printf("\n_________________________________________________________\n");
    
    printf("\nBook titles and their status:\n");
    for (int i = 0; i < size; i++) { //iterate through the size of the array 
        printf("%d. %s (%s)\n", i + 1, bookArray[i].title, bookArray[i].status);
        //print the book title and the status 
    }

        printf("\nChoose an option:\n");
        printf("1. Check out a book\n");
        printf("2. Return a book\n");
        printf("0. Quit\n");
        printf("Your choice: ");
        scanf("%d", &menu_choice);   


          if (menu_choice == 0) {
            printf("\nThank you for checking our library! See you next time!\n\n");
            break;
        } else if (menu_choice == 1) {
            printf("\nEnter the number of the book to check out (or 0 to go back): ");
            scanf("%d", &choice);

            if (choice == 0) {
                continue;
            } else if (choice < 1 || choice > size) {
                printf("Invalid choice. Please enter a number between 1and %d.\n", size);
    } else if (strcmp(bookArray[choice - 1].status, "checked out") == 0) {
        printf("\nSorry, that book is already checked out.\n");
} else {
    bookArray[choice - 1].status = "checked out";
    printf("\nGreat selection! You checked out %s.\n", bookArray[choice - 1].title);
    printf("We still have a selection of books if you'd like to see!\n");
    }
} else if (menu_choice == 2) {
    return_book(bookArray, size);
} else {
    printf("\nInvalid choice. Please choose a valid option.\n");
}
}



    for (int i = 0; i < size; i++) {
        free(bookArray[i].title); //free memory 
        free(bookArray[i].status); 
    }
    free(bookArray); 

    return 0; //end 
}
