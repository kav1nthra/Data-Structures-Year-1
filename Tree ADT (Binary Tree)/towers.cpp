#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cases, towers;
    cout << "Enter the number of test cases: ";
    cin >> cases; // Input number of test cases

    for (int i = 0; i < cases; i++) {
        cout << "Enter the number of towers: ";
        cin >> towers; // Input number of towers for this test case
        
        vector<int> arr(towers); // Vector to store number of bricks in each tower
        
        for (int j = 0; j < towers; j++) {
            cout << "Enter the number of bricks in tower " << j + 1 << ": ";
            cin >> arr[j]; // Input brick count for each tower
        }

        // Sort the towers to bring the smallest tower to index 0
        sort(arr.begin(), arr.end());

        // Try to balance the smallest tower with every taller tower
        for (int j = 1; j < towers; j++) {
            if (arr[j] > arr[0]) {
                // If average is an integer, update arr[0] to the average
                if ((arr[0] + arr[j]) % 2 == 0) {
                    arr[0] = (arr[j] + arr[0]) / 2;
                } 
                // If average is not an integer, round it up
                else {
                    arr[0] = (arr[j] + arr[0]) / 2 + 1;
                }
            }
        }

        // Print the final number of bricks in the first tower after balancing
        cout << "The number of bricks in tower 1 is " << arr[0] << endl;
    }

    return 0;
}
