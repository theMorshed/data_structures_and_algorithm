#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Queue {
public:
    int arr[MAX_SIZE];
    int l, r;

    Queue() 
    {
        l = 0;
        r = -1;
    }

    void enqueue(int value)
    {
        if (r + 1 >= MAX_SIZE) {
            cout << "Queue is full\n";
            return;
        }
        r++;
        arr[r] = value;
    }

    void dequeue()
    {
        if (l > r) {
            cout << "Queue is empty\n";
            return;
        }
        l++;
    }

    int front()
    {
        if (l > r) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[l];
    }

    int size()
    {
        return r - l + 1;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout << "Q size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << "Q size: " << q.size() << "\n";

    return 0;
}