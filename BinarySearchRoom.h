#pragma once
#include <iostream>
#include "Room.h"
#include <string>
using namespace std;

class BinarySearchRoom {
private:
    Room data;
    BinarySearchRoom* left;
    BinarySearchRoom* right;
public:
    BinarySearchRoom() {
        left = right = NULL;
    }
    BinarySearchRoom(Room obj) {
        data = (Room)obj;
        left = right = NULL;
    }

    BinarySearchRoom* minValue(BinarySearchRoom* root) {
        BinarySearchRoom* current = root;

        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    BinarySearchRoom* insert(BinarySearchRoom* root, Room data) {
        if (root == NULL) {
            return new BinarySearchRoom(data);
        }
        else if (data.getCapacity() > root->data.getCapacity()) {
            root->right = insert(root->right, data);
        }
        else {
            root->left = insert(root->left, data);
        }
        return root;
    }

    void traverse(BinarySearchRoom* root) {
        if (!root) {
            return;
        }
        traverse(root->left);
        cout << "User ID: " << root->data.getRoomID() << "\n" << "Room Capacity: " << root->data.getCapacity() << endl;
        traverse(root->right);
    }

    Room find(BinarySearchRoom* root, Room data) {
        if (root == NULL || root->data.getCapacity() == data.getCapacity()) {
            return root->data;
        }
        if (root->data.getCapacity() < data.getCapacity()) {
            return find(root->right, data);
        }
        else {
            return find(root->left, data);
        }
    }

    BinarySearchRoom* remove(BinarySearchRoom* root, Room data) {
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
                BinarySearchRoom* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                BinarySearchRoom* temp = root->left;
                free(root);
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            BinarySearchRoom* temp = minValue(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = remove(root->right, temp->data);
        }
        return root;
    }



};


