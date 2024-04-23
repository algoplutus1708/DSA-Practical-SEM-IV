// linear probing with chaining with replacement

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

    if (hashtable[index].key == -1)
    {
        hashtable[index].key = value;
        return;
    }
    else if (hashtable[index].key != -1 && (hashtable[index].key) % 10 == value % 10)
    {

        while (hashtable[index].chain != -1)
        {
            index = hashtable[index].chain;
        }
        int store = index;

        while (hashtable[index].key != -1)
        {
            index = (index + 1) % 10;
            if(index==store)
            {
                cout << "Hashtable is full\n";
                return;
            }
        }

        hashtable[index].key = value;
        hashtable[store].chain = index;
    }
    else
    {

        int temp_value = hashtable[index].key;
        int temp_index = hashtable[index].chain;

        hashtable[index].key = value;
        hashtable[index].chain = -1;

        for (int i = 0; i < 10; i++)
        {
            if(hashtable[i].chain==index)
            {
                hashtable[i].chain = temp_index;
                break;
            }
        }
        
        index = temp_index;
        value = temp_value;

        while (hashtable[index].chain != -1)
        {
            temp_value = hashtable[index].key;
            temp_index = hashtable[index].chain;

            hashtable[index].key = value;

            value = temp_value;
            index = temp_index;
        }

        temp_value = hashtable[index].key;
        hashtable[index].key = value;

        temp_index = index;

        while (hashtable[index].key != -1)
        {
            index = (index + 1) % 10;
        }

        hashtable[index].key = temp_value;
        hashtable[temp_index].chain = index;
    }
}

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
    h.insert(42);
    h.display();
    cout << "--------------------------------\n";
    h.insert(55);
    h.display();
    cout << "--------------------------------\n";
    h.insert(88);
    h.display();
    cout << "--------------------------------\n";
    h.insert(77);
    h.display();
}