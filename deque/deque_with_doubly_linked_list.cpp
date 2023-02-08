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

class Deque {
public:
    node *head;
    node *tail;
    int sz;
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }    

    node *create_new_node(int value)
    {
        node *new_node = new node(value);
        return new_node;
    }

    // complexity O(1)
    void insert_at_head(int value)
    {
        node *new_node = create_new_node(value);
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

    // complexity O(1)
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
        node *a = head;
        head = head->next;
        head->prev = NULL;
        delete a;
        sz--;
    }

    // complexity O(1)
    void insert_at_tail(int value)
    {
        node *new_node = create_new_node(value);
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

    // complexity O(1)
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
        node *a = tail;
        tail = a->prev;
        tail->next = NULL;
        delete a;
        sz--;
    }

    void push_back(int value)
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

    void push_front(int value)
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

    // complexity O(1)
    int front()
    {
        if (rev == 1) {
            return tail->data;
        }
        return head->data;
    }

    // complexity O(1)
    int back()
    {
        if (rev == 1) {
            return head->data;
        }
        return tail->data;
    }

    // complexity O(1)
    void reverse_deque()
    {
        if (rev == 0) {
            rev = 1;
            return;
        }
        rev = 0;
    }

    // complexity O(n)
    int max()
    {
        node *current = head;
        int max_num = current->data;
        while (current != NULL) {
            if (current->data > max_num) {
                max_num = current->data;
            }
            current = current->next;
        }
        return max_num;
    }

    // complexity O(n)
    int min()
    {
        node *current = head;
        int min_num = current->data;
        while (current != NULL) {
            if (current->data < min_num) {
                min_num = current->data;
            }
            current = current->next;
        }
        return min_num;
    }
};

int main()
{
    Deque dq;
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
    cout << "Maximum Number is: " << dq.max() << "\n";
    cout << "Minimum Number is: " << dq.min() << "\n";

    return 0;
}