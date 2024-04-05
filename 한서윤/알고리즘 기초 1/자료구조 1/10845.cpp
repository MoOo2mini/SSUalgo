#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (!input.compare("push")) {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (!input.compare("pop")) {
			if (!q.size())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!input.compare("size")) {
			cout << q.size() << '\n';
		}
		else if (!input.compare("empty")) {
			if (!q.size()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (!input.compare("front")) {
			if (!q.size())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (!input.compare("back")) {
			if (!q.size())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

}