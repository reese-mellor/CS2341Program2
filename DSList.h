#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position
 *
 * 1. Use a postion index to refer to an element. This is simpler to
 *    implement compared to iterators (see iterator version), but does not
 *    play as nicely with the STL.
 * 2. Optional: Use a sentinel node (a node without data that represents the
 *    beginning of the list).
 * 
 * @tparam Object 
 */
#include <stdio.h>
#include <iostream>
using namespace std;
template <typename Object>
class DSList {
private:
    /**
      * @brief The nested Node data structure
      *
      * struct is in C++ a class with all public members
      */
    struct Node { //creates a node
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {};

        Node *getNext() { return next; };
    };

    Node *head; //creates a node pointer
    char *identifier; //creates an identifier (character pointer)
public:
    // Default construction
    DSList() {
        head = new Node();
//        identifier = nullptr;
    }

    // Copy constructor
    DSList(char *identifier) { //can pass in a character
        head = nullptr;
        this->identifier = identifier;
        DSList();
        head = nullptr;
        identifier = nullptr;
    }

    // Destructor
    ~DSList() {
        clear();
    }

    // size
    int size() {
        int size = 0;
        Node* current = head->next;
        while (current != nullptr) { //&& head->next != nullptr
            size++;
            current = current->next;
        }
        return size;
    }

    // empty? -- checks to
    bool isEmpty() {
        Node *current = head;
        if (current == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    // clear
    void clear() {
        // frees the memory
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr) {
            previous = current;
            current = current->next;
            delete previous;
        }
        head = nullptr;
    }

    // find an element with a specific value (and return the position. First element in list is pos 0).
    int elementAt(Object toFind) {
        //create temp
        Node *temp = head;
        for (int i = 0; i < size(); i++) {
            if (temp->data == toFind) {
                return i;
            }
            temp = temp->next;
        }
    }

    // insert in front (push_front).
    void push_front(Object obj) {
        Node *current = new Node(obj);

        if (isEmpty() == true) {
            head = current;
        } else {
            current->next = head;
            head = current;
        }
    }

    // insert at a specified position.
    void insert(int index, Object newNode) {
        Node *current = head;
        int counter = 0;
        while (current != nullptr) {
            if (counter == index - 1) {
                Node *temp(newNode);
                temp->next = current->next;
                current->next = temp;
                return;
            }
            counter++;
            current = current->next;
        }
    }

    // remove the element in front (pop_front)
    Object pop_front() {
        Node *temp = head;
        head = head->next;
        Object tempData = temp->data;
        delete temp;
        return tempData;
    }

    void push_back(Object value) {
        Node *current = head;
        if (current->next == nullptr) {
            // create a newNode
            Node *newNode = new Node();
            newNode->data = value; //setValue(value);
            current->next = newNode;
        }
        else {
            // iterate until we get to the end of the list
            while (current->next != nullptr) {
                current = current->next;
            }
            // now create a new ListNode
            Node *newNode = new Node();
            newNode->data = value;
            current->next = newNode; //setNext(newNode);
        }
    }
        // remove using position.
        void remove_at(int position) {
            Node *current = head;
            Node *previous;
            for (int i = 0; i < size(); i++) {
                previous = current; // save current
                current = current->next;
            }

            if (current == head) {
                // first one is being removed
                head = current->next;
                delete current;
            } else {
                previous->setNext(current->next);
                delete current;
            }
        }
        // remove an element with a specific value (find and remove)
        void removeValAt(int value) {
            remove_at(elementAt(value));
        }
        Object gethead() {
            return head->data;
        }
        void display() {
            Node *current = head;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->next;
            }
        }
};

#endif
