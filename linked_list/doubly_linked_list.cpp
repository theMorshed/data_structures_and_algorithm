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

    void insert_at_any_index(int index, int value)
    {
        int idx = 0;
        node *current = head;

        // create new node by given value
        node *new_node = create_new_node(value);

        // check if index is 0 then add node into head and if index is absent display a msg
        if (index == 0) {
            insert_at_head(value);
            return;
        } else if (index > size) {
            cout << "Index does not exist\n";
            return;
        }

        // find exact position by loop
        while (idx != index - 1) {
            idx++;
            current = current->next;
        }
        size++;
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;
        new_node->next->prev = new_node;
    }

    // remove node by index
    void delete_by_index(int index)
    {
        if (index >= size) {
            cout << "Index doesn't exist\n";
            return;
        }
        node *current = head;
        int current_index = 0;
        while (current_index != index) {
            current = current->next;
            current_index++;
        }
        node *b = current->prev;
        node *c = current->next;
        if (b != NULL) {
            b->next = c;
        }
        if (c != NULL) {
            c->prev = b;
        }
        if (index == 0) {
            head = c;
        }
        size--;
        delete current;
    }

    // reverse the whole list
    void reverse_list()
    {
        if (head == NULL) {
            return;
        }
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        node *b = head;
        while (b != NULL) {
            swap(b->next, b->prev);
            b = b->prev;
        }
        head = current;
    }

    // print linked list
    void print_list()
    {
        node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // get list size
    int get_size()
    {
        return size;
    }
};

int main()
{
    DoublyLinkedList list;
    list.insert_at_head(40);
    list.insert_at_head(30);
    list.insert_at_head(10);
    list.print_list();
    cout << list.get_size() << "\n";
    list.insert_at_any_index(0, 5);
    list.insert_at_any_index(1, 50);
    list.insert_at_any_index(3, 100);
    list.print_list();
    cout << list.get_size() << "\n";
    list.delete_by_index(5);
    list.print_list();
    cout << list.get_size() << "\n";
    list.reverse_list();
    list.print_list();

    return 0;
}
