
#include<iostream>
#include<windows.h>
#include <iostream>
#include "Room.h"
#include "Booking.h"
#include "BinarySearchBooking.h"
#include "BinarySearchRoom.h"
#include "StackQueue.h"
#include <string>
using namespace std;

Waitlist person(5);
Stack room_capacity_check(2);
BookingReady temp_user;

int main()
{
    BinarySearchBooking nodeB, * bookingRoot = NULL;
    BinarySearchRoom nodeR, * roomRoot = NULL;
    Room searchRoom;


    system("Color 0A");
    cout << "\t\t\t\t\t\t\t";
    cout << "Time OVERFLOW";
    cout << endl;
    //Sleep(1000);
    system("cls");


    string name = "Azizullo", id, pass = "2022";
    //main page
MAIN:
    while (true) {
        system("cls");
        int i;
        cout << "[1] Admin \n[2] User \n[3] Exit" << endl;
        cin >> i;
        switch (i)
        {
        case 1: {
            //check admin
        CHECKADMIN:
            system("cls");
            int i = 2022;
            cout << ("Enter Top Secret Password!\n");
            cin >> i;

            if (i == 2022) {
                // Admin page
            ADMIN:
                while (true) {
                    system("cls");
                    int admin;
                    cout << "[1] Show bookings.\n[2] Add a room.\n[3] Room list\n[4] Delete rooms.\n[5] Main Page.\n";
                    cin >> admin;
                    switch (admin) {
                    case 1:
                        cout << "\t\t\t Bookings \n";
                        nodeB.traverse(bookingRoot);
                        Sleep(2000);
                        break;
                    case 2:
                    {
                        cout << "\t\t\t Add Rooms \n";
                        int capacity;
                        string roomID;

                        // Initializing data members
                        cout << "Enter room id: ";
                        cin >> roomID;

                        cout << "Enter room capacity: ";
                        cin >> capacity;

                        // Inserting into BST
                        Room room(roomID, capacity, false);
                        roomRoot = nodeR.insert(roomRoot, room);
                        break;
                    }
                    case 3: 
                    {
                        cout << "\t Room list \n";
                        nodeR.traverse(roomRoot);
                        Sleep(2000);
                        break;
                    }
                    case 4:
                    {
                        cout << "\t\t\t Delete rooms \n";
                        //delete room
                        string roomID;
                        int capacity;
                        cout << "Enter room id: ";
                        cin >> roomID;
                        cout << "Enter capacity: ";
                        cin >> capacity;

                        Room roomToBeDel(roomID, capacity, false);

                        searchRoom = roomRoot->find(roomRoot, roomToBeDel);

                        roomRoot = roomRoot->remove(roomRoot, searchRoom);

                        break;
                    }
                    case 5:
                        goto MAIN;
                        break;
                    default:
                        cout << "\t\t\t Input from 1-4 \n";
                        goto ADMIN;
                        break;
                    }
                }
            }
            else {
                goto CHECKADMIN;
            }
            break;
        }
        case 2: {
            //userpage
        USERPAGE:
            while (true) {
                system("cls");
                int i;
                cout << "[1] Sign In.\n[2] Sign Up.\n[3] Main Page\n";
                cin >> i;
                switch (i) {
                case 1:
                    //sign in
                SIGNIN:
                    while (true) {
                        string tmp1, tmp2;
                        cout << "Enter your name: " << endl;
                        cin >> tmp1;

                        cout << "Enter Password: " << endl;
                        cin >> tmp2;

                        
                            if (tmp1 == name && tmp2 == pass) {
                                //signedin
                            SIGNEDIN:
                                system("cls");
                                while (true) {
                                    int i;
                                    cout << "[1] Booking.\n[2] Log out.\n";
                                    cin >> i;
                                    if (i == 1) {
                                        //book
                                    BOOK:
                                        system("cls");
                                        while (true) {
                                            int userID, capacity;
                                            // Initializing data members
                                            cout << "Enter your ID number: ";
                                            cin >> userID;
                                            cout << "Enter number of participants: ";
                                            cin >> capacity;
                                            temp_user.setID(userID);
                                            temp_user.setCapacity(capacity);
                                            temp_user = temp_user.returnOrder(person, room_capacity_check);
                                            // Adding booking to the BST
                                            Booking booking(temp_user.getID(), temp_user.getCapacity());
                                            bookingRoot = nodeB.insert(bookingRoot, booking);
                                            Sleep(1000);
                                            goto SIGNEDIN;
                                        }
                                    }if (i == 2) {
                                        goto MAIN;
                                    }
                                    else {
                                        goto SIGNEDIN;
                                    }
                                }
                            }
                            else {
                                cout << "Try again ";
                                goto SIGNIN;
                            }
                    }
                    break;
                case 2:
                    //signup
                SIGNUP:
                    cout << "Enter your name: " << endl;
                    cin >> name;
                    cout << "Enter your ID: " << endl;
                    cin >> id;
                    cout << "Enter Password: " << endl;
                    cin >> pass;
                    cout << "Confirm the password: " << endl;
                    cin >> pass;
                    goto USERPAGE;
                    break;
                case 3:
                    goto MAIN;
                    break;
                default:
                    cout << "\t\t\t Input from 1-3 \n";
                    goto USERPAGE;
                    break;
                }
            }
            break;
        }
        case 0: {
            exit(0);
        }
        default:
            break;
        }
    }

    system("pause");
    return 0;
}