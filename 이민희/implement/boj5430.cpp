#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

deque<string> parsing(string s) {
    string tmp = "";
    // vector<string> v;
    deque<string> v;
    if (s.length() == 2) {
        return v;
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ',' || s[i] == ']') {
            v.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, countR, countD;
    string flag = "f";
    cin >> T;
    string p, sarr;
    bool error = false;
    while (T--) {
        countR = 0; countD = 0;
        flag = "f";
        error = false;
        cin >> p;
        cin >> n;
        cin >> sarr;
        deque<string> v = parsing(sarr);

        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                if (flag == "f") {
                    flag = "b";
                } else {
                    flag = "f";
                }
                countR++;
            } else if (p[i] == 'D') {
                if (v.empty()) {
                    error = true;
                    break;
                }

                if (flag == "f") {
                    v.erase(v.begin());
                } else if (flag == "b") {
                    auto iter = v.end();
                    iter--;
                    v.erase(iter);
                }
            }
        }
        if (!error) {
            int start = 0;
            int end = v.size();
            if (countR % 2 == 1) {
                cout << '[';
                for (int i = v.size() - 1; i >= 0; i--) {
                    cout << v[i];
                    if (i != 0) cout << ",";
                }
                cout << "]\n";
            } else {
                cout << '[';
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i != v.size() - 1) cout << ",";
                }
                cout << "]\n";
            }
        } else {
            cout << "error" << '\n';
        }
    }
}