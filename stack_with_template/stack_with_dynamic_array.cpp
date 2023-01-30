#include <bits/stdc++.h>
using namespace std;

template<class T>
class Stack {
public:
    T *arr;
    int capacity;
    int stack_size;

    Stack()
    {
        arr = new T[1];
        capacity = 1;
        stack_size = 0;
    }

    void increase_size()
    {
        T *tmp;
        tmp = new T[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            tmp[i] = arr[i];
        }
        swap(arr, tmp);
        capacity *= 2;
        delete []tmp;
    }

    void push(T value)
    {
        if (stack_size + 1 > capacity) {
            increase_size();            
        }
        stack_size++;
        arr[stack_size - 1] = value;
    }

    void pop()
    {
        if (stack_size == 0) {
            cout << "Stack is empty.\n";
            return;
        }
        stack_size--;
    }

    T top()
    {
        if (stack_size == 0) {
            cout << "Stack is empty.\n";
            T a;
            return a;
        }
        return arr[stack_size - 1];
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
    st.pop();
    cout << st.top() << "\n";

    Stack<double> std;
    std.push(4.5);
    std.push(4.6);
    std.push(5.67);
    cout << std.top() << "\n";
    std.pop();
    cout << std.top() << "\n";
    std.pop();
    cout << std.top() << "\n";
    std.pop();
    cout << std.top() << "\n";

    Stack<char> stc;
    stc.push('A');
    stc.push('B');
    cout << stc.top() << "\n";
    stc.pop();
    cout << stc.top() << "\n";
    stc.pop();
    cout << stc.top() << "\n";

    return 0;
}
