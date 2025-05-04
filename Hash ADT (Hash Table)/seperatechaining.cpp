#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int data;
    Node* next;
};

class HashTable {
private:
    Node* table[SIZE];

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
            case 1: cout << "Enter key: "; cin >> key; ht.insert(key); break;
            case 2: cout << "Enter key: "; cin >> key; ht.remove(key); break;
            case 3: cout << "Enter key: "; cin >> key; ht.search(key); break;
            case 4: ht.display(); break;
        }
    } while (choice != 5);

    return 0;
}

// Definitions

HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

void HashTable::insert(int key) {
    int index = key % SIZE;
    Node* newNode = new Node{key, table[index]};
    table[index] = newNode;
}

void HashTable::remove(int key) {
    int index = key % SIZE;
    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Key not found\n";
        return;
    }

    if (!prev)
        table[index] = curr->next;
    else
        prev->next = curr->next;

    delete curr;
    cout << "Key deleted\n";
}

void HashTable::search(int key) {
    int index = key % SIZE;
    Node* curr = table[index];

    while (curr) {
        if (curr->data == key) {
            cout << "Key found at index " << index << "\n";
            return;
        }
        curr = curr->next;
    }

    cout << "Key not found\n";
}

void HashTable::display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node* curr = table[i];
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}
