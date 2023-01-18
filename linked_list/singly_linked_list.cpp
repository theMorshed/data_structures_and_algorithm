#include <bits/stdc++.h>
using namespace std;

// node structure 
class node {
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }    
};

// linked list class
class SinglyLinkedList {
public:
    node *head;
    int size;

    // constructor
    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // create new node before add in the list
    node *createNewNode(int value)
    {
        node *newNode = new node(value);
        return newNode;
    }

    // add node in head
    void insertNodeAtHead(int value)
    {
        node *newNode = createNewNode(value);
        size++;
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // print the whole list
    void printList()
    {
        node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // get size
    void getSize()
    {
        cout << size << "\n";
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertNodeAtHead(40);
    list.insertNodeAtHead(30);
    list.insertNodeAtHead(20);
    list.printList();
    list.getSize();

    return 0;
}