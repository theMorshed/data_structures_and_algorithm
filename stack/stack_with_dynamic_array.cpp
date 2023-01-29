#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int *arr;
    int size;
    int capacity;

    Stack()
    {
        capacity = 1;
        arr = new int[capacity];
        size = 0;
    }    

    // increase array size dynamically
    void increase_size()
    {
        int *tmp;
        tmp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            tmp[i] = arr[i];
        }
        swap(arr, tmp);
        delete []tmp;
        capacity *= 2;
    }

    // add an item in stack
    void push(int value)
    {
        if (size + 1 > capacity) {
            increase_size();
        }
        size++;
        arr[size - 1] = value;
    }

    // remove an item from stack
    void pop()
    {
        if (size == 0) {
            cout << "Stack is empty.\n";
            return;
        }
        arr[size - 1] = 0;
        size--;
    }

    // get top item
    int top()
    {
        if (size == 0) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[size - 1];
    }
};

int main()
{
    Stack st;
    st.push(4);
    cout << st.top() << "\n";
    st.push(6);
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    cout << st.top() << "\n";

    return 0;
}