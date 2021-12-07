#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room {
public:
    Room() { roomID = "AAA", capacity = 0, isEmpty = true; }
    Room(string roomID, int capacity, bool isEmpty) {
        setRoomID(roomID);
        setCapacity(capacity);
        setIsEmpty(isEmpty);
    }
    Room(const Room& obj1) {
        setRoomID(obj1.roomID);
        setCapacity(obj1.capacity);
        setIsEmpty(obj1.isEmpty);
    }
    ~Room() {}

    // Overloading the '=' operator
    Room& operator=(const Room& obj2) {
        setRoomID(obj2.roomID);
        setCapacity(obj2.capacity);
        setIsEmpty(obj2.isEmpty);
        return *this;
    }

    // Set and get for room
    void setRoomID(string roomID) {
        this->roomID = roomID;
    }
    string getRoomID() {
        return roomID;
    }

    // Get and set methods for room capacity
    void setCapacity(int capacity) {
        this->capacity = capacity;
    }
    int getCapacity() {
        return capacity;
    }

    // Get and set methods for status of the room
    void setIsEmpty(bool isEmpty) {
        this->isEmpty = isEmpty;
    }
    bool getIsEmpty() {
        return isEmpty;
    }

    void display() {
        cout << "Room ID: " << roomID << "\n" << "Room Capacity: " << capacity << "\n" << "Status: " << isEmpty << endl;
    }
private:
    string roomID;
    int capacity;
    bool isEmpty;

};