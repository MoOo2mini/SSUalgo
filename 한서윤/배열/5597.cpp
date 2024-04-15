#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> num(31, 0);

    for (int i = 0; i < 28; i++) {
        int input;
        cin >> input;
        num[input] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (!num[i]) cout << i << '\n';
    }
}