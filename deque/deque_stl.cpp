#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(23);
    dq.push_back(20);
    dq.push_back(10);
    dq.push_front(2);
    dq.push_front(1);
    dq.pop_back();
    dq.pop_front();
    cout << dq.front() << " " << dq.back() << "\n";

    return 0;
}