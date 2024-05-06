/*
Consider the student database of N students and their marks. Make use of a hash table 
implementation to quickly insert and lookup students' PNR and marks. Implement 
collision handling techniques: 
1. linear probing  
2. Implement delete operation in collision handling using linear probing 
3. linear probing with chaining without replacement 
*/

#include<iostream>
#include<vector>
using namespace std;

int hashTableSize=10;
vector<pair<int,int>>hashTable(10,{0,0});

int hashFunction(int pnr){
    return (pnr%hashTableSize);
}

void insertlp(int pnr,int marks){
    int idx=hashFunction(pnr);
    while(hashTable[idx].first!=0){
        idx=(idx+1)%hashTableSize;
    }
    hashTable[idx].first=pnr;
    hashTable[idx].second=marks;
    cout<<"\n\t Student with PNR "<<pnr<<" has been added successfully !"<<endl;
}

void deletelp(int pnr){
    int idx=hashFunction(pnr);
    while(hashTable[idx].first!=pnr){
        idx=(idx+1)%hashTableSize;
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

    insertlp(274,100);
    insertlp(283,97);
    insertlp(284,98);
    insertlp(254,90);
    insertlp(253,93);
    insertlp(281,95);
    displayRecords();
    deletelp(284);
    displayRecords();

    return 0;
}