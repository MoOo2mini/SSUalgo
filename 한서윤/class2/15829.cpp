#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long l, hash = 0;
    string s;
    cin >> l >> s;
    for (int i = 0; i < l; i++) {
        long long num = s[i] - 'a' + 1;
        for (int j = 0; j < i; j++) {
            num *= 31;
            num %= 1234567891;
        }
        hash += num;
        hash %= 1234567891;
    }
    cout << hash;
}