#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int from, to, weight;
    bool operator<(const Edge &other) const { return weight < other.weight; }
    Edge(int from, int to, int weight)
        : from(from), to(to), weight(weight) {}
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int v) : V(v) {}

    void addEdge(int from, int to, int weight) {
        edges.emplace_back(from, to, weight);
    }

    int find(vector<int> &parent, int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    void Union(vector<int> &parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);
        parent[y] = x;
    }

    void KruskalMST() {
        sort(edges.begin(), edges.end());

        vector<int> parent(V, -1);
        vector<Edge> result;

        int i = 0;      
        int chosen = 0; 

        while (chosen < V - 1 && i < edges.size()) {
            Edge next = edges[i++];

            int x = find(parent, next.from);
            int y = find(parent, next.to);

            if (x != y) {
                result.push_back(next);
                Union(parent, x, y);
                chosen++;
            }
        }

        int totalWeight = 0;
        for (auto &e : result)
            totalWeight += e.weight;

        cout << totalWeight << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Graph graph(n+1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x >= 0)
            {
                graph.addEdge(i, j, x);
            }
            
        }
        
    }
    
    graph.KruskalMST();
}