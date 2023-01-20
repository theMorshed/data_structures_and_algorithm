#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node (int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class Stack {
    Node *head;
    Node *top;
    int size = 0;

public:
    Stack() {
        head = NULL;
        top = NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        size++;
        if (head == NULL) {
            head = newNode;
            top = newNode;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }

    void get_top()
    {
        cout << top->data;
    }

    void pop()
    {
        Node *delNode = top;
        if (top == NULL) {
            head = top = NULL;
            return;
        }
        top = delNode->prev;
        top->next = NULL;
        delete delNode;
        size--;
    }

    bool empty()
    {
        if (size == 0) return true;
        return false;
    }

    int get_size()
    {
        return size;
    }
};

int main()
{
    Stack num_stack;
    num_stack.push(12);
    num_stack.push(15);
    num_stack.push(19);
    num_stack.push(30);
    num_stack.pop();
    cout << num_stack.get_size() << "\n";
    num_stack.get_top();

    return 0;
}
