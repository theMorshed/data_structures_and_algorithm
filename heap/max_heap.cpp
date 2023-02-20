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
};

vector<int> heap_sort(vector<int> a)
{
    MaxHeap h;
    h.build_from_array(a);
    vector<int> ans;
    for(int i = 0; i < a.size(); i++) {
        ans.push_back(h.extractMax());
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    MaxHeap heap;
    heap.Insert(4);
    heap.Insert(7);
    heap.Insert(9);
    heap.Insert(1);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(30);
    cout<<"Max element = "<<heap.getMax()<<"\n";
    heap.print_heap();

    cout<<"Max element = "<<heap.extractMax()<<"\n";
    cout<<"Max element = "<<heap.extractMax()<<"\n";

    MaxHeap h;
    vector<int> a = {1, 2, 3, 4, 10, 9, 8, 7};
    h.build_from_array(a);
    cout << h.extractMax() << "\n";
    cout << h.getMax() << "\n";

    vector<int>sorted_a = heap_sort(a);
    for(int i=0;i<sorted_a.size();i++)
    {
        cout<<sorted_a[i]<<" ";
    }
    cout<<"\n";

    return 0;
}