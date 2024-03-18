#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (!input.compare("push")) {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (!input.compare("pop")) {
			if (s.size() == 0)
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (!input.compare("size")) {
			cout << s.size() << '\n';
		}
		else if (!input.compare("empty")) {
			if (s.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (!input.compare("top")) {
			if (s.size() == 0)
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}
	
}