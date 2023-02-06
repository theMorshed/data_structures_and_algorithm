#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> qstr;
    qstr.push("1");
    for (int i = 1; i <= n; i++) {
        cout << "Binary Representation of: " << i << " is: " << qstr.front() << "\n";
        string temp = qstr.front();
        qstr.pop();
        qstr.push(temp + "0");
        qstr.push(temp + "1");
    }

    return 0;
}