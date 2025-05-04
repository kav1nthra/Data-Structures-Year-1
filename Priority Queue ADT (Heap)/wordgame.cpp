#include <stdio.h>
#include <string.h>

#define MAX_N 1000     // Maximum number of words per player
#define MAX_LEN 4      // Length of each word

int main() {
    int test;
    printf("Enter number of test cases: ");
    scanf("%d", &test);

    while (test--) {
        int n;
        scanf("%d", &n);  // Input number of words

        char words[3][MAX_N][MAX_LEN];  // 3 players' words
        int wc[26 * 26 * 26] = {0};  // Frequency counter

        // Count frequencies of 3-letter combinations
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", words[i][j]);
                int index = (words[i][j][0] - 'a') * 676 + 
                            (words[i][j][1] - 'a') * 26 + 
                            (words[i][j][2] - 'a');
                wc[index]++;
            }
        }

        int scores[3] = {0, 0, 0};

        // Calculate scores based on frequencies
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                int index = (words[i][j][0] - 'a') * 676 + 
                            (words[i][j][1] - 'a') * 26 + 
                            (words[i][j][2] - 'a');

                if (wc[index] == 1) {
                    scores[i] += 3;  // Unique word, 3 points
                } else if (wc[index] == 2) {
                    scores[i] += 1;  // Word appears twice, 1 point
                }
            }
        }

        printf("%d %d %d\n", scores[0], scores[1], scores[2]);
    }

    return 0;
}
