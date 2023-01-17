#include <bits/stdc++.h>
using namespace std;

vector<int> bubble_sort(vector<int> arr);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // bubble sort algorithm
    /***********
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    *************/

    vector<int> sorted = bubble_sort(arr);

    for (int i = 0; i < n; i++) {
        cout << sorted[i] << " ";
    }
    cout << "\n";

    return 0;
}

// bubble sort function declaration without implement
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
