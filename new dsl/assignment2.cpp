#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  string word;
  string mean;
  Node *next;
  Node()
  {
    word = "";
    mean = "";
    next = NULL;
  }
  Node(string s, string m)
  {
    word = s;
    mean = m;
    next = NULL;
  }
};

class hashing : public Node
{
public:
  Node *table[10];
  hashing()
  {
    for (int i = 0; i < 10; i++)
    {
      table[i] = NULL;
    }
  }
  int hsfunc(string s)
  {
    int l = s.length();
    int val = 0;
    // for(int i=l-1;i>=0;i--)
    // {
    //   val+=int(s[i])*pow(10,i);
    // }
    for (int i = 0; i < l; i++)
    {
      val += (s[i] - 'a' + 1);
    }
    // cout<<"check val : "<<s<<" "<<val<<endl;
    return val % 10;
  }
  void insert(string s, string m)
  {
    int index = hsfunc(s);
    if (table[index] == NULL)
    {
      table[index] = new Node(s, m);
    }
    else
    {
      Node *temp = table[index];
      table[index] = new Node(s, m);
      table[index]->next = temp;
    }
  }
  void search(string s)
  {
    int index = hsfunc(s);
    Node *temp = table[index];
    while (temp->word != s && temp != NULL)
    {
      temp = temp->next;
    }
    if (temp != NULL)
    {
      cout << "Word found : " << s << " " << temp->mean << endl;
    }
    else
      cout << "Word not found !" << endl;
  }
  void display()
  {
    cout << "Gourav" << endl;
    cout << "7224" << endl;
    cout << "Dictionary contents :" << endl;
    for (int i = 0; i < 10; i++)
    {
      cout << "Index : " << i << endl;
      Node *temp = table[i];
      while (temp != NULL)
      {
        cout << "   " << temp->word << "   " << temp->mean << endl;
        temp = temp->next;
      }
      cout << endl;
    }
  }
};

int main()
{
  hashing hs;
  ifstream inf("Data.txt");
  string words, meaning;
  while (inf >> words >> meaning)
  {
    hs.insert(words, meaning);
  }

  //  hs.insert("apple","fruit");
  //  hs.insert("book","stationary");
  //  hs.insert("mobile","electronic");
  //  hs.insert("sad","emotion");
  //  hs.insert("ads","promo");
  hs.display();
  //  hs.search("sad");

  hs.search("keyboard");
}
