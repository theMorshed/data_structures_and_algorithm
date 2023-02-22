#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> nodes;

    MinHeap() {}

    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] < nodes[(index - 1) / 2]) {
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

    int getMin()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return nodes[0];
    }

    int extractMin()
    {
        if (nodes.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        int min_num = nodes[0];
        Delete(0);
        return min_num;
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
};

vector<int> heap_sort(vector<int> a)
{
    MinHeap h;
    h.build_from_array(a);
    vector<int> ans;
    for(int i = 0; i < a.size(); i++) {
        ans.push_back(h.extractMin());
    }
    return ans;
}

int main()
{
    MinHeap heap;
    heap.Insert(4);
    heap.Insert(7);
    heap.Insert(9);
    heap.Insert(1);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(30);
    cout<<"Min element = "<<heap.getMin()<<"\n";
    heap.print_heap();

    cout<<"Min element = "<<heap.extractMin()<<"\n";
    cout<<"Min element = "<<heap.extractMin()<<"\n";

    MinHeap h;
    vector<int> a = {1, 2, 3, 4, 10, 9, 8, 7};
    h.build_from_array(a);
    cout << h.extractMin() << "\n";
    cout << h.getMin() << "\n";

    vector<int>sorted_a = heap_sort(a);
    for(int i=0;i<sorted_a.size();i++)
    {
        cout<<sorted_a[i]<<" ";
    }
    cout<<"\n";

    return 0;
}