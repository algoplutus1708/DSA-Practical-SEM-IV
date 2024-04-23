#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert_node(int x, node *&root)
{
    node *newNode = new node(x);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    char choice;
    node *temp = root;
    while (true)
    {
        cout << "Move left(l) or right(r) of" << temp->data << endl;
        cin >> choice;
        if (choice == 'l')
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
                temp = temp->left;
        }
        else if (choice == 'r')
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

void insertIntoBST(node *&root, int key)
{
    node *nw = new node(key);

    if (root == NULL)
    {
        root = nw;
        return;
    }
    node *temp = root;
    while (true)
    {
        if (temp->data > key)
        {
            if (temp->left == NULL)
            {
                temp->left = nw;
                return;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = nw;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

// RECURSIVE TRAVERSAL DFS

void printInorder(node *&root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(node *&root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// NON-RECURSIVE LEVEL ORDER OR BFS

void bfs(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

// NON-RECURSIVE TRAVERSAL DFS

void iterativeInOrder(node *&root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    node *current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

void iterativePreorder(node *root)
{

    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *current = s.top();

        cout << current->data << " ";
        s.pop();

        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
    cout << endl;
}

void iterativePostOrder(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s1, s2;

    s1.push(root);
    node *newNode;

    while (!s1.empty())
    {
        newNode = s1.top();
        s1.pop();
        s2.push(newNode);

        if (newNode->left)
            s1.push(newNode->left);
        if (newNode->right)
            s1.push(newNode->right);
    }

    while (!s2.empty())
    {
        newNode = s2.top();
        s2.pop();
        cout << newNode->data << " ";
    }
    cout << endl;
}

// HEIGHT

int recursiveHeight(node *root)
{
    if (root == nullptr)
        return 0;

    int left_height = recursiveHeight(root->left);
    int right_height = recursiveHeight(root->right);

    return 1 + max(left_height, right_height);
}

int iterativeHeight(node *root)
{

    int depth = 0;

    queue<node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            depth++;
        }

        if (temp != NULL)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return depth;
}

node *cloneTree(node *root)
{
    if (root == nullptr)
        return nullptr;

    node *newNode = new node(root->data);

    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);

    return newNode;
}

void eraseTree(node *&root)
{
    if (root == nullptr)
        return;

    eraseTree(root->left);
    eraseTree(root->right);

    delete root;
    root = nullptr;
}

void mirrorImage(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    node *newNode = root->left;
    root->left = root->right;
    root->right = newNode;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

// DELETE NODE FROM BST

node *deleteNode(node *root, int k)
{

    if (root == NULL)
        return root;

    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {

        node *succParent = root;

        node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        delete succ;
        return root;
    }
}

bool areEqual(node *p, node *q)
{

    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    if (p->data != q->data)
        return false;

    return areEqual(p->left, q->left) && areEqual(p->right, q->right);
}

int main()
{
    node *originalRoot = NULL;
    originalRoot = new node(1);
    originalRoot->left = new node(2);
    originalRoot->right = new node(3);
    originalRoot->left->left = new node(4);
    originalRoot->right->right = new node(5);

    cout << "Inorder: ";
    printInorder(originalRoot);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(originalRoot);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(originalRoot);
    cout << endl;

    cout << "BFS: ";
    bfs(originalRoot);

    cout << "Non-recursive Inorder: ";
    iterativeInOrder(originalRoot);

    cout << "Non-recursive Preorder: ";
    iterativePreorder(originalRoot);

    cout << "Non-recursive Postorder: ";
    iterativePostOrder(originalRoot);

    cout << "Recursive Height: ";
    cout << recursiveHeight(originalRoot) << endl;

    cout << "Non-Recursive Height: ";
    cout << iterativeHeight(originalRoot) << endl;

    node *cloneRoot = cloneTree(originalRoot);

    eraseTree(originalRoot);

    cout << "Mirror Image: ";
    mirrorImage(cloneRoot);
    printInorder(cloneRoot);
    cout << endl;

    node *bst = NULL;
    insertIntoBST(bst, 15);
    insertIntoBST(bst, 8);
    insertIntoBST(bst, 30);
    insertIntoBST(bst, 4);
    insertIntoBST(bst, 53);

    cout << "------------------BINARY SEARCH TREE------------------\n";
    cout << "Inorder: ";
    printInorder(bst);
    cout << endl;

    cout << "------------------DELETE NODE IN BST------------------\n";
    deleteNode(bst, 30);
    cout << "Inorder: ";
    printInorder(bst);
    cout << endl;

    cout << "------------------CHECKING TREE ARE EQUAL OR NOT------------------\n";

    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(6);
    root2->left->right = new node(5);

    if (areEqual(root1, root2))
        cout << "The two trees are equal." << endl;
    else
        cout << "The two trees are not equal." << endl;
}