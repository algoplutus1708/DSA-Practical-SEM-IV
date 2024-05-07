#include<bits/stdc++.h>
using namespace std;

struct rec{
    int roll_no;
    string name;
};

class Hashing
{
    public:
    rec hashtable[10];
    Hashing()
    {
        for(int i=0;i<10;i++)
        {
            hashtable[i].roll_no=-1;
        }
    }
    void insert(int r,string s);
    void search(int r);
    void display();
    void delete_rno(int r);
};

void Hashing::insert(int r,string s)
{
    int ind=r%10;
    if(hashtable[ind].roll_no==-1)
    {
        hashtable[ind].roll_no=r;
        hashtable[ind].name=s;
    }
    else
    {
        int sq=1;
        int tp=(ind+(sq*sq))%10;
        while(tp!=ind)
        {
            if(hashtable[tp].roll_no==-1)
            {
               hashtable[tp].roll_no=r;
               hashtable[tp].name=s; 
               return;
            }
            sq+=1;
            tp=(tp+(sq*sq))%10;
        }
        cout<<"Element cannot be inserted , hashtable is FULL !!!"<<endl;
    }
}

void Hashing::delete_rno(int r)
{
    int tp=r%10;
    int sq=1;
        while(hashtable[tp].roll_no!=r)
        {
            tp=(tp+sq*sq)%10;
        }
        if(hashtable[tp].roll_no==r)
        {
          hashtable[tp].roll_no=-2;
          hashtable[tp].name="";
          cout<<"Element deleted successfully "<<endl;
        }  
        else{
            cout<<"Element not found "<<endl;
        }
}

void Hashing::search(int r)
{
    int ind=r%10;
    int bg=r%10;
    if(hashtable[ind].roll_no==r)
    {
        cout<<"Roll no present at index :"<<ind<<"  "<<"Roll no : "<<r<<"  "<<"Name : "<<hashtable[ind].name<<endl;
        return;
    }
    else
    {
        int sq=1;
        ind=(ind+sq*sq)%10;
        while(hashtable[ind].roll_no!=r && ind!=bg)
        {
            sq+=1;
            ind=(ind+sq*sq)%10;
        }

        if(hashtable[ind].roll_no==r)
        {
            cout<<"Roll no present at index :"<<ind<<"  "<<"Roll no : "<<r<<"  "<<"Name : "<<hashtable[ind].name<<endl;
            return;
        }
        cout<<"Roll no not found !"<<endl;
    }
}

void Hashing::display()
{
    for(int i=0;i<10;i++)
    {
        if(hashtable[i].roll_no!=-1)
        {
            cout<<"Index : "<<i<<" "<<"Roll No : "<<hashtable[i].roll_no<<" "<<"Name : "<<hashtable[i].name<<endl;
        }
    }
}

int main()
{
    Hashing hs;
    hs.insert(62,"Tushar");
    hs.insert(19,"Deepanshu");
    hs.insert(9,"Ankit");
    hs.insert(11,"Aryan");
    hs.insert(21,"Divyanshi");
    hs.display();
    hs.search(11);
    hs.search(22);
    hs.delete_rno(11);
    hs.display();
    hs.search(21);

    
}