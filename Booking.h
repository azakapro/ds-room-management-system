#pragma once
#include <iostream>
#include <string>
using namespace std;

class Booking {
public:
    // Constructors and destructor
    Booking() { userID = 0; capacity = 0; }
    Booking(int userID, int capacity) {
        setUserID(userID);
        setCapacity(capacity);
    }
    Booking(const Booking& obj1) {
        setUserID(obj1.userID);
        setCapacity(obj1.capacity);
    }
    ~Booking() {}

    // Overloading the '=' operator
    Booking& operator=(const Booking& obj2) {
        setUserID(obj2.userID);
        setCapacity(obj2.capacity);
        return *this;
    }

    // Get and set methods for User ID
    void setUserID(int userID) {
        this->userID = userID;
    }
    int getUserID() {
        return userID;
    }
    // Get and set methods for room capacity
    void setCapacity(int capacity) {
        this->capacity = capacity;
    }
    int getCapacity() {
        return capacity;
    }

    void display() {
        cout << "User ID: " << userID << "\n" << "Capacity: " << capacity << endl;
    }

private:
    int userID;
    int capacity;
};