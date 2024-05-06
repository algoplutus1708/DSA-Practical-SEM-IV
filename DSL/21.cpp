/*
Department maintains student information. The file contains rollno, name, division 
and address. Allow user to add, delete, insert and search information of student. use 
sequential file to maintain the data 
*/


#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void addStudent(){
    cout<<"Enter Roll Number : ";
    string rno;
    cin>>rno;
    cout<<"Enter Name : ";
    cin.ignore();
    string name;
    getline(cin,name);
    
    ofstream fout("students.txt",ios::app);
    if(fout){
        fout<<rno<<":"<<name<<endl;
        cout<<"student added successfully"<<endl;
        fout.close();
    }
    else cout<<"error in opening file";
    
}

void deleteStud(){
    cout<<"Enter Roll Number to delete : ";
    string rno;
    cin>>rno;
    ifstream fin("students.txt");
    ofstream fout("temp.txt");
    string line;
    bool found=false;
    while(getline(fin,line)){
        if(line.substr(0,line.find(':'))==rno){
            found=true;
            continue;
        }
        fout<<line<<endl;
    }
    fin.close();
    fout.close();
    if(found){
        remove("students.txt");
        rename("temp.txt","students.txt");
    }
    else{
        remove("temp.txt");
        cout<<"Nothing to remove"<<endl;
    }

}

void search(){
    cout<<"Enter Roll Number to search : ";
    string rno;
    cin>>rno;
    ifstream fin("students.txt");
    string line;
    while(getline(fin,line)){
        if(line.substr(0,line.find(':'))==rno){
            cout<<"Details found ! ";
            cout<<line<<endl;
            fin.close();
            return;
        }
    }
    fin.close();
    cout<<"No such record exists"<<endl;
}

int main(){
    addStudent();
    addStudent();
    deleteStud();
    search();
    return 0;
}