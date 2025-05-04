#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Binary Tree Class
class BinaryTree {
private:
    Node* root;
    Node* insert(Node* node, int data);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    bool search(Node* node, int key);

public:
    BinaryTree() { root = nullptr; }
    void insert(int data);
    void inorder();
    void preorder();
    void postorder();
    bool search(int key);
};

// Insert function (Recursive)
Node* BinaryTree::insert(Node* node, int data) {
    if (node == nullptr) {
        Node* temp = new Node();
        temp->data = data;
        temp->left = temp->right = nullptr;
        return temp;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {  // Prevent duplicates
        node->right = insert(node->right, data);
    }
    return node;
}

// Wrapper for insertion
void BinaryTree::insert(int data) {
    root = insert(root, data);
}

// Inorder Traversal (LNR)
void BinaryTree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}
void BinaryTree::inorder() {
    inorder(root);
    cout << endl;
}

// Preorder Traversal (NLR)
void BinaryTree::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}
void BinaryTree::preorder() {
    preorder(root);
    cout << endl;
}

// Postorder Traversal (LRN)
void BinaryTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}
void BinaryTree::postorder() {
    postorder(root);
    cout << endl;
}

// Search for an element
bool BinaryTree::search(Node* node, int key) {
    if (node == nullptr) return false;
    if (node->data == key) return true;
    return (key < node->data) ? search(node->left, key) : search(node->right, key);
}
bool BinaryTree::search(int key) {
    return search(root, key);
}

// Main function
int main() {
    BinaryTree tree;
    int choice, data;

    cout << "Binary Search Tree Operations\n";
    cout << "1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n";

    do {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data to be inserted: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Inorder: ";
                tree.inorder();
                break;
            case 3:
                cout << "Preorder: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter number to search: ";
                cin >> data;
                if (tree.search(data)) {
                    cout << data << " is present in the tree" << endl;
                } else {
                    cout << data << " is NOT THERE in the tree" << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
