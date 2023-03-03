#include <set>
#include <iostream>
using namespace std;
int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        string s; int tmp;
        multiset<int> q;
        for (int i = 0; i < n; i++) {
            cin >> s >> tmp;
            if (s == "I") {
                q.insert(tmp);
            } else if (s == "D") {
                if (q.empty()) continue;
                
                if (tmp == 1) {
                    auto iter = q.end();
                    iter--;
                    q.erase(iter);
                } else if (tmp == -1) {
                    q.erase(q.begin());
                }
            }
        }
        if (q.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            auto iter = q.end();
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
    }
}