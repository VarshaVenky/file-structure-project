#include <iostream>
#include <fstream>
#include <string>
#include "camper.h"
#include "staff.h"
#include "activity.h"
#include "fee.h"

using namespace std;

// Function prototypes
void showMainMenu();
void camperMenu();
void staffMenu();
void activityMenu();
void feeMenu();

// Main function
int main() {
    int choice;

    while (true) {
        showMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                camperMenu();
                break;
            case 2:
                staffMenu();
                break;
            case 3:
                activityMenu();
                break;
            case 4:
                feeMenu();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Display main menu
void showMainMenu() {
    cout << "\n...**WELCOME TO FILE STRUCTURE MANAGEMENT SYSTEM**...\n" << endl;
    cout << "1. Camper Information" << endl;
    cout << "2. Staff Information" << endl;
    cout << "3. Activity Information" << endl;
    cout << "4. Fee Structure" << endl;
    cout << "5. Exit" << endl;
}

// Camper Menu
void camperMenu() {
    int choice;
    Camper camper;

    while (true) {
        cout << "\n**CAMPER MENU**\n";
        cout << "1. New Registration" << endl;
        cout << "2. Update Camper Information" << endl;
        cout << "3. Delete Camper Information" << endl;
        cout << "4. List All Campers" << endl;
        cout << "5. Search Camper Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                camper.registerCamper();
                break;
            case 2:
                camper.updateCamper();
                break;
            case 3:
                camper.deleteCamper();
                break;
            case 4:
                camper.listAllCampers();
                break;
            case 5:
                camper.searchCamper();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Staff Menu
void staffMenu() {
    int choice;
    Staff staff;

    while (true) {
        cout << "\n**STAFF MENU**\n";
        cout << "1. Add New Staff" << endl;
        cout << "2. Update Staff Information" << endl;
        cout << "3. Delete Staff Information" << endl;
        cout << "4. List All Staff" << endl;
        cout << "5. Search Staff Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                staff.addStaff();
                break;
            case 2:
                staff.updateStaff();
                break;
            case 3:
                staff.deleteStaff();
                break;
            case 4:
                staff.listAllStaff();
                break;
            case 5:
                staff.searchStaff();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Activity Menu
void activityMenu() {
    int choice;
    Activity activity;

    while (true) {
        cout << "\n**ACTIVITY MENU**\n";
        cout << "1. Add New Activity" << endl;
        cout << "2. Update Activity Information" << endl;
        cout << "3. Delete Activity Information" << endl;
        cout << "4. List All Activities" << endl;
        cout << "5. Search Activity Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                activity.addActivity();
                break;
            case 2:
                activity.updateActivity();
                break;
            case 3:
                activity.deleteActivity();
                break;
            case 4:
                activity.listAllActivities();
                break;
            case 5:
                activity.searchActivity();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Fee Menu
void feeMenu() {
    int choice;
    Fee fee;

    while (true) {
        cout << "\n**FEE MENU**\n";
        cout << "1. Add New Fee" << endl;
        cout << "2. Update Fee Information" << endl;
        cout << "3. Delete Fee Information" << endl;
        cout << "4. List All Fees" << endl;
        cout << "5. Search Fee Information" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fee.addFee();
                break;
            case 2:
                fee.updateFee();
                break;
            case 3:
                fee.deleteFee();
                break;
            case 4:
                fee.listAllFees();
                break;
            case 5:
                fee.searchFee();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
