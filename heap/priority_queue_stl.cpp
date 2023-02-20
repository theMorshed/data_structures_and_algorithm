#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(10);
    pq.push(4);
    pq.push(1);

    while (pq.size() != 0) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    return 0;
}