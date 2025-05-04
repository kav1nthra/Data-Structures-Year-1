#include <iostream>
#include "stackadt.h"

using namespace std;

int checkbalance(string);

// Main function
int main() {
    string in;
    int choice;
    int check;
    
    do {
        cout << "\n\nMenu : \n1. Check Balance\n2. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the string : ";
                cin >> in;
                check = checkbalance(in);
                if (check == 1)
                    cout << "\nThe string is balanced\n";
                else
                    cout << "\nThe string is not balanced\n";
                break;

            case 2:
                cout << "\nTerminating program...\n";
                exit(0);

            default:
                cout << "\nInvalid choice! Try again.\n";
                break;
        }
    } while (choice != 2);

    return 0;
}

// Function to check if parentheses are balanced
int checkbalance(string in) {
    Stack s;

    for (char c : in) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.isEmpty()) {
                return -1; // Unmatched closing parenthesis
            }
            s.pop();
        }
    }

    if (!s.isEmpty()) {
        return -1; // Unmatched opening parenthesis
    }

    return 1; // Balanced
}
