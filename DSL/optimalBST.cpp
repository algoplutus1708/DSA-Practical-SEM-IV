#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
vector<vector<int>>weightMatrix;
vector<vector<int>>costMatrix;
vector<vector<int>>rootMatrix;
int n=5;
void findWeight(vector<int>& p,vector<int>& q){
    for(int i=0;i<n;i++){
        weightMatrix[i][i]=q[i];
        for(int j=i+1;j<n;j++){
            weightMatrix[i][j]=weightMatrix[i][j-1]+p[j]+q[j];
        }
    }
}

void findCost(){
    for(int i=0;i<n;i++){
        costMatrix[i][i]=0;
    }
    for(int l=1;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;
            for(int k=i+1;k<=j;k++){
                int c=costMatrix[i][k-1]+costMatrix[k][j]+weightMatrix[i][j];
                if(c<costMatrix[i][j]){
                    costMatrix[i][j]=c;
                    rootMatrix[i][j]=k;
                }
            }
        }
    }
}



int main(){
    vector<int> p={0,3,3,1,1};
    vector<int> q={2,3,1,1,1};
    weightMatrix.resize(n,vector<int>(n,0));
    costMatrix.resize(n,vector<int>(n,INT_MAX));
    rootMatrix.resize(n,vector<int>(n,-1));
    findWeight(p,q);
    findCost();
    cout<<"Cost Matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<costMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Root Matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<rootMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Weight Matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<weightMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}