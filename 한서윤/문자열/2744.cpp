#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string str, output;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        char c;
        if (str[i] >= 'a' && str[i] <= 'z') {
            c = str[i] - 'a' + 'A';
            output.push_back(c);
        } else {
            c = str[i] - 'A' + 'a';
            output.push_back(c);
        }
    }
    cout << output;
}