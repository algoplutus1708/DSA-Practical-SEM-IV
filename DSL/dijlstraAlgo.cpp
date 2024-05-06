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
        // cout<<"Enter source and destination of vertex : ";
        int s,d,w;
        cin>>s>>d>>w;
        adjList[s].push_back({d,w});
    }
    // for(auto ele:adjList){
    //     cout<<"{ ";
    //     for(auto em:ele) cout<<em.first<<", ";
    //     cout<<"}"<<endl;

    // }
}
vector<int>ans;
vector<int>path;
void dijkstra(int start,int end){
    ans.resize(v,INT_MAX);
    visited.resize(v,0);
    vector<int>parent(v);
    for(int i=0;i<v;i++) parent[i]=i;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    ans[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int visitingNode=pq.top().second;
        int currDist=pq.top().first;
        pq.pop();
        for(auto ele:adjList[visitingNode]){
            if(currDist+ele.second<ans[ele.first]){
                ans[ele.first]=currDist+ele.second;
                pq.push({ans[ele.first],ele.first});
                parent[ele.first]=visitingNode;
            }
        }
    }
    if(ans[end]==INT_MAX) cout<<"No path exists"<<endl;
    else{
        // cout<<"Shortest path from "<<start<<" to "<<end<<" is : ";
        int currentLoc=end;
        while(parent[currentLoc]!=currentLoc){
            path.push_back(currentLoc);
            currentLoc=parent[currentLoc];
        }
        path.push_back(start);
        reverse(path.begin(),path.end());
    
    }
}

int main(){
    constructGraph();
    dijkstra(0,3);
    cout<<ans[3]<<endl;
    for(auto ele:path) cout<<ele<<" ";
    return 0;
}