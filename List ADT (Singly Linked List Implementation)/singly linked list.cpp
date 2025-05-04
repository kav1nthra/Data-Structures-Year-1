#include <iostream>
using namespace std;

class Llist {
private:
    struct node {
        int data;
        struct node* next;
    } *head;

public:
    Llist() { head = NULL; }

    int insertBegin(int);   // Insert at beginning
    int insertEnd(int);     // Insert at end
    int insertPos(int, int); // Insert at given position
    int deleteBegin();      // Delete from beginning
    int deleteEnd();        // Delete from end
    int deletePos(int);     // Delete from specific position
    int search(int);        // Search for element
    int display();          // Display elements
    int displayrev();       // Display in reverse (not reversing actual links)
    int revlink();          // Reverse the actual linked list
};

int main() {
    Llist list;
    int choice, num, pos, ret;
    while (true) {
        cout << "\nMain menu" << endl;
        cout << "1. Insert Beginning" << endl;
        cout << "2. Insert End" << endl;
        cout << "3. Insert Position" << endl;
        cout << "4. Delete Beginning" << endl;
        cout << "5. Delete End" << endl;
        cout << "6. Delete Position" << endl;
        cout << "7. Search" << endl;
        cout << "8. Display" << endl;
        cout << "9. Display Reverse" << endl;
        cout << "10. Reverse Link" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> num;
                ret = list.insertBegin(num);
                cout << (ret ? "Insertion successful" : "Insertion failed") << endl;
                break;
            case 2:
                cout << "Enter number to insert: ";
                cin >> num;
                ret = list.insertEnd(num);
                cout << (ret ? "Insertion successful" : "Insertion failed") << endl;
                break;
            case 3:
                cout << "Enter number to insert: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                ret = list.insertPos(num, pos);
                cout << (ret ? "Insertion successful" : "Insertion failed") << endl;
                break;
            case 4:
                ret = list.deleteBegin();
                cout << (ret ? "Deletion successful" : "Deletion failed") << endl;
                break;
            case 5:
                ret = list.deleteEnd();
                cout << (ret ? "Deletion successful" : "Deletion failed") << endl;
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                ret = list.deletePos(pos);
                cout << (ret ? "Deletion successful" : "Deletion failed") << endl;
                break;
            case 7:
                cout << "Enter number to search: ";
                cin >> num;
                ret = list.search(num);
                cout << (ret != -1 ? "Element found at position: " + to_string(ret) : "Element not found") << endl;
                break;
            case 8:
                ret = list.display();
                if (ret == 0) cout << "List is empty" << endl;
                break;
            case 9:
                ret = list.displayrev();
                if (ret == 0) cout << "List is empty" << endl;
                break;
            case 10:
                ret = list.revlink();
                cout << (ret ? "List reversed successfully" : "Reversal failed") << endl;
                break;
            case 11:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

// Inserts new node at the beginning
int Llist::insertBegin(int num) {
    node* newnode = new node;
    if (!newnode) return 0;
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    return 1;
}

// Inserts new node at the end
int Llist::insertEnd(int num) {
    node* newnode = new node;
    if (!newnode) return 0;
    newnode->data = num;
    newnode->next = NULL;
    if (!head) {
        head = newnode;
        return 1;
    }
    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
    return 1;
}

// Inserts new node at a specific position
int Llist::insertPos(int num, int pos) {
    if (pos < 1) return 0;
    node* newnode = new node;
    if (!newnode) return 0;
    newnode->data = num;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return 1;
    }
    node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) return 0;
    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

// Deletes node from the beginning
int Llist::deleteBegin() {
    if (!head) return 0;
    node* temp = head;
    head = head->next;
    delete temp;
    return 1;
}

// Deletes node from the end
int Llist::deleteEnd() {
    if (!head) return 0;
    if (!head->next) {
        delete head;
        head = NULL;
        return 1;
    }
    node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return 1;
}

// Deletes node at a given position
int Llist::deletePos(int pos) {
    if (!head || pos < 1) return 0;
    if (pos == 1) return deleteBegin();
    node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp || !temp->next) return 0;
    node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return 1;
}

// Searches for an element and returns its position
int Llist::search(int num) {
    node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == num) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// Displays the linked list elements
int Llist::display() {
    if (!head) return 0;
    node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 1;
}

// Displays the list in reverse using an array (does not modify list)
int Llist::displayrev() {
    if (!head) return 0;
    node* temp = head;
    int arr[1000], i = 0;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 1;
}

// Reverses the actual linked list using three pointers
int Llist::revlink() {
    if (!head) return 0;
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current) {
        next = current->next;     // Store next node
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev forward
        current = next;           // Move current forward
    }
    head = prev;                  // Update head to new front
    return 1;
}
