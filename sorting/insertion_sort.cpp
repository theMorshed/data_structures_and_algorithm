#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    // input vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // insertion sort code
    for (int i = 1; i < n; i++) {
        int item = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > item) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = item;
    }

    // print the vector after sort
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}