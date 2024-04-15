#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    multiset<pair<int, int>> m;  // multiset에 pair 형식으로 저장.

    string input;
    cin >> input;
    int check = 1, length = input.length();

    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - i - 1]) check = 0;
    }

    cout << check;
}