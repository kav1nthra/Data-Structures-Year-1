#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations for checking different number types
void Palindrome(int* num);
void Armstrong(int* num);
void Perfect(int* num);

int main() {
    // Dynamic memory allocation for choice and number
    int* choice = (int*)malloc(sizeof(int));
    int* number = (int*)malloc(sizeof(int));

    if (choice == NULL || number == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Displaying menu options
    printf("Menu Card\n");
    printf("Enter 1: To check for Palindrome number\n");
    printf("Enter 2: To check for Armstrong number\n");
    printf("Enter 3: To check for Perfect number\n");
    printf("Enter 4: To Exit the program\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", choice);

        if (*choice == 4) {
            printf("Program ended\nThank you\n");
            break;
        }

        printf("Enter the number: ");
        scanf("%d", number);

        // Switch case to call the appropriate function
        switch (*choice) {
            case 1:
                Palindrome(number);
                break;
            case 2:
                Armstrong(number);
                break;
            case 3:
                Perfect(number);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    // Free dynamically allocated memory
    free(choice);
    free(number);
    return 0;
}

// Checks if the number is a palindrome
void Palindrome(int* num) {
    int* temp = (int*)malloc(sizeof(int));
    int* reversed = (int*)malloc(sizeof(int));
    int* rem = (int*)malloc(sizeof(int));

    *temp = *num;
    *reversed = 0;

    while (*temp != 0) {
        *rem = *temp % 10;
        *reversed = (*reversed * 10) + *rem;
        *temp /= 10;
    }

    if (*reversed == *num) {
        printf("It is a Palindrome number\n");
    } else {
        printf("It is not a Palindrome number\n");
    }

    free(temp);
    free(reversed);
    free(rem);
}

// Checks if the number is an Armstrong number
void Armstrong(int* num) {
    int* temp = (int*)malloc(sizeof(int));
    int* sum = (int*)malloc(sizeof(int));
    int* rem = (int*)malloc(sizeof(int));
    int* digits = (int*)malloc(sizeof(int));

    *temp = *num;
    *sum = 0;
    *digits = 0;

    // Counting number of digits
    while (*temp != 0) {
        (*digits)++;
        *temp /= 10;
    }

    *temp = *num;
    // Summing powers of digits
    while (*temp != 0) {
        *rem = *temp % 10;
        *sum += pow(*rem, *digits);
        *temp /= 10;
    }

    if (*sum == *num) {
        printf("It is an Armstrong number\n");
    } else {
        printf("It is not an Armstrong number\n");
    }

    free(temp);
    free(sum);
    free(rem);
    free(digits);
}

// Checks if the number is a perfect number
void Perfect(int* num) {
    int* sum = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));

    *sum = 0;
    *i = 1;

    // Summing all divisors of the number
    while (*i < *num) {
        if (*num % *i == 0) {
            *sum += *i;
        }
        (*i)++;
    }

    if (*sum == *num) {
        printf("It is a Perfect number\n");
    } else {
        printf("It is not a Perfect number\n");
    }

    free(sum);
    free(i);
}
