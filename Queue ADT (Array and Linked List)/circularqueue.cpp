#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the circular queue

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue();
    void enqueue(int element);
    void dequeue();
    void peek();
};

CircularQueue::CircularQueue() {
    front = -1;
    rear = -1;
}

int main() {
    CircularQueue q;
    int choice, element;

    do {
        cout << "\nCircular Queue Operations:" << endl;
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
void CircularQueue::enqueue(int element) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Overflow! Cannot enqueue." << endl;
        return;
    }
    if (front == -1) front = 0;  // first element condition
    rear = (rear + 1) % SIZE;
    arr[rear] = element;
    cout << "Enqueued: " << element << endl;
}

//remove from queue
void CircularQueue::dequeue() {
    if (front == -1) {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1;  // reset queue if empty
    } else {
        front = (front + 1) % SIZE;
    }
}

//to look at the firstmost element in the queue
void CircularQueue::peek() {
    if (front == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front Element: " << arr[front] << endl;
}