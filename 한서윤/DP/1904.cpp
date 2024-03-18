#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    vector<int> t(1000100);
    cin >> n;
    t[1] = 1, t[2] = 2;
    for (int i = 3; i <= n; i++) {
        t[i] = (t[i - 2] % 15746 + t[i - 1] % 15746) % 15746;
    }
    cout << t[n];
}