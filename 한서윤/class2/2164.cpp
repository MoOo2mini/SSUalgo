#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    queue<int> q;
    cin >> n;

    for (int i = 1; i < n + 1; i++) q.push(i);

    while (q.size() != 1) {
        q.pop();
        int a = q.front();
        q.pop();
        q.push(a);
    }
    cout << q.front();
}