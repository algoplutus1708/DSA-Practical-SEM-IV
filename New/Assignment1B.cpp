// linear probing with chaining without replacement

#include <bits/stdc++.h>
using namespace std;

struct chain
{
    int key, chain;
};

class hashing
{
    chain hashtable[10];

public:
    hashing()
    {
        for (int i = 0; i < 10; ++i)
        {
            hashtable[i].key = -1;
            hashtable[i].chain = -1;
        }
    }

    void insert(int key);
    // void search(int key, int chain);
    // void Delete(int key, int chain);
    void display();
};

void hashing::insert(int value)
{

    int index = value % 10;
    int initialIndex = index;

    // Empty
    if (hashtable[index].key == -1 && hashtable[index].chain == -1)
    {
        hashtable[index].key = value;
        return;
    }

    // not empty && having same hash value -->> follow chain
    else if (hashtable[index].key != -1 && (hashtable[index].key) % 10 == value % 10)
    {

        while (hashtable[index].chain != -1)
        {
            index = ((hashtable[index].chain));
        }

        int store = index;

        while (hashtable[index].key != -1)
        {
            index = (index + 1) % 10;
        }

        hashtable[index].key = value;
        hashtable[store].chain = index;
    }

    // not empty and having different hash value
    else if (hashtable[index].key != -1 && (hashtable[index].key) % 10 != value % 10)
    {
        int store;
        while (hashtable[index].key != -1)
        {
            if ((hashtable[index].key) % 10 == value % 10)
            {
                store = index;
            }
            index = (index + 1) % 10;
        }

        hashtable[index].key = value;
        hashtable[store].chain = index;
    }
}

// void hashing::search(int key, int chain)
// {
// }
// void hashing::Delete(int key, int chain)
// {
// }

void hashing::display()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "Index " << i << ": ";
        if (hashtable[i].key != -1)
        {
            cout << "Key: " << hashtable[i].key << ", Chain: " << hashtable[i].chain;
        }
        else
        {
            cout << "Empty";
        }
        cout << endl;
    }
}

int main()
{
    hashing h;

    cout << "-----------------Inserting-----------------\n";

    h.insert(131);
    h.insert(13);
    h.insert(14);
    h.insert(31);
    h.insert(51);
    h.insert(16);
    h.insert(71);

    h.display();
}
