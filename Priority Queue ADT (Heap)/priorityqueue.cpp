#include <iostream>
using namespace std;

const int MAX = 100;

class MaxHeap {
private:
    int heap[MAX];
    int size;

    void heapifyUp(int index);   // Adjusts the heap when inserting a new element
    void heapifyDown(int index); // Adjusts the heap after deleting the max element

public:
    MaxHeap();                 
    void insert(int value);     // Inserts a value into the heap
    void deleteMax();           // Deletes the maximum value from the heap
    void display();             // Displays the current elements in the heap
    void search(int key);       // Searches for a value in the heap
    void heapSort();            // Sorts the elements in the heap
};

// Main function with menu
int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;
            case 5:
                cout << "Sorted elements: ";
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

// Constructor
MaxHeap::MaxHeap() {
    size = 0;
}

void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(int value) {
    if (size >= MAX) {
        cout << "Heap is full!\n";
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
    cout << "Inserted.\n";
}

void MaxHeap::deleteMax() {
    if (size <= 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Deleted: " << heap[0] << endl;
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void MaxHeap::display() {
    if (size == 0) {
        cout << "Heap is empty.\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void MaxHeap::search(int key) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == key) {
            cout << "Found at index: " << i << endl;
            return;
        }
    }
    cout << "Not found.\n";
}

void MaxHeap::heapSort() {
    int temp[MAX], tempSize = size;
    for (int i = 0; i < size; i++)
        temp[i] = heap[i];

    while (size) {
        cout << heap[0] << " ";
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
    cout << endl;

    for (int i = 0; i < tempSize; i++)
        heap[i] = temp[i];
    size = tempSize;
}
