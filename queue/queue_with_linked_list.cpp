#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int value) 
    {
        data = value;
        next = NULL;
    }    
};

class Queue {
public:
    node *head;
    node *tail;
    int sz;

    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }    

    node *create_node(int value)
    {
        node *new_node = new node(value);
        return new_node;
    }

    void enqueue(int value)
    {
        node *new_node = create_node(value);
        sz++;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }

    void dequeue()
    {
        if (sz == 0) {
            cout << "Queue is empty\n";
            return;
        }
        if (sz == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node *a = head;
        head = head->next;
        sz--;
        delete a;
    }

    int front()
    {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    cout << "Queue size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << "Queue size: " << q.size() << "\n";

    return 0;
}