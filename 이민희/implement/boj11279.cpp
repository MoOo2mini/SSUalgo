#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    priority_queue<int, vector<int>, less<int> > q;
    int n; cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (q.empty()) {
                cout << 0 << '\n';
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(tmp);
        }
    }
}