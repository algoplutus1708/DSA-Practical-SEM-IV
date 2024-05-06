/*
The dictionary file consists of a list of more than 100 correctly spelt lowercase words, 
separated by whitespace. The words are inserted into the hash table. Handle collision 
using separate chaining. After the reading of the dictionary file is complete, the 
program prompts the user for input. After input is obtained, each word that the user 
enters into the program is looked up within the hash table to see if it exists. If the 
entered word exists within the hash table, then that word is spelt correctly.
*/

#include<iostream>
#include<vector>
using namespace std;

int hashTableSize=26;
vector<string>hashTable(hashTableSize,"");
vector<int>chain(hashTableSize,-1);

int hashFunction(string word){
    return ((word[0]-'a')%hashTableSize);
}

void insertlp(string word){
    int idx=hashFunction(word);
    int prev=-1;
    while(hashTable[idx]!=""){
        if(hashFunction(hashTable[idx])==hashFunction(word)){
            prev=idx;
        }
        idx=(idx+1)%hashTableSize;
    }
    if(prev!=-1) chain[prev]=idx;
    hashTable[idx]=word;
    cout<<"\n\t word entered : "<<word<<endl;
}

void lookup(string word){
    int idx=hashFunction(word);
    while(idx!=-1){
        if(hashTable[idx]==word){
            cout<<"word : "<<word<<" found at index "<<idx<<endl;
            return;
        }
        else idx=chain[idx];

    }
    cout<<"word not found"<<endl;
    return;
}

void displayRecords(){
    cout<<"\n\t Dispalying current records in the hash table : "<<endl;
    for(auto it:hashTable){
        if(it=="") cout<<"No entries till now"<<endl;
        else{
            cout<<it<<endl;
        }
    }
}


int main(){

    insertlp("hello");
    insertlp("challo");
    insertlp("bollo");
    insertlp("nachllo");
    insertlp("haagllo");
        
    // displayRecords();
    // for(auto it:chain) cout<<it<<" ";
    lookup("haagllo");
    lookup("kkkll");
    return 0;
}