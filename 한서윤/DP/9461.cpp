#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<long long> v(100);
    v[0] = v[1] = v[2] = 1;
    v[3] = v[4] = 2;
    for (int i = 5; i < 100; i++) {
        v[i] = v[i - 5] + v[i - 1];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << v[n - 1] << '\n';
    }
}