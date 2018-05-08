#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void test();
void addEdge(vector<int> adj[], int u, int v);
void printGraph(vector<int> adj[], int V);
bool find(vector<int> adj, int v);
void printPath(int path[], int V);
bool isSafe(int v, vector<int> adj[], int path[], int pos);
bool _hamCycle(vector<int> adj[], int path[], int pos, int V);
bool hamCycle(vector<int> adj[], int start, int V);


int main(int argc, char* argv[]) {
    string arg = argv[1];
    if(argc == 2 && arg == "test") {
        test();
    } else if(argc == 0) {
        int V;
        cout << "Choose the amount of vertices: ";
        cin >> V;
        if (V < 0) {
            V = abs(V);
            cout << "Taking absolute value of amount of vertices, V = " << V << endl;
        } else if (V == 0) {
            cout << "V can not be zero";
            exit(1);
        }
        vector<int> adj[V];
        bool flag = true;
        cout << "Amount of vertices in the graph is: " << V << endl;
        while (flag) {
            cout << "Choose the vertices to connect:" << endl;
            string u, v;
            cout << "u: ";
            cin >> u;
            cout << "v: ";
            cin >> v;
            if (u == "break" || v == "break") break;
            int x = stoi(u);
            int y = stoi(v);
            if (x > V - 1 || y > V - 1) {
                cout << "Incorrect vertex\n";
                break;
            }
            addEdge(adj, x, y);
        }
        printGraph(adj, V);
        for (int i = 0; i < V; i++) {
            hamCycle(adj, i, V);
        }
    } else {
        cout << "Incorrect arguments\n";
        exit(1);
    }
}



void addEdge(vector<int> adj[], int u, int v) {
    if(u == v) {
        adj[u].push_back(u);
    } else {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void printGraph(vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

bool find(vector<int> adj, int v) {
    for (int i : adj) {
        if(i == v) return true;
    }
    return false;
};

void printPath(int path[], int V) {
    cout << "The Hamitlonian cycle path for this graph is: " << endl;
    for (int i = 0; i < V; i++)
        cout << path[i] << "->";
    cout << path[0] << endl;
}

bool isSafe(int v, vector<int> adj[], int path[], int pos) {
    if(!find(adj[path[pos - 1]], v)) {
        return false;
    }
    for(int i = 0; i < pos; i++) {
        if(path[i] == v) return false;
    }
    return true;
}

bool _hamCycle(vector<int> adj[], int path[], int pos, int V) {
    if(pos == V) {
        return find(adj[path[pos - 1]], path[0]);
    }
    for(int v = 0; v < V; v++) {
        if(isSafe(v, adj, path, pos)) {
            path[pos] = v;
            if(_hamCycle(adj, path, pos + 1, V))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(vector<int> adj[], int start, int V) {
    int* path = new int[V];
    for(int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = start;
    if(!_hamCycle(adj, path, 1, V)) {
        cout << "\nThere is no Hamitlonian cycle in the graph\n";
        return false;
    }
    printPath(path, V);
    return true;
}

void test() {
    srand(time(nullptr));
    for(int i = 0; i < 100; i++) {
        int V = rand() % 98 + 3;
        vector<int> adj[V];
        int edges = rand() % (V * (V - 1) / 2) + 1;
        for (int i = 0; i < edges; i++) {
            int u = rand() % V;
            int v = rand() % V;
            addEdge(adj, u, v);
        }
        for (int i = 0; i < V; i++) {
            if (hamCycle(adj, i, V)) {
                printGraph(adj, V);
                exit(0);
            };
        }
    }
}