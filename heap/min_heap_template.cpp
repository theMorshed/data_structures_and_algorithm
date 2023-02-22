#include <bits/stdc++.h>
using namespace std;

template <class T>
class MinHeap {
public:
    vector<T> nodes;

    MinHeap() {}

    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] < nodes[(index - 1) / 2]) {
            swap(nodes[index], nodes[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void Insert(T value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void print_heap()
    {
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }

    void down_heapify(int index)
    {
        while(1) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < nodes.size() && nodes[smallest] > nodes[left]) {
                smallest = left;
            }
            if (right < nodes.size() && nodes[smallest] > nodes[right]) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }
            swap(nodes[index], nodes[smallest]);
            index = smallest;
        }
    }

    void Delete(int index)
    {
        if (index >= nodes.size()) {
            return;
        }
        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }

    T getMin()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            T a;
            return a;
        }
        return nodes[0];
    }

    T extractMin()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            T a;
            return a;
        }
        T min_num = nodes[0];
        Delete(0);
        return min_num;
    }
};

int main()
{
    MinHeap<char> heap;
    heap.Insert('c');
    heap.Insert('r');
    heap.Insert('h');
    heap.Insert('d');
    heap.Insert('x');
    cout<<"Min element = "<<heap.getMin()<<"\n";
    heap.print_heap();

    cout<<"Min element = "<<heap.extractMin()<<"\n";
    cout<<"Min element = "<<heap.extractMin()<<"\n";

    return 0;
}