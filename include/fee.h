#ifndef FEE_H
#define FEE_H

#include <string>

class Fee {
private:
    std::string id;             // Fee ID
    std::string activityName;   // Associated activity name
    double amount;              // Fee amount

public:
    // Constructor
    Fee();

    // Function to add a new fee record
    void addFee();

    // Function to update fee information
    void updateFee();

    // Function to delete a fee record
    void deleteFee();

    // Function to list all fee records
    void listAllFees();

    // Function to search for a fee record by ID
    void searchFee();
};

#endif // FEE_H
