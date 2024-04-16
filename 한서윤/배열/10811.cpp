#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= (b - a) / 2; j++) {
            swap(v[a + j - 1], v[b - j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}