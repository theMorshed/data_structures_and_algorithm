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

    // selection sort code
    for (int i = 0; i < n - 1; i++) {
        int index_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[index_min]) {
                index_min = j;
            }
        }

        if (index_min != i) {
            swap(arr[index_min], arr[i]);
        }
    }

    // print the vector after sort
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}