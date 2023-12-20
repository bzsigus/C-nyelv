#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

void displayMenu() {
    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Exit\n");
}

int main(int *argc, char *argv){


    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You selected Option 1.\n");
                // Add your code for Option 1 here
                break;
            case 2:
                printf("You selected Option 2.\n");
                // Add your code for Option 2 here
                break;
            case 3:
                printf("You selected Option 3.\n");
                // Add your code for Option 3 here
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;





}