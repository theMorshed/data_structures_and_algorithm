#include <bits/stdc++.h>
using namespace std;

template <class T>
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

template <class T>
class DoublyLinkedList {
public:
    node<T> *head;
    int size;

    DoublyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // create new node and return his pointer
    node<T> *create_new_node (T value)
    {
        node<T> *new_node = new node<T>(value);
        return new_node;
    }

    // insert new node in head
    void insert_at_head(T value)
    {
        node<T> *new_node = create_new_node(value);
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
        node<T> *a = head;
        node<T> *b = head->next;
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

template <class T>
class Stack {
public:
    DoublyLinkedList<T> list;

    Stack() {}   

    void push(T value)
    {
        list.insert_at_head(value);
    }

    void pop()
    {
        list.remove_head();
    }

    T top()
    {
        if (list.get_size() == 0) {
            cout << "Stack is empty\n";
            T a;
            return a;
        }
        return list.head->data;
    }

    int get_size()
    {
        return list.get_size();
    }
};

int main()
{
    Stack<int> st;
    st.push(10);
    cout << st.top() << "\n";
    st.push(4);
    cout << st.top() << "\n";
    st.push(14);
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    cout << st.get_size() << "\n";
    st.pop();
    cout << st.top() << "\n";

    Stack<char> stc;
    stc.push('a');
    cout << stc.top() << "\n";
    stc.push('b');
    cout << stc.top() << "\n";
    stc.push('c');
    cout << stc.top() << "\n";
    stc.pop();
    stc.pop();
    stc.pop();
    cout << stc.top() << "\n";

    return 0;
}
