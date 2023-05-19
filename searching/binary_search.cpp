#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity O(logN)
    Memory complexity O(n)
*/

int main()
{
    vector<int>a = {2, 4, 5, 7, 8, 10, 19};
    int target = 10;
    int low = 0, high = a.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == target) {
            cout << target << " found at index " << mid << endl;
            break;
        }

        if (a[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (low > high) {
        cout << "Object not found" << endl;
    }

    return 0;
}
