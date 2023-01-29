#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    node *head;
    int size;

    DoublyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // create new node and return his pointer
    node *create_new_node (int value)
    {
        node *new_node = new node(value);
        return new_node;
    }

    // insert new node in head
    void insert_at_head(int value)
    {
        node *new_node = create_new_node(value);
        size++;
        if (head == NULL) {
            head = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    // remove head node
    void remove_head()
    {
        if (head == NULL) return;
        node *a = head;
        node *b = head->next;
        delete a;
        head = b;
        if (b != NULL) {
            b->prev = NULL;
        }
        size--;
    }

    // get list size
    int get_size()
    {
        return size;
    }
};

class Stack {
public:
    DoublyLinkedList list;

    Stack() {}   

    void push(int value)
    {
        list.insert_at_head(value);
    }

    void pop()
    {
        list.remove_head();
    }

    int top()
    {
        if (list.get_size() == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return list.head->data;
    }
};

int main()
{
    Stack st;
    st.push(10);
    cout << st.top() << "\n";
    st.push(4);
    cout << st.top() << "\n";
    st.push(14);
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << "\n";

    return 0;
}
