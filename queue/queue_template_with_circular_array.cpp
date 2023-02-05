#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
public:
    T *arr;
    int capacity;
    int l, r;
    int sz;

    Queue()
    {
        arr = new T[1];
        capacity = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if (l > r) {
            T *tmp = new T[capacity];
            int index = 0;
            for (int i = l; i < capacity; i++) {
                tmp[index] = arr[i];
                index++;
            }

            for (int i = 0; i <= r; i++) {
                tmp[index] = arr[i];
                index++;
            }

            swap(tmp, arr);
            l = 0;
            r = capacity - 1;
            delete []tmp;
        }
    }

    void increase_size()
    {
        remove_circular();
        T *tmp = new T[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            tmp[i] = arr[i];
        }
        swap(arr, tmp);
        capacity = capacity * 2;
        delete []tmp;
    }

    void enqueue(T value)
    {
        if (sz == capacity) {
            increase_size();
        }
        r++;
        if (r == capacity) {
            r = 0;
        }
        arr[r] = value;
        sz++;
    }

    void dequeue()
    {
        if (sz == 0) {
            cout << "Queue is empty\n";
            return;
        }
        l++;
        if (l == capacity) {
            l = 0;
        }
        sz--;
    }

    T front()
    {
        if (sz == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[l];
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(10);
    q.enqueue(12);

    cout<< "Q size : "<< q.size() <<"\n";
    cout<< q.front() <<"\n";
    q.dequeue();
    cout<< q.front() << "\n";
    q.dequeue();
    cout<< q.front() << "\n";
    q.dequeue();

    cout<< "Q size : "<< q.size() << "\n";

    Queue<char> qch;
    qch.enqueue('A');
    qch.enqueue('B');
    qch.enqueue('C');
    cout << "Q size: " << qch.size() << "\n";
    cout << qch.front() << "\n";
    qch.dequeue();
    cout << qch.front() << "\n";
    qch.dequeue();
    cout << qch.front() << "\n";
    qch.dequeue();
    cout << "Q size: " << qch.size() << "\n";

    return 0;
}