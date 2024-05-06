/*
Consider the student database of N students and their marks. Make use of a hash table 
implementation to quickly insert and lookup students' PNR and marks. Implement 
collision handling techniques: 
1. linear probing  
2. Implement collision handling using Quadratic probing
*/

#include<iostream>
#include<vector>
using namespace std;

int hashTableSize=10;
vector<pair<int,int>>hashTable(10,{0,0});

int hashFunction(int pnr){
    return (pnr%hashTableSize);
}

void insertqp(int pnr,int marks){
    int idx=hashFunction(pnr);
    int t=idx;
    int i=0;
    while(hashTable[idx].first!=0){
        idx=(t+(i*i))%hashTableSize;
        i++;
    }
    hashTable[idx].first=pnr;
    hashTable[idx].second=marks;
    cout<<"\n\t Student with PNR "<<pnr<<" has been added successfully !"<<endl;
}

void deleteqp(int pnr){
    int idx=hashFunction(pnr);
    int t=idx;
    int i=0;
    while(hashTable[idx].first!=pnr){
        idx=(t+(i*i))%hashTableSize;
        i++;
    }
    hashTable[idx]={0,0};
    cout<<"\n\t Student with PNR "<<pnr<<" has been deleted successfully !"<<endl;
}

void displayRecords(){
    cout<<"\n\t Dispalying current records in the hash table : "<<endl;
    for(auto it:hashTable){
        if(it.first==0) cout<<"No entries till now"<<endl;
        else{
            cout<<"PNR : "<<it.first<<" has marks : "<<it.second<<endl;
        }
    }
}


int main(){

    insertqp(274,100);
    insertqp(283,97);
    insertqp(284,98);
    insertqp(254,90);
    insertqp(253,93);
    insertqp(281,95);
    displayRecords();
    deleteqp(284);
    displayRecords();

    return 0;
}