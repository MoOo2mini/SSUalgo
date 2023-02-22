#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

int main() {
    cin >> s >> t;
    
    while (true) {
        if (t[t.length() - 1] == 'A') {
            t.pop_back();
        } else if (t[0] == 'B') {
            reverse(t.begin(), t.end());
            t.pop_back();
        } else {
            cout << 0;
            break;
        }
        cout << t << endl;

        if (t.length() == s.length()) {
            if (t == s) {
                cout << 1;
            } else {
                cout << 0;
            }
            break;
        }
    }
}