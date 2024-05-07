#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int rollno;
    string name;
    char division;
    string address;
};

// Function prototypes
void addRecord(fstream& file);
void displayRecord(fstream& file);
void searchRecord(fstream& file);
void deleteRecord(fstream& file);
void insertRecord(fstream& file);

int main() {
    fstream file("student.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error: Unable to open file for reading and writing." << endl;
        return 1;
    }

    char choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Record\n"
             << "2. Display Records\n"
             << "3. Search Record\n"
             << "4. Delete Record\n"
             << "5. Insert Record\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addRecord(file);
                break;
            case '2':
                displayRecord(file);
                break;
            case '3':
                searchRecord(file);
                break;
            case '4':
                deleteRecord(file);
                break;
            case '5':
                insertRecord(file);
                break;
            case '6':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '6');

    file.close();
    return 0;
}

// Function to add a record
void addRecord(fstream& file) {
    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollno;
    cin.ignore(); // Ignore newline character
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore(); // Ignore newline character
    cout << "Enter Address: ";
    getline(cin, student.address);

    file.seekp((student.rollno - 1) * sizeof(Student)); // Move file pointer to the correct position
    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    cout << "Record added successfully." << endl;
}

// Function to display all records
void displayRecord(fstream& file) {
    file.seekg(0, ios::beg); // Move file pointer to the beginning
    Student student;
    cout << "Roll No  Name           Division  Address\n";
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << setw(8) << student.rollno << " " << setw(14) << student.name << " " << setw(9) << student.division << " " << student.address << endl;
    }
}

// Function to search for a record
void searchRecord(fstream& file) {
    int rollno;
    cout << "Enter Roll No to search: ";
    cin >> rollno;
    file.seekg((rollno - 1) * sizeof(Student)); // Move file pointer to the correct position
    Student student;
    if (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Roll No: " << student.rollno << endl;
        cout << "Name: " << student.name << endl;
        cout << "Division: " << student.division << endl;
        cout << "Address: " << student.address << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

// Function to delete a record
void deleteRecord(fstream& file) {
    int rollno;
    cout << "Enter Roll No to delete: ";
    cin >> rollno;
    file.seekg((rollno - 1) * sizeof(Student)); // Move file pointer to the correct position
    Student student;
    if (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        Student emptyStudent = {0, "", ' ', ""}; // Empty record
        file.seekp((rollno - 1) * sizeof(Student)); // Move file pointer to the correct position for writing
        file.write(reinterpret_cast<char*>(&emptyStudent), sizeof(Student));
        cout << "Record with Roll No " << rollno << " deleted successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

// Function to insert a record
void insertRecord(fstream& file) {
    int rollno;
    cout << "Enter Roll No to insert: ";
    cin >> rollno;
    file.seekg((rollno - 1) * sizeof(Student)); // Move file pointer to the correct position
    Student student;
    if (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Record with Roll No " << rollno << " already exists." << endl;
    } else {
        addRecord(file);
    }
}
