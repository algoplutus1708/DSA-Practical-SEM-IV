/**
You have a business with several offices; you want to lease phone lines to connect 
them up with each other; and the phone company charges different amounts of money 
to connect different pairs of cities. You want a set of lines that connects all your offices 
with a minimum total cost. Solve the problem by suggesting appropriate data 
structures and using prim’s algorithm
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

vector<pair<int,int>>MST;
int minCost=0;

void prims(int start){
    visited.resize(v,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{start,-1}});
    while(!pq.empty()){
        auto edge=pq.top();
        pq.pop();
        if(visited[edge.second.first]==0){
            visited[edge.second.first]=1;
            minCost+=edge.first;
            if(edge.second.second!=-1){
                MST.push_back({edge.second.second,edge.second.first});
            }
            for(auto ele:adjList[edge.second.first]){
                if(visited[ele.first]==0){
                    pq.push({ele.second,{ele.first,edge.second.first}});
                }
            }
        }
    }
}

int main(){
    constructGraph();
    prims(0);
    cout<<minCost<<endl;
    for(auto ele:MST){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    return 0;
}