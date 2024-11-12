#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "activity.h"

using namespace std;

Activity::Activity() {}

// Add a new activity
void Activity::addActivity() {
    cout << "Enter Activity ID: ";
    cin >> id;
    cout << "Enter Activity Name: ";
    cin.ignore(); // To clear the newline character left by cin
    getline(cin, name);
    cout << "Enter Activity Description: ";
    getline(cin, description);
    cout << "Enter Duration (in hours): ";
    cin >> duration;

    ofstream file("activity.txt", ios::app);
    if (file.is_open()) {
        file << id << "|" << name << "|" << description << "|" << duration << "$\n";
        file.close();
        cout << "**Successfully Added**" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}

// Update activity information
void Activity::updateActivity() {
    string searchId;
    cout << "Enter activity ID to update: ";
    cin >> searchId;

    fstream file("activity.txt", ios::in | ios::out);
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
            getline(cin, name);
            cout << "Enter New Description: ";
            getline(cin, description);
            cout << "Enter New Duration (in hours): ";
            cin >> duration;

            // Move to the beginning of the found line
            file.seekp(pos - line.length() - 1);
            file << id << "|" << name << "|" << description << "|" << duration << "$\n";
            cout << "**Successfully Updated**" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Activity with ID " << searchId << " not found!" << endl;
    }
    file.close();
}

// Delete activity information
void Activity::deleteActivity() {
    string searchId;
    cout << "Enter activity ID to delete: ";
    cin >> searchId;

    ifstream file("activity.txt");
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
        cout << "Activity with ID " << searchId << " not found!" << endl;
    }

    file.close();
    temp.close();
    remove("activity.txt");
    rename("temp.txt", "activity.txt");
}

// List all activities
void Activity::listAllActivities() {
    ifstream file("activity.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    cout << setw(10) << "ID" << setw(20) << "NAME" << setw(30) << "DESCRIPTION" << setw(10) << "DURATION" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

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
                case 2: cout << setw(30) << token; break;
            }
            line.erase(0, pos + 1);
            fieldCount++;
        }
        cout << setw(10) << line.substr(0, line.find('$')) << " hours" << endl;
    }
    file.close();
}

// Search for an activity by ID
void Activity::searchActivity() {
    string searchId;
    cout << "Enter activity ID to search: ";
    cin >> searchId;

    ifstream file("activity.txt");
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

            cout << setw(10) << "ID" << setw(20) << "NAME" << setw(30) << "DESCRIPTION" << setw(10) << "DURATION" << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;

            while ((pos = line.find('|')) != string::npos) {
                token = line.substr(0, pos);
                switch (fieldCount) {
                    case 0: cout << setw(10) << token; break;
                    case 1: cout << setw(20) << token; break;
                    case 2: cout << setw(30) << token; break;
                }
                line.erase(0, pos + 1);
                fieldCount++;
            }
            cout << setw(10) << line.substr(0, line.find('$')) << " hours" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Activity with ID " << searchId << " not found!" << endl;
    }
    file.close();
}
