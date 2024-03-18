#include <bits/stdc++.h>
using namespace std;
int min(int, int);
int min(int, int, int);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> v(3);
    int n, m, x, y, z;
    cin >> n;
    cin >> v[0] >> v[1] >> v[2];
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x = min(v[1] + a, v[2] + a);
        y = min(v[0] + b, v[2] + b);
        z = min(v[0] + c, v[1] + c);
        v[0] = x, v[1] = y, v[2] = z;
    }
    m = min(v[0], v[1], v[2]);
    cout << m;
}

int min (int a, int b) {
    if (a >= b) return b;
    else
        return a;
}

int min(int a, int b, int c) {
    int m;
    if (a >= b) m = b;
    else m = a;
    if (m >= c) return c;
    else return m;
}