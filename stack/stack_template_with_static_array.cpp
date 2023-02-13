#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;

template <class T>
class Stack {
public:
    T arr[MAX_SIZE];
    int size;

    Stack()
    {
        size = 0;
    }

    // add an item in stack
    void push(T value)
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
        size--;
    }

    // get top item
    T top()
    {
        if (size == 0) {
            cout << "Stack is empty.\n";
            T a;
            return a;
        }
        return arr[size - 1];
    }
};

int main()
{
    Stack<int> st;
    st.push(4);
    cout << st.top() << "\n";
    st.push(6);
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    cout << st.top() << "\n";

    Stack<char> stc;
    stc.push('A');
    cout << stc.top() << "\n";
    stc.push('B');
    cout << stc.top() << "\n";
    stc.pop();
    stc.pop();
    cout << stc.top() << "\n";

    return 0;
}
