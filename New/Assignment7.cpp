#include <bits/stdc++.h>
using namespace std;

#define size 9

int minKey(int distance[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
    {
        if (visited[v] == false && distance[v] < min)
        {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[size][size])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < size; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void prim(int graph[size][size])
{
    int parent[size];
    int distance[size];
    bool visited[size];

    for (int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < size - 1; count++)
    {
        int u = minKey(distance, visited);

        visited[u] = true;

        for (int v = 0; v < size; v++)
        {
            if (graph[u][v] != 0 && visited[v] == false && graph[u][v] < distance[v])
            {
                parent[v] = u;
                distance[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[size][size] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    prim(graph);

    return 0;
}




// #include <bits/stdc++.h>

// using namespace std;

// class kruskal
// {
// public:
//     int cities;

//     vector<pair<int, pair<int, int>>> v;

//     kruskal(int val)
//     {
//         cities = val;
//     }

//     void addEdge(int a, int b, int weight)
//     {

//         v.push_back(make_pair(weight, make_pair(a, b)));
//     }

//     void sortEdges()
//     {
//         sort(v.begin(), v.end());
//     }

//     int findParent(vector<int> &parent, int vertex)
//     {
//         if (parent[vertex] == -1)
//             return vertex;
//         return findParent(parent, parent[vertex]);
//     }

//     void unionSets(vector<int> &parent, int u, int v)
//     {
//         int uSet = findParent(parent, u);
//         int vSet = findParent(parent, v);
//         parent[uSet] = vSet;
//     }

//     void kruskalMST()
//     {
//         vector<int> parent(cities, -1);
//         vector<pair<int, pair<int, int>>> result;

//         for (auto edge : v)
//         {
//             int weight = edge.first;
//             int u = edge.second.first;
//             int v = edge.second.second;

//             int uSet = findParent(parent, u);
//             int vSet = findParent(parent, v);

//             if (uSet != vSet)
//             {
//                 result.push_back(edge);
//                 unionSets(parent, u, v);
//             }
//         }
//     }

//     void output()
//     {
//         cout << "Sorted Edges:" << endl;
//         for (auto edge : v)
//         {
//             int weight = edge.first;
//             int a = edge.second.first;
//             int b = edge.second.second;
//             cout << a << " - " << b << ", Weight: " << weight << endl;
//         }
//     }
// };
// int main()
// {
//     kruskal k(5);

//     k.addEdge(1, 2, 30);
//     k.addEdge(0, 1, 10);
//     k.addEdge(2, 3, 20);

//     k.sortEdges();
//     k.kruskalMST();

//     k.output();

//     return 0;
// }

