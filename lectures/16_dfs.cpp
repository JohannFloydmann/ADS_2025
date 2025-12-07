#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

    void DFS_recursive(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << ' ';
        for (int i : adjList[v])
        {
            if (!visited[i])
            {
                DFS_recursive(i, visited);
            }
        }
    }

    void topologicalSort_recursive(int v, stack<int> &Stack, vector<bool> &visited)
    {
        visited[v] = true;

        for (int i : adjList[v])
        {
            if (!visited[i])
            {
                topologicalSort_recursive(i, Stack, visited);
            }
        }
        Stack.push(v);
    }

public:
    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        DFS_recursive(start, visited);
    }

    void topologicalSort()
    {
        stack<int> Stack;
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                topologicalSort_recursive(i, Stack, visited);
            }
        }

        cout << "Topological sort: " << endl;
        while (!Stack.empty())
        {
            cout << Stack.top() << ' ';
            Stack.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    g.topologicalSort();
    return 0;
}