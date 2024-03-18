#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int m, x;
    string cmd;
    set<int> s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "remove") {
            cin >> x;
            s.erase(x);
        }
        else if (cmd == "check") {
            cin >> x;
            if(s.find(x) != s.end()) {
                cout << "1\n";
            }
            else
                cout << "0\n";

        }
        else if (cmd == "toggle") {
            cin >> x;
            if(s.find(x) != s.end()) {
                s.erase(x);
            }
            else
                s.insert(x);
        }
        else if (cmd == "all") {
            for (int i = 1; i < 21; i++) {
                s.insert(i);
            }
        }
        else if (cmd == "empty") {
            s.clear();
        }
    }
}