#include <bits/stdc++.h>
using namespace std;

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n = 세로, m = 가로
    int n, m;
    
    cin >> n >> m;
        
    if (n == 1) cout << 1;
    else if (n == 2) cout << min(4, (m + 1) / 2);
    else if (m < 7) cout << min(4, m);
    else cout << m - 2;
}