#include <stdio.h>
#include <stdlib.h>
#include "sort.h" // Include custom sort header for bubbleSort

// Linear Search - searches for key sequentially
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}   

// Binary Search - searches for key in sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, choice, key, result;

    // Input number of elements and array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Menu-driven loop for searching options
    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Perform linear search
            printf("Enter the element to search (Linear Search): ");
            scanf("%d", &key);
            result = linearSearch(arr, n, key);
            if (result != -1) {
                printf("Element found at index %d\n", result);
            } else {
                printf("Element not found\n");
            }
            break;

        case 2:
            // Sort and perform binary search
            printf("Sorting array for Binary Search...\n");
            bubbleSort(arr, n); // Using Bubble Sort from the header file
            printf("Sorted array:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Enter the element to search (Binary Search): ");
            scanf("%d", &key);
            result = binarySearch(arr, 0, n - 1, key);
            if (result != -1) {
                printf("Element found at index %d\n", result);
            } else {
                printf("Element not found\n");
            }
            break;

        case 3:
            exit(0); // Exit the program

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
