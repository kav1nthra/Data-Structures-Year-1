#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];  // Array to store the hash table elements

public:
    HashTable();      // Constructor
    void insert(int key);  // Insert a key
    void remove(int key);  // Remove a key
    void search(int key);  // Search for a key
    void display();  // Display the hash table
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

// Constructor to initialize the hash table with -1 (empty slots)
HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

// Insert key using linear probing
void HashTable::insert(int key) {
    int index = key % SIZE;
    int start = index;
    while (table[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash Table is full\n";
            return;
        }
    }
    table[index] = key;
}

// Remove a key using linear probing
void HashTable::remove(int key) {
    int index = key % SIZE;
    int start = index;
    while (table[index] != key) {
        index = (index + 1) % SIZE;
        if (index == start || table[index] == -1) {
            cout << "Key not found\n";
            return;
        }
    }
    table[index] = -1;
}

// Search for a key in the hash table
void HashTable::search(int key) {
    int index = key % SIZE;
    int start = index;
    while (table[index] != key) {
        if (table[index] == -1) {
            cout << "Key not found\n";
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Key not found\n";
            return;
        }
    }
    cout << "Key found at index " << index << "\n";
}

// Display the hash table contents
void HashTable::display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": " << table[i] << "\n";
    }
}
