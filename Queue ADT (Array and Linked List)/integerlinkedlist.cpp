#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class with front and rear pointers
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    void enqueue(int element);
    void dequeue();
    void peek();
};

Queue::Queue() {
    front = rear = nullptr;
}

int main() {
    Queue q;
    int choice, element;

    do {
        cout << "\nQueue Operations:\n1: Enqueue\n2: Dequeue\n3: Peek\n4: Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Destructor to free memory
Queue::~Queue() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

// Insert an element at the rear
void Queue::enqueue(int element) {
    Node* newNode = new Node(element);
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << element << endl;
}

// Remove an element from the front
void Queue::dequeue() {
    if (!front) {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return;
    }
    Node* temp = front;
    cout << "Dequeued: " << front->data << endl;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

// Display the front element
void Queue::peek() {
    if (!front) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front Element: " << front->data << endl;
}
