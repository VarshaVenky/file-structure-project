#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "fee.h"

using namespace std;

Fee::Fee() {}

// Add a new fee record
void Fee::addFee() {
    cout << "Enter Fee ID: ";
    cin >> id;
    cout << "Enter Activity Name: ";
    cin.ignore(); // To clear the newline character left by cin
    getline(cin, activityName);
    cout << "Enter Fee Amount: ";
    cin >> amount;

    ofstream file("fee.txt", ios::app);
    if (file.is_open()) {
        file << id << "|" << activityName << "|" << amount << "$\n";
        file.close();
        cout << "**Successfully Added**" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}

// Update fee information
void Fee::updateFee() {
    string searchId;
    cout << "Enter fee ID to update: ";
    cin >> searchId;

    fstream file("fee.txt", ios::in | ios::out);
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
            cout << "Enter New Activity Name: ";
            cin.ignore(); // Clear newline character
            getline(cin, activityName);
            cout << "Enter New Fee Amount: ";
            cin >> amount;

            // Move to the beginning of the found line
            file.seekp(pos - line.length() - 1);
            file << id << "|" << activityName << "|" << amount << "$\n";
            cout << "**Successfully Updated**" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Fee record with ID " << searchId << " not found!" << endl;
    }
    file.close();
}

// Delete fee information
void Fee::deleteFee() {
    string searchId;
    cout << "Enter fee ID to delete: ";
    cin >> searchId;

    ifstream file("fee.txt");
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
        cout << "Fee record with ID " << searchId << " not found!" << endl;
    }

    file.close();
    temp.close();
    remove("fee.txt");
    rename("temp.txt", "fee.txt");
}

// List all fee records
void Fee::listAllFees() {
    ifstream file("fee.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    cout << setw(10) << "ID" << setw(20) << "ACTIVITY NAME" << setw(10) << "AMOUNT" << endl;
    cout << "-------------------------------------------------" << endl;

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
                case 1: cout << setw(20) << token; break;
            }
            line.erase(0, pos + 1);
            fieldCount++;
        }
        cout << setw(10) << line.substr(0, line.find('$')) << endl;
    }
    file.close();
}

// Search for a fee record by ID
void Fee::searchFee() {
    string searchId;
    cout << "Enter fee ID to search: ";
    cin >> searchId;

    ifstream file("fee.txt");
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

            cout << setw(10) << "ID" << setw(20) << "ACTIVITY NAME" << setw(10) << "AMOUNT" << endl;
            cout << "-------------------------------------------------" << endl;

            while ((pos = line.find('|')) != string::npos) {
                token = line.substr(0, pos);
                switch (fieldCount) {
                    case 0: cout << setw(10) << token; break;
                    case 1: cout << setw(20) << token; break;
                }
                line.erase(0, pos + 1);
                fieldCount++;
            }
            cout << setw(10) << line.substr(0, line.find('$')) << endl;
            break;
        }
    }
    if (!found) {
        cout << "Fee record with ID " << searchId << " not found!" << endl;
    }
    file.close();
}
