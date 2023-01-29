#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Stack {
public:
    int arr[MAX_SIZE];
    int size;

    Stack()
    {
        size = 0;
    }    

    // add an item in stack
    void push(int value)
    {
        if (size + 1 > MAX_SIZE) {
            cout << "Stack is full.\n";
            return;
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