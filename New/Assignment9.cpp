#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<vector<int>> &adj, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int current = adj[v][i];
        if (!visited[current])
        {
            topologicalSortUtil(current, adj, visited, Stack);
        }
    }

    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    int V = 4;

    vector<pair<int, int>> edges = {{0, 1}, {3, 1}, {3, 2}, {1, 2}};

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}
