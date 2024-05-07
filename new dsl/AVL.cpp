#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;
    int height;

    Node(string keyword, string meaning)
    {
        this->keyword = keyword;
        this->meaning = meaning;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *root)
    {
        Node *child= root->left;
        Node *childRight = child->right;

        child->right = root;
        root->left = childRight;

        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node *leftRotate(Node *root)
    {
        Node *child = root->right;
        Node *childLeft = child->left;

        child->left = root;
        root->right = childLeft;

        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node *insertNode(Node *node, string keyword, string meaning)
    {
        if (node == nullptr)
        {
            return new Node(keyword, meaning);
        }

        if (keyword < node->keyword)
        {
            node->left = insertNode(node->left, keyword, meaning);
        }
        else if (keyword > node->keyword)
        {
            node->right = insertNode(node->right, keyword, meaning);
        }
        else
        {
            node->meaning = meaning;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && keyword < node->left->keyword)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && keyword > node->right->keyword)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && keyword > node->left->keyword)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && keyword < node->right->keyword)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *root, string keyword)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (keyword < root->keyword)
        {
            root->left = deleteNode(root->left, keyword);
        }
        else if (keyword > root->keyword)
        {
            root->right = deleteNode(root->right, keyword);
        }
        else
        {
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp;
                if (root->left != nullptr)
                {
                    temp = root->left;
                }
                else
                {
                    temp = root->right;
                }

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        if (root == nullptr)
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            inorder(root->right);
        }
    }

    void reverseInorder(Node *root)
    {
        if (root != nullptr)
        {
            reverseInorder(root->right);
            cout << root->keyword << " : " << root->meaning << endl;
            reverseInorder(root->left);
        }
    }

    Node *search(Node *root, string keyword, int &comparisons)
    {
        comparisons++;
        if (root == nullptr || root->keyword == keyword)
        {
            return root;
        }
        if (root->keyword < keyword)
        {
            return search(root->right, keyword, comparisons);
        }
        return search(root->left, keyword, comparisons);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(string keyword, string meaning)
    {
        root = insertNode(root, keyword, meaning);
    }

    void remove(string keyword)
    {
        root = deleteNode(root, keyword);
    }

    void update(const string &keyword, const string &newMeaning)
    {
        int comparisons = 0;
        Node *node = search(root, keyword, comparisons);
        if (node != nullptr)
        {
            node->meaning = newMeaning;
        }
    }

    void displayAscending()
    {
        inorder(root);
    }

    void displayDescending()
    {
        reverseInorder(root);
    }

    int getMaxComparisons(const string &keyword)
    {
        int comparisons = 0;
        search(root, keyword, comparisons);
        return comparisons;
    }
};

int main()
{
    AVLTree dictionary;

    dictionary.insert("apple", "a fruit");
    dictionary.insert("banana", "another fruit");
    dictionary.insert("zebra", "an animal");
    dictionary.insert("audi", "a car");
    dictionary.insert("HP", "laptop");

    cout << "=========================================\n";

    cout << "Displaying ascending order:" << endl;
    dictionary.displayAscending();

    cout << "=========================================\n";

    cout << "Displaying descending order:" << endl;
    dictionary.displayDescending();

    cout << "=========================================\n";

    string searchWord = "banana";
    int comparisons = dictionary.getMaxComparisons(searchWord);
    cout << "Maximum comparisons required to find \"" << searchWord << "\": " << comparisons << endl;

    cout << "=========================================\n";

    string deleteWord = "banana";
    dictionary.remove(deleteWord);
    cout << "After deleting \"" << deleteWord << "\":" << endl;
    dictionary.displayAscending();

    cout << "=========================================\n";

    string updateWord = "apple";
    string newMeaning = "a delicious fruit";
    dictionary.update(updateWord, newMeaning);
    cout << "After updating \"" << updateWord << "\":" << endl;
    dictionary.displayAscending();

    return 0;
}
