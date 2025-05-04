#include <iostream>
#include <stack>
using namespace std;

string process(const string& input) {
    stack<char> s;
    
    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) s.pop();  // Remove the last valid character
        } else {
            s.push(ch);  // Push normal characters
        }
    }

    string result;
    while (!s.empty()) {
        result = s.top() + result;  // Build result from stack contents
        s.pop();
    }
    
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    string output = process(input);
    cout << "Processed string: " << output << endl;
    
    return 0;
}