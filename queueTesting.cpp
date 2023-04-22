#include "queueUsingArray.cpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    // cin >> n;
    queueWithArray<int> q1(5);
    q1.push(0);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.pop();
    cout << q1.size() << endl;
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    cout << q1.front() << endl;
    return 0;
}
