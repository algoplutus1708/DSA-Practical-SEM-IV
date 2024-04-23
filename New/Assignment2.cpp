#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string word, meaning;
    Node *next;

    Node()
    {
        word = "";
        meaning = "";
        next = nullptr;
    }

    Node(string w, string m)
    {
        word = w;
        meaning = m;
        next = nullptr;
    }
};

class Hashing
{
    Node *table[10];

public:
    Hashing()
    {

        for (int i = 0; i < 10; ++i)
        {
            table[i] = nullptr;
        }
    }

    void insert(string w, string m);
 
    void search(string w);
    void display();
};


void Hashing::insert(string word, string meaning)
{
   

    int index = 0;
    for (int i = 0; i < word.length(); i++)
    {
        // index+=((word[i]-'a'+1)*pow(10,i));
        index += (word[i] - 'a' + 1);
    }
    index = index % 10;

    Node *newNode = new Node(word, meaning);

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        newNode->next = table[index];
        table[index] = newNode;
    }

    cout << "Word inserted successfully!" << endl;
}

void Hashing::search(string word)
{
   

    int index = 0;
    for (int i = 0; i < word.length(); i++)
    {
        // index+=((word[i]-'a'+1)*pow(10,i));
        index += (word[i] - 'a' + 1);
    }
    index = index % 10;

    Node *temp = table[index];
    while (temp != nullptr)
    {
        if (temp->word == word)
        {
            cout<<"Word Found\n";
            cout << "Meaning: " << temp->meaning << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Word not found!" << endl;
}

void Hashing::display()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "Index " << i << ": ";
        Node *temp = table[i];
        while (temp != nullptr)
        {
            cout << "(" << temp->word << ", " << temp->meaning << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Hashing hashTable;

    ifstream Input("Data.txt");
    string word,meaning;
    while(Input>>word>>meaning)
    {
        hashTable.insert(word,meaning);
    }

    hashTable.display();


    hashTable.search("sad");

    return 0;
}
