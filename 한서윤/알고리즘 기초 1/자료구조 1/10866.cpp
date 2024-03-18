#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	deque<int> dq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		int x;
		cin >> command;
		if (!command.compare("push_front")) {
			cin >> x;
			dq.push_front(x);
		}
		else if (!command.compare("push_back")) {
			cin >> x;
			dq.push_back(x);
		}
		else if (!command.compare("pop_front")) {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (!command.compare("pop_back")) {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (!command.compare("size")) cout << dq.size() << '\n';
		else if (!command.compare("empty")) {
			if (dq.empty())
				cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (!command.compare("front")) {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (!command.compare("back")) {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}