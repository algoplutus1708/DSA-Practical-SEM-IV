#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int>&st, vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it]) dfs(it,vis,st,adj);
    }
    st.push(node);
}

vector<int> topological_sort(int V, vector<int>adj[])
{
    int vis[V]={0};
    stack<int>st;
    for(int i=0;i<V;i++)
    {
       if(!vis[i])
       {
        dfs(i,vis,st,adj);
       }
    }
    vector<int>ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int>adjls[]={{},{},{3},{1},{0,1},{0,2}};
    cout<<"Topological Sort for the given Directed Acyclic Graph:"<<endl;
    vector<int>f=topological_sort(6,adjls);
    for(auto it:f)cout<<it<<" ";
    cout<<endl;
}