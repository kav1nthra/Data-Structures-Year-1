#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 200000

// Function to solve a test case
void solve() {
    int n;
    scanf("%d", &n);  // Read size of array
    int *a = (int *)malloc(n * sizeof(int)); 
    bool seen[MAX_N + 1] = {false}; // Track seen elements

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read array elements
    }

    int remove_count = 0;

    // Traverse from right, find longest suffix with unique elements
    for (int i = n - 1; i >= 0; i--) {
        if (seen[a[i]]) break;
        seen[a[i]] = true;
        remove_count++;
    }

    printf("%d\n", n - remove_count);  // Print number of elements to remove
    free(a);  // Free allocated memory
}

int main() {
    int t;
    scanf("%d", &t);  // Read number of test cases
    while (t--) {
        solve();  // Solve each test case
    }
    return 0;
}
