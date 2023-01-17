#include <bits/stdc++.h>
using namespace std;

vector<int> bubble_sort(vector<int> arr)
{
    vector<int> sorted = arr;
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = 0; j < sorted.size() - 1 - i; j++) {
            if (sorted[j] > sorted[j + 1]) {
                swap(sorted[j], sorted[j + 1]);
            }
        }
    }
    return sorted;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sorted_arr = bubble_sort(arr);

    for (int i = 0; i < n; i++) {
        cout << sorted_arr[i] << " ";
    }
    cout << "\n";

    return 0;
}