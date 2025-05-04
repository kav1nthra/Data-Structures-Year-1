#include <iostream>

using namespace std;

void solve() 
{
    int n;
    cout<<"Enter the number of nos: ";
    cin >> n;
    int strengths[n];

    // Read input and find the maximum and second maximum strength
    int max1 = -1, max2 = -1;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> strengths[i];

        if (strengths[i] > max1) 
        {
            max2 = max1;
            max1 = strengths[i];
        } 
        else if (strengths[i] > max2) 
        {
            max2 = strengths[i];
        }
    }

    cout<<"The difference values: ";
    // Compute and print only the difference values
    for (int i = 0; i < n; i++) 
    {
        int max_other = (strengths[i] == max1 ? max2 : max1);
        int diff = strengths[i] - max_other;
        cout<<diff << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cout<<"Enter t=no. of testcases: ";
    cin >> t; // Number of test cases
    while (t--) 
    {
        solve();
    }
    return 0;
}
