#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int max = -1, x, y;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n;
            if (max < n) {
                max = n;
                x = i;
                y = j;
            }
        }
    }
    cout << max << '\n' << x + 1 << " " << y + 1;
}