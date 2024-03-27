#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> v(30);

    for (int i = 0; i < 28; i++) {
        int input;
        cin >> input;
        v[input - 1] = 1;
    }

    int a, b, check = 0;
    for (int i = 0; i < 28; i++) {
        if (!v[i] && !check) {
            a = i + 1;
            check = 1;
        } else if (!v[i])
            b = i + 1;
    }

    if (a > b) swap(a, b);

    cout << a << '\n' << b;
}