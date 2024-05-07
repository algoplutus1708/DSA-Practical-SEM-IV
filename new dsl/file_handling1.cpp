#include <bits/stdc++.h>
using namespace std;

struct student {
    int rollno;
    char name[50];
    char div;
    char addr[100];
};

void displayMenu() {
    cout << "\nMenu:\n"
         << "1. Create\n"
         << "2. Display\n"
         << "3. Insert\n"
         << "4. Search\n"
         << "5. Delete\n"
         << "6. Exit\n"
         << "Enter your choice: ";
}

void create() {
    ofstream fout("student.dat", ios::out | ios::binary | ios::app);
    if (!fout) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    student s;
    cout << "Enter roll no: ";
    cin >> s.rollno;
    cout << "Enter name: ";
    cin.ignore(); // Ignore previous newline character
    cin.getline(s.name, 50); // Read name with spaces
    cout << "Enter division: ";
    cin >> s.div;
    cout << "Enter address: ";
    cin.ignore(); // Ignore previous newline character
    cin.getline(s.addr, 100); // Read address with spaces
    fout.write(reinterpret_cast<char *>(&s), sizeof(s));
    cout << "Record written successfully." << endl;
    fout.close();
}

void display() {
    ifstream fin("student.dat", ios::in | ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    student s;
    while (fin.read(reinterpret_cast<char *>(&s), sizeof(s))) {
        cout << "Roll no: " << s.rollno << endl;
        cout << "Name: " << s.name << endl;
        cout << "Division: " << s.div << endl;
        cout << "Address: " << s.addr << endl << endl;
    }
    fin.close();
}

void insert() {
    ofstream fout("student.dat", ios::out | ios::binary | ios::app);
    if (!fout) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    student s;
    cout << "Enter roll no: ";
    cin >> s.rollno;
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(s.name, 50);
    cout << "Enter division: ";
    cin >> s.div;
    cout << "Enter address: ";
    cin.ignore();
    cin.getline(s.addr, 100);
    fout.write(reinterpret_cast<char *>(&s), sizeof(s));
    cout << "Record inserted successfully." << endl;
    fout.close();
}

void search() {
    int rollno;
    cout << "Enter roll no to search: ";
    cin >> rollno;
    ifstream fin("student.dat", ios::in | ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    student s;
    bool found = false;
    while (fin.read(reinterpret_cast<char *>(&s), sizeof(s))) {
        if (s.rollno == rollno) {
            cout << "Roll no: " << s.rollno << endl;
            cout << "Name: " << s.name << endl;
            cout << "Division: " << s.div << endl;
            cout << "Address: " << s.addr << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found" << endl;
    }
    fin.close();
}

void deleteRecord() {
    int rollno;
    cout << "Enter roll no to delete: ";
    cin >> rollno;
    ifstream fin("student.dat", ios::in | ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    ofstream fout("temp.dat", ios::out | ios::binary);
    if (!fout) {
        cerr << "Error: Unable to open temp file for writing." << endl;
        fin.close();
        return;
    }
    student s;
    bool found = false;
    while (fin.read(reinterpret_cast<char *>(&s), sizeof(s))) {
        if (s.rollno != rollno) {
            fout.write(reinterpret_cast<char *>(&s), sizeof(s));
        } else {
            found = true;
        }
    }
    fin.close();
    fout.close();
    if (!found) {
        cout << "Record not found" << endl;
        remove("temp.dat");
    } else {
        remove("student.dat");
        rename("temp.dat", "student.dat");
        cout << "Record deleted successfully" << endl;
    }
}

int main() {
    char choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case '1':
                create();
                break;
            case '2':
                display();
                break;
            case '3':
                insert();
                break;
            case '4':
                search();
                break;
            case '5':
                deleteRecord();
                break;
            case '6':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');
}