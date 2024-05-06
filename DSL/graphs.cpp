/*
Represent a given graph using adjacency list representation to perform DFS   traversal 
on graph. 
Represent a given graph using adjacency list representation to perform   BFS traversal 
on graph. 
Write a c++  program to perform topological sort on a graph.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adjList;
vector<int>visited;
int v,e;

void constructGraph(){
    cout<<"Enter number of vertex : ";
    cin>>v;
    cout<<"Enter number of edges : ";
    cin>>e;
    adjList.resize(v);
    visited.resize(v,0);
    for(int i=0;i<e;i++){
        cout<<"Enter source and destination of vertex : ";
        int s,d;
        cin>>s>>d;
        adjList[s].push_back(d);
    }
    for(auto ele:adjList){
        cout<<"{ ";
        for(auto e:ele) cout<<e<<", ";
        cout<<"}"<<endl;

    }
}

void bfs(int start){
    visited.resize(v,0);
    queue<int>toVisit;
    toVisit.push(start);

    while(!toVisit.empty()){
        int visiting=toVisit.front();
        toVisit.pop();
        visited[visiting]=1;
        cout<<visiting<<" ";
        for(auto e:adjList[visiting]){
            if(visited[e]==0) toVisit.push(e);
        }
    }
    
}
vector<int>ans;
void dfs(int node){
    visited[node]=1;
    ans.push_back(node);
    for(int e:adjList[node]){
        if(visited[e]==0){
            dfs(e);
        }
    }

}

void topological(int node,stack<int>&values){
    visited[node]=1;
    cout<<node<<" ";
    for(int ele:adjList[node]){
        if(visited[ele]==0){
            topological(ele,values);
        }
    }
    values.push(node);
}

int main(){
    constructGraph();
    // bfs(0);
    // visited.resize(v,0);
    cout<<endl;
    // dfs(3);
    // for(auto ele:ans) cout<<ele<<" ";
    stack<int>values;
    for(int i=0;i<v;i++){
        if(visited[i]==0) topological(i,values);
    }
    // topological(0,values);
    cout<<values.size()<<endl;
    // while(!values.empty()){
    //     cout<<values.top()<<" ";
    //     values.pop();
    // }
    return 0;
}