#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the queue

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue();
    void enqueue(int element);
    void dequeue();
    void peek();
};

//constructor
Queue::Queue() {
    front = -1;
    rear = -1;
}

int main() {
    Queue q;
    int choice, element;

    do {
        cout << "\nQueue Operations:" << endl;
        cout << "1: Enqueue" << endl;
        cout << "2: Dequeue" << endl;
        cout << "3: Peek" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your choice: ";
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

//add to queue
void Queue::enqueue(int element) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow! Cannot enqueue." << endl;
        return;
    }
    if (front == -1) front = 0;  // first element condition
    arr[++rear] = element;
    cout << "Enqueued: " << element << endl;
}

//remove from queue
void Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    front++;
    if (front > rear) front = rear = -1;  // reset queue if empty
}

//look at the firstmost element
void Queue::peek() {
    if (front == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front Element: " << arr[front] << endl;
}
