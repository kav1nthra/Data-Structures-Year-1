#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];

public:
    HashTable();
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function definitions

HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void HashTable::insert(int key) {
    int index = key % SIZE;
    int i = 1;
    while (table[index] != -1) {
        index = (index + i * i) % SIZE;
        i++;
        if (i >= SIZE) return;
    }
    table[index] = key;
}

void HashTable::remove(int key) {
    int index = key % SIZE;
    int i = 1;
    while (table[index] != key) {
        if (table[index] == -1 || i >= SIZE) {
            cout << "Key not found\n";
            return;
        }
        index = (index + i * i) % SIZE;
        i++;
    }
    table[index] = -1;
}

void HashTable::search(int key) {
    int index = key % SIZE;
    int i = 1;
    while (table[index] != key) {
        if (table[index] == -1 || i >= SIZE) {
            cout << "Key not found\n";
            return;
        }
        index = (index + i * i) % SIZE;
        i++;
    }
    cout << "Key found at index " << index << "\n";
}

void HashTable::display() {
    for (int i = 0; i < SIZE; i++)
        cout << i << ": " << table[i] << "\n";
}
