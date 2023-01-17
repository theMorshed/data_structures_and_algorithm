#include <bits/stdc++.h>
using namespace std;

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

class SinglyLinkedList {
public:
    node *head;
    int size;

    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    node *createNewNode(int value)
    {
        node *newNode = new node(value);
        return newNode;
    }

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

    void printList()
    {
        node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertNodeAtHead(40);
    list.insertNodeAtHead(30);
    list.insertNodeAtHead(20);
    list.printList();

    return 0;
}