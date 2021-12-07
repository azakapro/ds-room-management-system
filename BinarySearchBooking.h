#pragma once
#include <iostream>
#include "Booking.h"
#include <string>
using namespace std;

class BinarySearchBooking {
private:
    Booking data;
    BinarySearchBooking* left;
    BinarySearchBooking* right;
public:
    BinarySearchBooking() {
        left = right = NULL;
    }

    BinarySearchBooking(Booking obj) {
        data = (Booking)obj;
        left = right = NULL;
    }

    BinarySearchBooking* minValue(BinarySearchBooking* root) {
        BinarySearchBooking* current = root;

        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    BinarySearchBooking* insert(BinarySearchBooking* root, Booking data) {
        if (root == NULL) {
            return new BinarySearchBooking(data);
        }
        else if (data.getCapacity() > root->data.getCapacity()) {
            root->right = insert(root->right, data);
        }
        else {
            root->left = insert(root->left, data);
        }
        return root;
    }

    void traverse(BinarySearchBooking* root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        cout << "User ID: " << root->data.getUserID() << "\n" << "Booked Room Capacity: " << root->data.getCapacity() << endl;
        traverse(root->right);
    }

    BinarySearchBooking* find(BinarySearchBooking* root, Booking data) {
        if (root == NULL || root->data.getCapacity() == data.getCapacity()) {
            return root;
        }
        if (root->data.getCapacity() < data.getCapacity()) {
            return find(root->right, data);
        }
        else {
            return find(root->left, data);
        }
    }

    BinarySearchBooking* remove(BinarySearchBooking* root, Booking data) {
        if (root == NULL) {
            return root;
        }
        if (data.getCapacity() < root->data.getCapacity()) {
            root->left = remove(root->left, data);
        }
        else if (data.getCapacity() > root->data.getCapacity()) {
            root->right = remove(root->right, data);
        }
        else {
            // Node has no child
            if (root->left == NULL and root->right == NULL)
                return NULL;

            // Node with only one child or no child
            else if (root->left == NULL) {
                BinarySearchBooking* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                BinarySearchBooking* temp = root->left;
                free(root);
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            BinarySearchBooking* temp = minValue(root->right);
            // Copy the inorder successor's content to this node
            root->data = temp->data;
            // Delete the inorder successor
            root->right = remove(root->right, temp->data);
        }
        return root;
    }



};