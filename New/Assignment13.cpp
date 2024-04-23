#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    string division;
    string address;

    Student(int rollNo, const string &name, const string &division, const string &address)
    {
        this->name = name;
        this->rollNo = rollNo;
        this->division = division;
        this->address = address;
    }
};

const string FILE_PATH = "student_data.txt";

void addStudent(const Student &student)
{

    ofstream outFile(FILE_PATH, ios::app);

    if (outFile.is_open())
    {
        outFile << student.rollNo << "," << student.name << "," << student.division << "," << student.address << endl;
        cout << "Student added successfully!" << endl;
        outFile.close();
    }
    else
    {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

vector<Student> readStudentsFromFile()
{

    vector<Student> students;

    ifstream inFile(FILE_PATH);

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            stringstream ss(line);
        
            string token;
            vector<string> tokens;

            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            // cout << "Contents of ss: ";
            // for (const string &token : tokens)
            // {
            //     cout << token << " ";
            // }
            // cout << endl;
            
            if (tokens.size() == 4)
            {
                int rollNo = stoi(tokens[0]);
                students.emplace_back(rollNo, tokens[1], tokens[2], tokens[3]);
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open file for reading." << endl;
    }
    return students;
}

void displayStudent(const Student &student)
{
    cout << "Roll No: " << student.rollNo << ", Name: " << student.name
         << ", Division: " << student.division << ", Address: " << student.address << endl;
}

void displayAllStudents()
{
    vector<Student> students = readStudentsFromFile();

    cout << "List of students:" << endl;

    for (size_t i = 0; i < students.size(); ++i)
    {
        displayStudent(students[i]);
    }
}

int main()
{
    while (true)
    {
        cout << "\n1. Add Student\n2. Display All Students\n3. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int rollNo;
            string name, division, address;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Division: ";
            cin >> division;
            cout << "Enter Address: ";
            cin >> address;
            addStudent(Student(rollNo, name, division, address));
            break;
        }
        case 2:
            displayAllStudents();
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
