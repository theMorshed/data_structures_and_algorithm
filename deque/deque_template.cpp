#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
public:
    T data;
    node *next;
    node *prev;

    node(T value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }    
};

template<class T>
class Deque {
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }    

    node<T> *create_new_node(T value)
    {
        node<T> *new_node = new node<T>(value);
        return new_node;
    }

    void insert_at_head(T value)
    {
        node<T> *new_node = create_new_node(value);
        if (sz == 0) {
            head = new_node;
            tail = new_node;
            sz++;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        sz++;
    }

    void remove_from_head()
    {
        if (sz == 0) {
            cout << "Deque is empty\n";
            return;
        }
        if (sz == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<T> *a = head;
        head = head->next;
        head->prev = NULL;
        delete a;
        sz--;
    }

    void insert_at_tail(T value)
    {
        node<T> *new_node = create_new_node(value);
        if (sz == 0) {
            head = new_node;
            tail = new_node;
            sz++;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        sz++;
    }

    void remove_from_tail()
    {
        if (sz == 0) {
            cout << "Deque is empty\n";
            return;
        }
        if (sz == 1) {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<T> *a = tail;
        tail = a->prev;
        tail->next = NULL;
        delete a;
        sz--;
    }

    void push_back(T value)
    {
        if (rev == 1) {
            insert_at_head(value);
            return;
        }
        insert_at_tail(value);
    }

    void pop_back()
    {
        if (rev == 1) {
            remove_from_head();
            return;
        }
        remove_from_tail();
    }

    void push_front(T value)
    {
        if (rev == 1) {
            insert_at_tail(value);
            return;
        }
        insert_at_head(value);
    }

    void pop_front()
    {
        if (rev == 1) {
            remove_from_tail();
            return;
        }
        remove_from_head();
    }

    T front()
    {
        if (rev == 1) {
            return tail->data;
        }
        return head->data;
    }

    T back()
    {
        if (rev == 1) {
            return head->data;
        }
        return tail->data;
    }

    void reverse_deque()
    {
        if (rev == 0) {
            rev = 1;
            return;
        }
        rev = 0;
    }
};

int main()
{
    Deque<int> dq;
    dq.push_back(12);
    dq.push_back(29);
    dq.push_back(34);
    cout << "Front: " << dq.front() << " Back: " << dq.back() << "\n";
    dq.pop_back();
    dq.push_front(10);
    dq.push_front(5);
    dq.reverse_deque();
    cout << "Front: " << dq.front() << " Back: " << dq.back() << "\n";
    dq.push_back(45);
    cout << "Front: " << dq.front() << " Back: " << dq.back() << "\n";

    return 0;
}