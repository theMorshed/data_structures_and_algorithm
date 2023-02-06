#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> qnum;
    qnum.push(45);
    qnum.push(44);
    qnum.push(11);
    cout << "Is empty: " << qnum.empty() << "\n";
    cout << qnum.size() << "\n";
    cout << qnum.front() << "\n";
    qnum.pop();
    cout << qnum.front() << "\n";
    qnum.pop();
    cout << qnum.front() << "\n";
    qnum.pop();
    cout << "Is empty: " << qnum.empty() << "\n";

    queue<char> qchar;
    qchar.push('A');
    qchar.push('B');
    cout << qchar.front() << "\n";
    qchar.pop();
    cout << qchar.front() << "\n";

    return 0;
}