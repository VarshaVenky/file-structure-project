#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

class Activity {
private:
    std::string id;             // Activity ID
    std::string name;           // Activity name
    std::string description;    // Activity description
    int duration;               // Duration of the activity in hours

public:
    // Constructor
    Activity();

    // Function to add a new activity
    void addActivity();

    // Function to update activity information
    void updateActivity();

    // Function to delete an activity record
    void deleteActivity();

    // Function to list all activities
    void listAllActivities();

    // Function to search for an activity by ID
    void searchActivity();
};

#endif // ACTIVITY_H
