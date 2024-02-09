#include <stdio.h>

int main() {
    int rows, i, j;

    // Get the number of rows from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop to print the hollow full pyramid pattern
    for (i = 1; i <= rows; i++) {
        // Print spaces for the left pyramid
        for (j = i; j < rows; j++) {
            printf(" ");
        }

        // Print stars for the upper boundary of the pyramid
        for (j = 1; j <= (2 * i - 1); j++) {
            if (j == 1  || i==rows) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
