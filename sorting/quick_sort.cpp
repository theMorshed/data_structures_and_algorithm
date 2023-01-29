#include <bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int> a)
{
    if (a.size() <= 1)
        return a;

    // int pivot = a.size() / 2;
    // int pivot = a.size() - 1;
    int pivot = rand() % a.size();

    vector <int> b, c;
    for (int i = 0; i < a.size(); i++) {
        if (i == pivot)
            continue;
        if (a[i] <= a[pivot])
            b.push_back(a[i]);
        else
            c.push_back(a[i]);
    }

    vector<int> sorted_b = quick_sort(b);
    vector<int> sorted_c = quick_sort(c);
    vector<int> sorted_a;

    for (int i = 0; i < sorted_b.size(); i++)
        sorted_a.push_back(sorted_b[i]);

    sorted_a.push_back(a[pivot]);

    for (int i = 0; i < sorted_c.size(); i++)
        sorted_a.push_back(sorted_c[i]);

    return sorted_a;
}

int main()
{
    vector<int> arr = {4, 3, 2, 1, 6, 7, 8, 9, 4, 5};
    vector<int> sorted_arr = quick_sort(arr);
    for (int i = 0; i < sorted_arr.size(); i++)
        cout << sorted_arr[i] << " ";
    cout << "\n";

    return 0;
}
