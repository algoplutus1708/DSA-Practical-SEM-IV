/*
Write a c++ program to implement Huffman coding text compression algorithm. Build 
the huffman Tree using characters and their frequencies input from user. Encode a 
given string by using codes generated from huffman tree and decode the bit sequence 
entered by the user.  
a 4             (01) 
b 7            (11) 
c 3          (101) 
d 2            (100) 
e 4            (00) 
*/

#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    char data;
    int freq;
    Node *left,*right;
    Node(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

class Huffman{
public:
    map<char,string>codes;
    map<string,char>revCodes;
    Node* root;
    
    Huffman(){
        root=NULL;
    }
    void buildHuffman(vector<pair<char,int>>& values){
        priority_queue<pair<int,Node*> ,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
        for(auto x:values){
            pq.push({x.second,new Node(x.first,x.second)});
        }
        while(pq.size()>1){
            Node* left=pq.top().second;
            pq.pop();
            Node* right=pq.top().second;
            pq.pop();
            Node* newNode=new Node('#',(left->freq+right->freq));
            newNode->left=left;
            newNode->right=right;
            pq.push({newNode->freq,newNode});
        }
        root=pq.top().second;

        coding(root,"");
        for(auto it:codes) cout<<it.first<<" "<<it.second<<endl;
    }
    void coding(Node* root,string s){
        if(root==NULL) return;
        if(root->data!='#'){
            codes[root->data]=s;
            revCodes[s]=root->data;
        }
        coding(root->left,s+'0');
        coding(root->right,s+='1');
    }
    
    string encode(string s){
        string res="";
        for(char c:s){
            res+=codes[c];
            res+=" ";
        }
        return res;
    }

    string decode(string s){
        string res="";
        string temp="";
        for(char c:s){
            if(c==' '){
                res+=revCodes[temp];
                temp="";
            }
            else temp+=c;
        }
        res+=revCodes[temp];
        return res;
    }
    

};


int main(){
    vector<pair<char,int>>values;
    values.push_back({'a',4});
    values.push_back({'b',7});
    values.push_back({'c',3});
    values.push_back({'d',2});
    values.push_back({'e',4});
    Huffman h;
    h.buildHuffman(values);
    cout<<endl;
    cout<<"Enter message to encode : ";
    string message;
    cin>>message;
    cout<<"Encoded message is as follows : "<<h.encode(message)<<endl;
    cout<<"Enter message to decode : ";
    string code;
    cin.ignore();
    getline(cin,code);
    cout<<"Decoded message is as follows : "<<h.decode(code)<<endl;


    return 0;
}