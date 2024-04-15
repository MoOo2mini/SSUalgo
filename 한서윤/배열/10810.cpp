#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for (int x = 0; x < m; x++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int y = i - 1; y < j; y++) {
            v[y] = k;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}