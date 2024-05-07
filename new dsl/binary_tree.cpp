#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
   Node* left;
   Node* right;

   Node(int val)
   {
	 data=val;
     left=NULL;
     right=NULL;
   }
};
class BT{
    Node* root=NULL;
  public:
    void insertnode(int);
    Node* cloneTree(Node*);
    // void printTree(Node* );
};

void BT::insertnode(int val)
{
   char choice;
   if(root==NULL)
   {
     root=new Node(val);
     return;
   }
   Node* temp=root;
   while(temp!=NULL)
   {
    cout<<"Enter left or right : "<<endl;
     cin>>choice;
     if(choice=='l')temp=temp->left;
     else temp=temp->right;
   }
   temp=new Node(val);
}

// void BT::printTree(Node* root)
// {
//    cout<<root->data<<endl;
//    cout<<root->left->data<<endl;
//    cout<<root->right->data<<endl;
// }

Node* BT::cloneTree(Node* root)
{
   Node* newRoot=root;
   queue<Node*>q;
   while(!q.empty())
   {

   }
}

int main()
{
   BT tree;
   tree.insertnode(1);
   tree.insertnode(2);
   tree.insertnode(3);
}
