#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int>adj[])
{
   int vis[V]={0};
   vis[0]=1;
   queue<int>q;
   q.push(0);
   vector<int>bfs;
   while(!q.empty())
   {
     int node = q.front();
     q.pop();
     bfs.push_back(node);
     for(auto it: adj[node])
     {
        if(!vis[it])
        {
            vis[it]=1;
            q.push(it);
        }
     }
   }
   return bfs;
}

void dfs(int node, vector<int>adj[], int vis[], vector<int>&ls)
{
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int> DFS(int V, vector<int>adj[])
{
    int vis[V]={0};
    int start=0;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

int numberOfComponents(vector<int>adj[], int V)
{
    int cnt=0;
    int vis[V]={0};
    vector<int>ls;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i,adj,vis,ls);
        }
    }
    return cnt;
}

int main()
{
   vector<int>adjls[]={{2,3,1},{0},{0,4},{0},{2}};
   vector<int>v=BFS(5,adjls);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   int count=numberOfComponents(adjls,5);
   cout<<count<<endl;
   v=DFS(5,adjls);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
}
