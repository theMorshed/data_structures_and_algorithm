#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
};

class LinkedList {
public:
    node *head;
    int size;
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    node* createNewNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
    }

    void insertAtHead(int value)
    {
        node *newNode = createNewNode(value);
        if (head == NULL)
        {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    void printList()
    {
        node *newNode = head;
        while(newNode != NULL)
        {
            cout << newNode->data << " ";
            newNode = newNode->next;
        }
        cout << "\n";
    }

    int searchValue(int value)
    {
        int index = 0;
        node *newNode = head;
        while (newNode != NULL)
        {
            if (newNode->data == value)
            {
                return index;
            }
            newNode = newNode->next;
            index++;
        }

        return -1;
    }

    void searchAllPossible(int value)
    {
        int index = 0;
        node *newNode = head;
        while (newNode != NULL)
        {
            if (newNode->data == value)
                cout << value << " found at " << index << "\n";
            newNode = newNode->next;
            index++;
        }
    }

    int getSize()
    {
        return size;
    }

    int getSizeAnother()
    {
        node *a = head;
        int size = 0;
        while(a != NULL)
        {
            size++;
            a = a->next;
        }
        return size;
    }

    void insertByIndex(int index, int value)
    {
        if (index < 0 || index > size) return;
        if (index == 0) {
            insertAtHead(value);
            return;
        }
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1) {
            current_index++;
            a = a->next;
        }
        node *newNode = createNewNode(value);
        newNode->next = a->next;
        a->next = newNode;
        size++;
    }

    void deleteFromHead()
    {
        if (head == NULL) return;
        node *a = head;
        head = a->next;
        size--;
        delete a;
    }

    void deleteByIndex(int index)
    {
        if (index < 0 || index > size - 1) return;
        if (index == 0){
            deleteFromHead();
            return;
        }
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1)
        {
            current_index++;
            a = a->next;
        }
        node *b = a->next;
        a->next = b->next;
        size--;
        delete b;
    }

    void insertAfterValue(int value, int data)
    {
        node *a = head;
        while (a != NULL)
        {
            if (a->data == value)
                break;
            a = a->next;
        }
        if (a == NULL) {
            cout << "The value doesn't exist\n";
            return;
        }
        size++;
        node *newNode = createNewNode(data);
        newNode->next = a->next;
        a->next = newNode;
    }

    void reversePrintRecursively(node *a)
    {
        if (a == NULL)
            return;
        reversePrintRecursively(a->next);
        cout << a->data << " ";
    }

    void recursivePrint()
    {
        reversePrintRecursively(head);
        cout << "\n";
    }
};

int main()
{
    LinkedList li;
    li.insertAtHead(20);
    li.insertAtHead(10);
    li.printList();

    li.insertAtHead(20);
    li.insertAtHead(30);
    li.insertByIndex(0, 5);
    li.insertByIndex(1, 7);
    li.insertByIndex(3, 35);
    li.printList();
    cout << "Size: " << li.getSize() << "\n";
    li.deleteByIndex(4);
    cout << "After delete index 4\n";
    li.printList();
    cout << "Size: " << li.getSize() << "\n";
    li.printList();
    li.deleteFromHead();
    cout << "After Delete from head\n";
    li.printList();
    cout << "Size: " << li.getSize() << "\n";
    li.insertAfterValue(35, 38);
    li.printList();
    cout << "Size: " << li.getSize() << "\n";
    li.insertAfterValue(37, 38);
    li.recursivePrint();


    // cout << "10 is found at " << li.searchValue(10) << "\n";
    // cout << "20 is found at " << li.searchValue(20) << "\n";
    // cout << "5 is found at " << li.searchValue(5) << "\n";

    // li.searchAllPossible(10);
    // li.searchAllPossible(20);

    return 0;
}
