#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int data){
        this->data=data;
        left=right=NULL;
        height=1;
    }
};
int getHeight(Node* root){
    if(!root) return 0;
    return root->height;
}
Node* leftRotate(Node* root){
    Node* child=root->right;
    Node* childLeft=child->left;

    child->left=root;
    root->right=childLeft;

    //update height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    return child;
}

Node* rightRotate(Node* root){
    Node* child=root->left;
    Node* childRight=child->right;

    child->right=root;
    root->left=childRight;

    //update height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    return child;
}

Node* insert(Node* root,int val){
    if(!root) return new Node(val);

    if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    else return root;

    //update heightof the tree
    root->height=1+max(getHeight(root->left),getHeight(root->right));

    //get the balance factor
    int balance=getHeight(root->left)-getHeight(root->right);

    if(balance>1 && val<root->left->data){//LL case
        return rightRotate(root);
    }
    else if(balance>1 && val>root->left->data){//LR Case
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance<-1 && val>root->right->data){//RR case
        return leftRotate(root);
    }
    else if(balance<-1 && val<root->right->data){//RL case
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    else return root; //balanced tree

}

Node* deleteNode(Node* root, int val){
    if(!root) return root;
    if(val<root->data) root->left=deleteNode(root->left,val);
    else if(val>root->data) root->right=deleteNode(root->right,val);
    else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(root->left && !root->right){
            Node* temp =root->left;
            delete root;
            return temp;
        }
        else if(root->right && !root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else{
            Node* temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }

        //update height
        root->height=1+max(getHeight(root->left),getHeight(root->right));
        //get the balance factor
        int balance=getHeight(root->left)-getHeight(root->right);

        if(balance>1 && val<root->left->data){//LL case
            return rightRotate(root);
        }
        else if(balance>1 && val>root->left->data){//LR Case
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        else if(balance<-1 && val>root->right->data){//RR case
            return leftRotate(root);
        }
        else if(balance<-1 && val<root->right->data){//RL case
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        else return root; //balanced tree
    }
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    root=insert(root,35);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    root=deleteNode(root,40);
    preorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}