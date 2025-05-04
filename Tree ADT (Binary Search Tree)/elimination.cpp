#include <iostream>
using namespace std;

void solve() 
{
    int k, q;
    cout << "Enter k: ";
    cin >> k; // Number of elements in array a
    cout << "Enter q: ";
    cin >> q; // Number of queries

    int a[100];
    cout << "Enter k sequence: ";
    for (int i = 0; i < k; ++i) 
    {
        cin >> a[i]; // Input the k-sequence
    }

    int queries[100];
    cout << "Enter q sequence: ";
    for (int i = 0; i < q; ++i) 
    {
        cin >> queries[i]; // Input the q queries
    }

    for (int i = 0; i < q; ++i) 
    {
        int current = queries[i]; // Current query value
        bool changed;

        // Repeat until no change is made in a full pass
        do {
            changed = false;
            for (int j = 0; j < k; ++j) 
            {
                // If current is greater than or equal to a[j], decrement current
                if (a[j] <= current) 
                {
                    current--;
                    changed = true; // A change was made
                } 
                else 
                {
                    break; // Since a[] is not necessarily sorted, continue checking
                }
            }
        } while (changed);

        cout << "The winner is: " << current << " ";
    }

    cout << endl;
}

int main() 
{
    int t;
    cout << "Enter no. of testcases: ";
    cin >> t; // Number of test cases

    while (t--) 
    {
        solve(); // Solve each test case
    }

    return 0;
}
