// linear probing

#include <bits/stdc++.h>
    using namespace std;

struct rec
{
    int rollNo;
    string name;
};

class hashing
{
    rec hashtable[10];

public:
    hashing()
    {
        for (int i = 0; i < 10; ++i)
        {
            hashtable[i].rollNo = -1;
            hashtable[i].name = "";
        }
    }

    void insert(int rollNo, string name);
    void search(int rollNo);
    void Delete(int rollNo);
    void display();
};

void hashing::insert(int rollNo, string name)
{
    int index = rollNo % 10;
    int initialIndex = index;

    while (hashtable[index].rollNo != -1)
    {
        index = (index + 1) % 10;
        if (index == initialIndex)
        {
            cout << "Hashtable is full. No more entry\n";
            return;
        }
    }

    hashtable[index].rollNo = rollNo;
    hashtable[index].name = name;

    cout << "Record inserted successfully." << endl;
}

void hashing::search(int rollNo)
{
    int index = rollNo % 10;
    int initialIndex = index;

    while (hashtable[index].rollNo != rollNo && hashtable[index].rollNo != -1)
    {
        index = (index + 1) % 10;

        if (index == initialIndex)
        {
            cout << "Record not found." << endl;
            return;
        }
    }

    if (hashtable[index].rollNo == rollNo)
    {
        cout << "Record found - Roll No: " << rollNo << ", Name: " << hashtable[index].name << endl;
    }
    else
    {
        cout << "Record not found." << endl;
    }
}

void hashing::Delete(int rollNo)
{
    int index = rollNo % 10;
    int initialIndex = index;

    while (hashtable[index].rollNo != rollNo && hashtable[index].rollNo != -1)
    {
        index = (index + 1) % 10;

        if (index == initialIndex)
        {
            cout << "Record not found for deletion." << endl;
            return;
        }
    }

    if (hashtable[index].rollNo == rollNo)
    {
        hashtable[index].rollNo = 0;
        hashtable[index].name = "";

        cout << "Record deleted successfully." << endl;
    }
    else
    {
        cout << "Record not found for deletion." << endl;
    }
}

void hashing::display()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "Index " << i << ": ";
        if (hashtable[i].rollNo != -1)
        {
            cout << "Roll No: " << hashtable[i].rollNo << ", Name: " << hashtable[i].name;
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
    hashing hashTable;

    cout << "-----------------Inserting-----------------\n";

    hashTable.insert(62, "tushar");
    hashTable.insert(19, "deepanshu");
    hashTable.insert(9, "Ankit");
    hashTable.insert(11, "aryan");
    hashTable.insert(21, "Divyanshi");

    // hashTable.insert(11, "Depanshu1");
    // hashTable.insert(18, "Depan2");
    // hashTable.insert(14, "Depanshu3");
    // hashTable.insert(26, "Depan4");
    // hashTable.insert(35, "Depanshu5");
    // hashTable.insert(48, "Depans6");
    // hashTable.insert(67, "Depanshu7");
    // hashTable.insert(12, "Dep8");
    // hashTable.insert(32, "Depanshu9");
    // hashTable.insert(15, "Depa10");
    // hashTable.insert(64, "Depanshu11");
    // hashTable.insert(36, "De12");

    cout << "-----------------Display-----------------\n";
    hashTable.display();

    cout << "-----------------Search-----------------\n";
    hashTable.search(11);
    hashTable.search(9);
    hashTable.search(65);
    hashTable.search(22);

    cout << "-----------------Delete-----------------\n";
    hashTable.Delete(11);

    cout << "-----------------Display-----------------\n";
    hashTable.display();

    cout << "-----------------Search-----------------\n";
    hashTable.search(21);

    cout << "-----------------Display-----------------\n";
    hashTable.display();
    return 0;
}
