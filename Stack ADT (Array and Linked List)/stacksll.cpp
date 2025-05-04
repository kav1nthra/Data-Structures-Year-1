#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    
    Node(char ch) { 
        data = ch; 
        next = nullptr; 
    }
};

class Stack {
private:
    Node* top; // Top of the stack

public:
    Stack();        // Constructor
    ~Stack();       // Destructor
    void push(char ch);
    void pop();
    void peek();
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

        if (!(cin >> choice)) {  
            cin.clear();  
            cin.ignore(1000, '\n');  
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> ws >> ch; // Ignore any whitespace before taking character input
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
Stack::Stack() { top = nullptr; }

// Destructor to free memory
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Check if stack is empty
bool Stack::isEmpty() { return top == nullptr; }

// Push operation
void Stack::push(char ch) {
    Node* newNode = new Node(ch);
    newNode->next = top;
    top = newNode;
    cout << "Pushed '" << ch << "' onto the stack.\n";
}

// Pop operation
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! No element to pop.\n";
        return;
    }
    Node* temp = top;
    cout << "Popped '" << temp->data << "' from the stack.\n";
    top = top->next;
    delete temp;
}

// Peek operation
void Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty! Nothing to peek.\n";
        return;
    }
    cout << "Top element is: '" << top->data << "'.\n";
}
