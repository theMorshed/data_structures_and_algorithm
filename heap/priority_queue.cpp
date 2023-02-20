#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> nodes;

    MaxHeap() {}

    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] > nodes[(index - 1) / 2]) {
            swap(nodes[index], nodes[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void Insert(int value)
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
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < nodes.size() && nodes[largest] < nodes[left]) {
                largest = left;
            }
            if (right < nodes.size() && nodes[largest] < nodes[right]) {
                largest = right;
            }
            if (largest == index) {
                break;
            }
            swap(nodes[index], nodes[largest]);
            index = largest;
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

    int getMax()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return nodes[0];
    }

    int extractMax()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        int max_num = nodes[0];
        Delete(0);
        return max_num;
    }

    void build_from_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_leaf_node = n / 2 - 1;
        for (int i = last_leaf_node; i >= 0; i--) {
            down_heapify(i);
        }
    }

    int size()
    {
        return nodes.size();
    }
};


class PriorityQueue {
public:
    MaxHeap h;

    PriorityQueue() {}

    void push(int value)
    {
        h.Insert(value);
    }

    void pop()
    {
        h.Delete(0);
    }

    int top()
    {
        return h.getMax();
    }

    int size()
    {
        return h.size();
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(8);
    pq.push(7);

    while(pq.size() != 0) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    return 0;
}