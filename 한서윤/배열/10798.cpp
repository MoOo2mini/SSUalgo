#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<string> v;
    vector<int> l;

    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        l.push_back(str.length());
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (l[j] > i) cout << v[j][i];
        }
    }
}