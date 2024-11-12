#ifndef STAFF_H
#define STAFF_H

#include <string>

class Staff {
private:
    std::string id;            // Staff ID
    std::string fName;         // First name
    std::string lName;         // Last name
    std::string qualification; // Qualification
    std::string mNumber;       // Mobile number
    std::string pay;           // Pay

public:
    // Constructor
    Staff();

    // Function to add a new staff member
    void addStaff();

    // Function to update staff information
    void updateStaff();

    // Function to delete a staff record
    void deleteStaff();

    // Function to list all staff members
    void listAllStaff();

    // Function to search for a staff member by ID
    void searchStaff();
};

#endif // STAFF_H
