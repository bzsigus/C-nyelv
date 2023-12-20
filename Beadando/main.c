#include <stdio.h>
#include <stdlib.h>


void displayMenu(void);

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
                printf("Option 4.\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

}

void displayMenu(void) {
    printf(" ---------------------\n");
    printf("|Welcome in the Matrix|\n");
    printf(" --------------------- \n");
    printf("   Your Options:\n");
    printf("    1 - User Manual\n");
    printf("    2 - Generate matrix\n");
    printf("    3 - Load Mátrix:\n");
    printf("    4 - Save Matrix:\n");
    printf("    5 - exit\n");
}