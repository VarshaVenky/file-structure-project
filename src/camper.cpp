#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "camper.h"

using namespace std;

Camper::Camper() {}

// Register a new camper
void Camper::registerCamper() {
    cout << "Enter Registration ID: ";
    cin >> rId;
    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Mobile Number: ";
    cin >> mNumber;
    cout << "Enter State: ";
    cin >> state;

    ofstream file("camper.txt", ios::app);
    if (file.is_open()) {
        file << rId << "|" << fName << "|" << lName << "|" << mNumber << "|" << state << "$\n";
        file.close();
        cout << "**Successfully Added**" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}

// Update camper information
void Camper::updateCamper() {
    string searchId;
    cout << "Enter camper registration ID to update: ";
    cin >> searchId;

    fstream file("camper.txt", ios::in | ios::out);
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
            cout << "Enter New Mobile Number: ";
            cin >> mNumber;
            cout << "Enter New State: ";
            cin >> state;

            // Move to the beginning of the found line
            file.seekp(pos - line.length() - 1);
            file << rId << "|" << fName << "|" << lName << "|" << mNumber << "|" << state << "$\n";
            cout << "**Successfully Updated**" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Camper with ID " << searchId << " not found!" << endl;
    }
    file.close();
}

// Delete camper information
void Camper::deleteCamper() {
    string searchId;
    cout << "Enter camper registration ID to delete: ";
    cin >> searchId;

    ifstream file("camper.txt");
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
        cout << "Camper with ID " << searchId << " not found!" << endl;
    }

    file.close();
    temp.close();
    remove("camper.txt");
    rename("temp.txt", "camper.txt");
}

// List all campers
void Camper::listAllCampers() {
    ifstream file("camper.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    cout << setw(10) << "REG.ID" << setw(15) << "F.NAME" << setw(15) << "L.NAME" << setw(15) << "M.NUMBER" << setw(10) << "STATE" << endl;
    cout << "---------------------------------------------------------------------" << endl;

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
                case 3: cout << setw(15) << token; break;
            }
            line.erase(0, pos + 1);
            fieldCount++;
        }
        cout << setw(10) << line.substr(0, line.find('$')) << endl;
    }
    file.close();
}

// Search for a camper by registration ID
void Camper::searchCamper() {
    string searchId;
    cout << "Enter camper registration ID to search: ";
    cin >> searchId;

    ifstream file("camper.txt");
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

            cout << setw(10) << "REG.ID" << setw(15) << "F.NAME" << setw(15) << "L.NAME" << setw(15) << "M.NUMBER" << setw(10) << "STATE" << endl;
            cout << "---------------------------------------------------------------------" << endl;

            while ((pos = line.find('|')) != string::npos) {
                token = line.substr(0, pos);
                switch (fieldCount) {
                    case 0: cout << setw(10) << token; break;
                    case 1: cout << setw(15) << token; break;
                    case 2: cout << setw(15) << token; break;
                    case 3: cout << setw(15) << token; break;
                }
                line.erase(0, pos + 1);
                fieldCount++;
            }
            cout << setw(10) << line.substr(0, line.find('$')) << endl;
            break;
        }
    }
    if (!found) {
        cout << "Camper with ID " << searchId << " not found!" << endl;
    }
    file.close();
}
