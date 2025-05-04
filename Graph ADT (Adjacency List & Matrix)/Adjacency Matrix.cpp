#include <iostream>
using namespace std;

#define MAX 100

class GraphMatrix {
    int adj[MAX][MAX];
    int vertices;

public:
    GraphMatrix(int v);
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    bool searchEdge(int u, int v);
    void display();
};

int main() {
    int v, choice, u, w;
    cout << "Enter number of vertices: ";
    cin >> v;

    if (v > MAX || v <= 0) {
        cout << "Number of vertices should be between 1 and " << MAX << ".\n";
        return 0;
    }

    GraphMatrix g(v);

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                g.insertEdge(u, w);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                g.deleteEdge(u, w);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                cout << (g.searchEdge(u, w) ? "Exists" : "Doesn't exist") << endl;
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

// Constructor definition
GraphMatrix::GraphMatrix(int v) {
    vertices = v;
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            adj[i][j] = 0;
}

// Insert edge
void GraphMatrix::insertEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    } else {
        cout << "Invalid vertices!\n";
    }
}

// Delete edge
void GraphMatrix::deleteEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices) {
        adj[u][v] = 0;
        adj[v][u] = 0;
    } else {
        cout << "Invalid vertices!\n";
    }
}

// Search edge
bool GraphMatrix::searchEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        return adj[u][v] == 1;
    else {
        cout << "Invalid vertices!\n";
        return false;
    }
}

// Display graph
void GraphMatrix::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}