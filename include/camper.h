#ifndef CAMPER_H
#define CAMPER_H

#include <string>

class Camper {
private:
    std::string rId;         // Registration ID
    std::string fName;       // First name
    std::string lName;       // Last name
    std::string mNumber;     // Mobile number
    std::string state;       // State

public:
    // Constructor
    Camper();

    // Function to add a new camper
    void registerCamper();

    // Function to update camper information
    void updateCamper();

    // Function to delete a camper record
    void deleteCamper();

    // Function to list all campers
    void listAllCampers();

    // Function to search for a camper by registration ID
    void searchCamper();
};

#endif // CAMPER_H
