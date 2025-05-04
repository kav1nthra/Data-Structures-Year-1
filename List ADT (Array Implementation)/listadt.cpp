#include <iostream>
using namespace std;

// Maximum size of the list
#define MAX 5

class List {
public:
    int arr[MAX];
    int size;

    List() {
        size = 0;
    }  

    // Function declarations:
    bool insertB(int);
    bool insertE(int);
    bool insertP(int, int);
    int deleteB();
    int deleteE();
    int deleteP(int);
    int search(int);
    void display();
    void rotate(int);
};

int main() {
    List lis;
    int choice, value, pos;

    cout << "The menu is as follows:\n"
         << "\t1. Insert beginning\n"
         << "\t2. Insert end\n"
         << "\t3. Insert position\n"
         << "\t4. Delete beginning\n"
         << "\t5. Delete end\n"
         << "\t6. Delete position\n"
         << "\t7. Search\n"
         << "\t8. Display\n"
         << "\t9. Rotate\n"
         << "\t10. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 10) break;
        if (choice < 1 || choice > 10) {
            cout << "Enter a valid choice\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter a number to insert: ";
            cin >> value;
            if (lis.insertB(value)) {
                cout << "Inserted successfully.\n";
            } else {
                cout << "Insertion failed. List is full.\n";
            }
            break;

        case 2:
            cout << "Enter a number to insert: ";
            cin >> value;
            if (lis.insertE(value)) {
                cout << "Inserted successfully.\n";
            } else {
                cout << "Insertion failed. List is full.\n";
            }
            break;

        case 3:
            cout << "Enter the index position: ";
            cin >> pos;
            cout << "Enter a number to insert: ";
            cin >> value;
            if (lis.insertP(value, pos)) {
                cout << "Inserted successfully.\n";
            } else {
                cout << "Insertion failed. List is full or position invalid.\n";
            }
            break;

        case 4:
            cout << "Deleted: " << lis.deleteB() << endl;
            break;

        case 5:
            cout << "Deleted: " << lis.deleteE() << endl;
            break;

        case 6:
            cout << "Enter the position to delete: ";
            cin >> pos;
            cout << "Deleted: " << lis.deleteP(pos) << endl;
            break;

        case 7:
            cout << "Enter target element: ";
            cin >> value;
            int index;
            index = lis.search(value);
            if (index != -1)
                cout << "Element found at position " << index << endl;
            else
                cout << "Element not found.\n";
            break;

        case 8:
            lis.display();
            break;

        case 9:
            cout << "No. of rotations: ";
            cin >> value;
            lis.rotate(value);
            break;
        }
    }
    return 0;
}

// Insert element at the beginning
bool List::insertB(int value) {
    if (size == MAX) {
        return false;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    return true;
}

// Insert element at the end
bool List::insertE(int value) {
    if (size == MAX) {
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}

// Insert element at a given position
bool List::insertP(int value, int pos) {
    if (size == MAX || pos < 0 || pos > size) {
        return false;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    return true;
}

// Delete element at the beginning
int List::deleteB() {
    if (size == 0) {
        cout << "List is empty.\n";
        return -1;
    }
    int del = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return del;
}

// Delete element at the end
int List::deleteE() {
    if (size == 0) {
        cout << "List is empty.\n";
        return -1;
    }
    int del = arr[size - 1];
    size--;
    return del;
}

// Delete element at a given position
int List::deleteP(int pos) {
    if (size == 0 || pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return -1;
    }
    int del = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return del;
}

// Search for a given value
int List::search(int value) {
    if (size == 0) {
        cout << "List is empty.\n";
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Display the list
void List::display() {
    if (size == 0) {
        cout << "No elements in the list.\n";
    } else {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Rotate the list k times
void List::rotate(int k) {
    if (size == 0) {
        cout << "No elements in the list.\n";
        return;
    }
    k = k % size; // To avoid excessive rotations
    for (int i = 0; i < k; i++) {
        int last = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}
