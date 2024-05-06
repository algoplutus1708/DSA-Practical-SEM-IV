/*
5. 
    Beginning with empty binary search tree Construct BST by inserting the values in given 
    order. After construction a binary tree do: 
    1. Insert new node.   2. Find number of nodes from longest path from root. Search a 
    specific value and display comparisons required.  
 
    Create binary tree/binary search tree with n nodes, do following operation  
    1. Insert a node         
    2. Delete a node from BST  
    3. All traversals (recursive and iterative) 

  
    Create binary tree/binary search tree with n nodes, do following operation  
    1. Insert a node        
    2. Find the height of a tree.  
    3. Create clone of a tree and then erase all nodes in a original tree.   
    4. create a Mirror image of a tree.  

    Create binary tree/binary search tree with n nodes, do following operation  
    1. Insert a node          
    2. construct a binary tree from inorder and preorder traversal   
    3. Check whether two trees are equal.
*/
#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};

class BST{
    Node* root;
    int size;
public:
    BST(){
        root=NULL;
        size=0;
    }
    Node* getRoot(){
        return root;
    }
    Node* insert(Node* root,int val){
        if(!root) return new Node(val);

        if(val<=root->val) root->left=insert(root->left,val);
        else root->right=insert(root->right,val);

        return root;
    }

    Node* deleteNode(Node* root,int val){
        if(!root) return NULL;

        if(val<root->val) root->left=deleteNode(root->left,val);
        else if(val>root->val) root->right=deleteNode(root->right,val);
        else{
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //has only left child
            else if(root->left && !root->right){
                Node* child=root->left;
                delete root;
                return child;
            }
            //has only right child
            else if(!root->left && root->right){
                Node* child=root->right;
                delete root;
                return child;
            }
            // has two childen
            else{
                Node* curr=root->right;
                while(curr->left){
                    curr=curr->left;
                }
                root->val=curr->val;
                root->right=deleteNode(root->right,curr->val);
                return root;
            }
        }
    }

    int heightOfTree(Node* root){
        if(!root) return 0;
        return 1+max(heightOfTree(root->left),heightOfTree(root->right));
    }

    int longestDist(Node* root){
        if(!root) return 0;
        return 1+heightOfTree(root->left)+heightOfTree(root->right);
    }

    int search(Node* root,int val){
        Node* temp=root;
        int comp=0;
        while(temp!=NULL){
            comp++;
            if(val==temp->val) break;
            else if(val<temp->val){
                temp=temp->left;
            }
            else{
                // comp++;
                temp=temp->right;
            }
        }
    

       comp= (temp!=NULL)? comp: -1;
       return comp;
    }

    Node* construct(vector<int>pre,int prestart,int preend,vector<int>in,int instart,int inend){
        if(prestart>preend || instart>inend) return NULL;

        Node* root=new Node(pre[prestart]);

        int idx=0;
        for(int i=instart;i<=inend;i++){
            if(in[i]==pre[prestart]){
                idx=i;
                break;
            }
        }
        int leftTreeSize=idx-instart;

        root->left=construct(pre,prestart+1,prestart+leftTreeSize,in,instart,idx-1);
        root->right=construct(pre,prestart+leftTreeSize+1,preend,in,idx+1,inend);
        return root;

    }
    
};

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}


void inorder_rec(Node* root){
    vector<int>ans;
    stack<Node*>st;
    Node* t=root;
    while(!st.empty() || t!=NULL){
        if(t!=NULL){
            st.push(t);
            t=t->left;
        }
        else{
            Node* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            t=temp->right;
        }
    }
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

}

void preorder_rec(Node* root){
    vector<int>ans;
    stack<Node*>st;
    if(root!=NULL) st.push(root);
    while(!st.empty()){
        Node* temp=st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
}

void postorder_rec(Node* root){
    vector<int>ans;
    stack<Node*>st;
    if(root!=NULL) st.push(root);
    while(!st.empty()){
        Node* temp=st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->left!=NULL) st.push(temp->left);
        if(temp->right!=NULL) st.push(temp->right);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main(){

    BST bst;
    Node* root=NULL;
    root=bst.insert(root,20);
    root=bst.insert(root,70);
    root=bst.insert(root,10);
    root=bst.insert(root,40);
    root=bst.insert(root,90);
    root=bst.insert(root,30);
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // // root=bst.deleteNode(root,70);
    // // inorder(root);
    // // cout<<endl;
    // cout<<bst.heightOfTree(root)<<endl;
    // cout<<bst.longestDist(root)<<endl;
    // cout<<bst.search(root,30)<<endl;
    // cout<<bst.search(root,25)<<endl;
    vector<int>pre={20,10,90,40,30};
    vector<int>in={10,20,30,40,90};
    Node *r1=bst.construct(pre,0,pre.size()-1,in,0,in.size()-1);
    inorder_rec(r1);
    cout<<endl;
    preorder_rec(r1);
    cout<<endl;
    postorder_rec(r1);
    cout<<endl;
}