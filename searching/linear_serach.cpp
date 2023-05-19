#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity O(n)
    Memory complexity O(n)
*/

int main()
{
    vector<int>a = {2, 4, 5, 7, 5, 3, 2};
    int target = 3;
    int size = a.size();

    for (int i = 0; i < size; i++) {
        if (a[i] == target) {
            cout << target << " Found at index - " << i << endl;
            break;
        }
    }

    return 0;
}
