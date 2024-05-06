/*
You have a business with several offices; you want to lease phone lines to connect 
them up with each other; and the phone company charges different amounts of money 
to connect different pairs of cities. You want a set of lines that connects all your offices 
with a minimum total cost. Solve the problem by suggesting appropriate data 
structures and using   kruskal's algorithm
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adjList;
vector<int>visited;
int v,e;

void constructGraph(){
    // cout<<"Enter number of vertex : ";
    cin>>v;
    // cout<<"Enter number of edges : ";
    cin>>e;
    adjList.resize(v);
    visited.resize(v,0);
    for(int i=0;i<e;i++){
        // cout<<"Enter source and destination and weight of edge : ";
        int s,d,w;
        cin>>s>>d>>w;
        adjList[s].push_back({d,w});
        adjList[d].push_back({s,w});
    }
    // for(auto ele:adjList){
    //     cout<<"{ ";
    //     for(auto e:ele) cout<<e<<", ";
    //     cout<<"}"<<endl;

    // }
}

class DisjointSet{
public:
    vector<int>parent;
    vector<int>rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int paru=findParent(u);
        int parv=findParent(v);
        if(paru==parv) return;
        if(rank[paru]<rank[parv]){
            parent[parv]=parent[paru];
        }
        else if(rank[parv]<rank[paru]){
            parent[paru]=parent[parv];
        }
        else{
            parent[paru]=parent[parv];
            rank[parv]++;
        }
    }
};

vector<pair<int,int>>MST;
int minCost=0;

void Kruskal(){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<v;i++){
        for(auto ele:adjList[i]){
            edges.push_back({ele.second,{i,ele.first}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(v);
    for(auto ele:edges){
        if(ds.findParent(ele.second.first)!=ds.findParent(ele.second.second)){
            visited[ele.second.first]=1;
            minCost+=ele.first;
            MST.push_back({ele.second.first,ele.second.second});
            ds.unionByRank(ele.second.first,ele.second.second);           
        }
    }

}


int main(){
    constructGraph();
    Kruskal();
    cout<<minCost<<endl;
    for(auto ele:MST){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    return 0;
}