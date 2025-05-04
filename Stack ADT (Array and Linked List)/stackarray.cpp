#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the stack

class Stack {
private:
    char arr[MAX]; // Stack array
    int top;       // Top pointer

public:
    Stack();        // Constructor
    void push(char ch);
    void pop();
    void peek();
    bool isFull();
    bool isEmpty();
};

int main() {
    Stack s;
    int choice;
    char ch;

    while (true) {
        cout << "\nStack Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> ch;
                s.push(ch);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

// Constructor
Stack::Stack() { top = -1; }

// Check if stack is full
bool Stack::isFull() { return top == MAX - 1; }

// Check if stack is empty
bool Stack::isEmpty() { return top == -1; }

// Push operation
void Stack::push(char ch) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push '" << ch << "'.\n";
        return;
    }
    arr[++top] = ch;
    cout << "Pushed '" << ch << "' onto the stack.\n";
}

// Pop operation
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! No element to pop.\n";
        return;
    }
    cout << "Popped '" << arr[top--] << "' from the stack.\n";
}

// Peek operation
void Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty! Nothing to peek.\n";
        return;
    }
    cout << "Top element is: '" << arr[top] << "'.\n";
}
