#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
  public:
    DisjointSet(int n) 
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>>adj[])
{
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++)
    {
        for(auto it: adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node=i;

            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet Ds(V);
    sort(edges.begin(), edges.end());
    int mstWt=0;
    for(auto it: edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(Ds.findUPar(u) != Ds.findUPar(v))
        {
            mstWt+=wt;
            Ds.unionBySize(u,v);
        }
    }
    return mstWt;
}

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3) == ds.findUPar(7))cout<<"Same component"<<endl;
    else cout<<"Diff component"<<endl;
    ds.unionByRank(3,7);
    if(ds.findUPar(3) == ds.findUPar(7))cout<<"Same component"<<endl;
    else cout<<"Diff component"<<endl;

    vector<vector<int>>adjls[]={{},{2},{1,3},{2},{5},{5,7},{6}};
    int minwt=spanningTree(8,adjls);
    cout<<minwt<<endl;
}