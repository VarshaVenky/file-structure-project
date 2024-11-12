#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "staff.h"

using namespace std;

Staff::Staff() {}

// Add a new staff member
void Staff::addStaff() {
    cout << "Enter Staff ID: ";
    cin >> id;
    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Qualification: ";
    cin >> qualification;
    cout << "Enter Mobile Number: ";
    cin >> mNumber;
    cout << "Enter Pay: ";
    cin >> pay;

    ofstream file("staff.txt", ios::app);
    if (file.is_open()) {
        file << id << "|" << fName << "|" << lName << "|" << qualification << "|" << mNumber << "|" << pay << "$\n";
        file.close();
        cout << "**Successfully Added**" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}

// Update staff information
void Staff::updateStaff() {
    string searchId;
    cout << "Enter staff ID to update: ";
    cin >> searchId;

    fstream file("staff.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;
    long pos;
    while (getline(file, line)) {
        pos = file.tellg();
        if (line.find(searchId) == 0) {
            found = true;
            cout << "Enter New First Name: ";
            cin >> fName;
            cout << "Enter New Last Name: ";
            cin >> lName;
            cout << "Enter New Qualification: ";
            cin >> qualification;
            cout << "Enter New Mobile Number: ";
            cin >> mNumber;
            cout << "Enter New Pay: ";
            cin >> pay;

            // Move to the beginning of the found line
            file.seekp(pos - line.length() - 1);
            file << id << "|" << fName << "|" << lName << "|" << qualification << "|" << mNumber << "|" << pay << "$\n";
            cout << "**Successfully Updated**" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Staff with ID " << searchId << " not found!" << endl;
    }
    file.close();
}

// Delete staff information
void Staff::deleteStaff() {
    string searchId;
    cout << "Enter staff ID to delete: ";
    cin >> searchId;

    ifstream file("staff.txt");
    ofstream temp("temp.txt");
    if (!file.is_open() || !temp.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(searchId) != 0) {
            temp << line << endl;
        } else {
            found = true;
            cout << "**Deleted successfully**" << endl;
        }
    }

    if (!found) {
        cout << "Staff with ID " << searchId << " not found!" << endl;
    }

    file.close();
    temp.close();
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
}

// List all staff members
void Staff::listAllStaff() {
    ifstream file("staff.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    cout << setw(10) << "ID" << setw(15) << "F.NAME" << setw(15) << "L.NAME" << setw(20) << "QUALIFICATION" << setw(15) << "M.NUMBER" << setw(10) << "PAY" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t pos = 0;
        string token;
        int fieldCount = 0;

        while ((pos = line.find('|')) != string::npos) {
            token = line.substr(0, pos);
            switch (fieldCount) {
                case 0: cout << setw(10) << token; break;
                case 1: cout << setw(15) << token; break;
                case 2: cout << setw(15) << token; break;
                case 3: cout << setw(20) << token; break;
                case 4: cout << setw(15) << token; break;
            }
            line.erase(0, pos + 1);
            fieldCount++;
        }
        cout << setw(10) << line.substr(0, line.find('$')) << endl;
    }
    file.close();
}

// Search for a staff member by ID
void Staff::searchStaff() {
    string searchId;
    cout << "Enter staff ID to search: ";
    cin >> searchId;

    ifstream file("staff.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(searchId) == 0) {
            found = true;
            size_t pos = 0;
            string token;
            int fieldCount = 0;

            cout << setw(10) << "ID" << setw(15) << "F.NAME" << setw(15) << "L.NAME" << setw(20) << "QUALIFICATION" << setw(15) << "M.NUMBER" << setw(10) << "PAY" << endl;
            cout << "-------------------------------------------------------------------------------------------" << endl;

            while ((pos = line.find('|')) != string::npos) {
                token = line.substr(0, pos);
                switch (fieldCount) {
                    case 0: cout << setw(10) << token; break;
                    case 1: cout << setw(15) << token; break;
                    case 2: cout << setw(15) << token; break;
                    case 3: cout << setw(20) << token; break;
                    case 4: cout << setw(15) << token; break;
                }
                line.erase(0, pos + 1);
                fieldCount++;
            }
            cout << setw(10) << line.substr(0, line.find('$')) << endl;
            break;
        }
    }
    if (!found) {
        cout << "Staff with ID " << searchId << " not found!" << endl;
    }
    file.close();
}
