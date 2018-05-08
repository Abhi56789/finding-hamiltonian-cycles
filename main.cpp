#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int V;

void addEdge(vector<int> adj[], int u, int v) {
    if(u == v) {
        adj[u].push_back(u);
    } else {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
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

void test() {
    vector<int> adj1[20];  //Dodecahedron graph
    addEdge(adj1, 7, 13);
    addEdge(adj1, 9, 10);
    addEdge(adj1, 1, 2);
    addEdge(adj1, 3, 4);
    addEdge(adj1, 10, 5);
    addEdge(adj1, 1, 6);
    addEdge(adj1, 3, 8);
    addEdge(adj1, 2, 7);
    addEdge(adj1, 4, 9);
    addEdge(adj1, 13, 8);
    addEdge(adj1, 5, 11);
    addEdge(adj1, 0, 5);
    addEdge(adj1, 12, 7);
    addEdge(adj1, 15, 16);
    addEdge(adj1, 8, 14);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 14, 9);
    addEdge(adj1, 10, 15);
    addEdge(adj1, 4, 0);
    addEdge(adj1, 11, 16);
    addEdge(adj1, 12, 17);
    addEdge(adj1, 6, 12);
    addEdge(adj1, 13, 18);
    addEdge(adj1, 14, 19);
    addEdge(adj1, 11, 6);
    addEdge(adj1, 0, 1);
    addEdge(adj1, 17, 18);
    addEdge(adj1, 18, 19);
    addEdge(adj1, 19, 15);
    addEdge(adj1, 16, 17);
    printGraph(adj1, 20);
    for(int i = 0; i < 20; i++) {
        hamCycle(adj1, i);
    }

    srand(time(nullptr));
    int ver = rand()%100 + 1;
    vector<int> adj2[ver];
    int edges = rand()%(ver * (ver - 1) / 2) + 1;
    for(int i = 0; i < edges; i++) {
        int u = rand()%ver;
        int v = rand()%ver;
        addEdge(adj2, u, v);
    }
    for(int i = 0; i < ver; i++) {
        if(hamCycle(adj2, i)) {
            printGraph(adj2, ver);
        };
    }

}

int main() {
    //test();
    /*
    cout << "Choose the amount of vertices: "; cin >> V;
    if(V < 0) {
        V = abs(V);
        cout << "Taking absolute value of amount of vertices, V = " << V << endl;
    } else if(V == 0) {
        cout << "V can not be zero";
        exit(1);
    }
    vector<int> adj[V];

    bool flag = true;
    cout << "Amount of vertices in the graph is: " << V << endl;
    while(flag) {
        cout << "Choose the vertices to connect:" << endl;
        string u, v;
        cout << "u: "; cin >> u;
        cout << "v: "; cin >> v;
        if(u == "break" || v == "break") break;
        int x = stoi(u);
        int y = stoi(v);
        if(x > V - 1 || y > V - 1) {
            cout << "Incorrect vertex\n";
            break;
        }
        addEdge(adj, x, y);
    }*/
    vector<int> adj[20];
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
    printGraph(adj, 20);
    for(int i = 0; i < 20; i++) {
        hamCycle(adj, i);
    }

}