#include <iostream>
#include <list>
using namespace std;

class GraphList {
    int V;
    list<int>* adj;

public:
    GraphList(int v);
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    bool searchEdge(int u, int v);
    void display();
};

int main() {
    int v, choice, u, w;
    cout << "Enter number of vertices: ";
    cin >> v;
    GraphList g(v);

    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice: ";
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
        }
    } while (choice != 5);

    return 0;
}

// Constructor definition
GraphList::GraphList(int v) {
    V = v;
    adj = new list<int>[V];
}


// Insert edge
void GraphList::insertEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Delete edge
void GraphList::deleteEdge(int u, int v) {
    adj[u].remove(v);
    adj[v].remove(u);
}

// Search edge
bool GraphList::searchEdge(int u, int v) {
    for (int x : adj[u])
        if (x == v) return true;
    return false;
}

// Display graph
void GraphList::display() {
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}
