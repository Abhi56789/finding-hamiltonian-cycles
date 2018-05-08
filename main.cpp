#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int V;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
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

void printPath(int path[]) {
    cout << "The Hamitlonian cycle path for this graph is: " << endl;
    for (int i = 0; i < V; i++)
        cout << path[i] << ' ';
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

bool _hamCycle(vector<int> adj[], int path[], int pos) {
    if(pos == V) {
        return find(adj[path[pos - 1]], path[0]);
    }
    for(int v = 0; v < V; v++) {
        if(isSafe(v, adj, path, pos)) {
            path[pos] = v;

            if(_hamCycle(adj, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(vector<int> adj[], int start) {
    int* path = new int[V];
    for(int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = start;
    if(!_hamCycle(adj, path, 1)) {
        cout << "\nThere is no Hamitlonian cycle in the graph\n";
        return false;
    }
    printPath(path);
    return true;
}

int main(int argc, char* argv[]) {
    V = atoi(argv[1]);
    vector<int> adj[V];
    addEdge(adj, 7, 13);
    addEdge(adj, 9, 10);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 10, 5);
    addEdge(adj, 1, 6);
    addEdge(adj, 3, 8);
    addEdge(adj, 2, 7);
    addEdge(adj, 4, 9);
    addEdge(adj, 13, 8);
    addEdge(adj, 5, 11);
    addEdge(adj, 0, 5);
    addEdge(adj, 12, 7);
    addEdge(adj, 15, 16);
    addEdge(adj, 8, 14);
    addEdge(adj, 2, 3);
    addEdge(adj, 14, 9);
    addEdge(adj, 10, 15);
    addEdge(adj, 4, 0);
    addEdge(adj, 11, 16);
    addEdge(adj, 12, 17);
    addEdge(adj, 6, 12);
    addEdge(adj, 13, 18);
    addEdge(adj, 14, 19);
    addEdge(adj, 11, 6);
    addEdge(adj, 0, 1);
    addEdge(adj, 17, 18);
    addEdge(adj, 18, 19);
    addEdge(adj, 19, 15);
    addEdge(adj, 16, 17);
/*
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 1);
    addEdge(adj, 5, 3);
    addEdge(adj, 3, 1);
*/
/*
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 3);
    addEdge(adj, 4, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
*/
    printGraph(adj, V);
    for(int i = 0; i < V; i++) {
        hamCycle(adj, i);
    }
}