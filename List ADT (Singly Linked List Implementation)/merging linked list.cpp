#include <iostream>

using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        
        // Constructor for Node
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;

public:
    List() { head = nullptr; }
    
    void insertAscending(int num);
    void display();
    void mergeLists(List& list1, List& list2);
    void clear();
};

int main() {
    List list1, list2, mergedList;
    int choice, num;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge List1 & List2 into List3\n";
        cout << "4. Display List1\n";
        cout << "5. Display List2\n";
        cout << "6. Display Merged List3\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to insert into List1: ";
                cin >> num;
                list1.insertAscending(num);
                break;

            case 2:
                cout << "Enter number to insert into List2: ";
                cin >> num;
                list2.insertAscending(num);
                break;

            case 3:
                mergedList.mergeLists(list1, list2);
                cout << "Lists merged successfully!\n";
                break;

            case 4:
                cout << "List1: ";
                list1.display();
                break;

            case 5:
                cout << "List2: ";
                list2.display();
                break;

            case 6:
                cout << "Merged List3: ";
                mergedList.display();
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice, try again!\n";
        }
    }
}


// Insert in ascending order
void List::insertAscending(int num) {
    Node* newNode = new Node(num, nullptr);

    if (!head || num < head->data) { // Insert at head
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data < num) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Merge two sorted lists into the current list
void List::mergeLists(List& list1, List& list2) {
    // Clear mergedList before merging
    clear();

    Node* temp1 = list1.head;
    Node* temp2 = list2.head;
    Node** lastPtrRef = &head;

    while (temp1 && temp2) {
        if (temp1->data < temp2->data) {
            *lastPtrRef = new Node(temp1->data);
            temp1 = temp1->next;
        } else {
            *lastPtrRef = new Node(temp2->data);
            temp2 = temp2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (temp1) {
        *lastPtrRef = new Node(temp1->data);
        lastPtrRef = &((*lastPtrRef)->next);
        temp1 = temp1->next;
    }

    while (temp2) {
        *lastPtrRef = new Node(temp2->data);
        lastPtrRef = &((*lastPtrRef)->next);
        temp2 = temp2->next;
    }
}

// Display the list
void List::display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Clear the list to prevent memory leaks
void List::clear() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}