#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> stack;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (!input.compare("push")) {
			int x;
			cin >> x;
			stack.push_back(x);
		}
		else if (!input.compare("pop")) {
			if (stack.size() == 0)
				cout << -1 << '\n';
			else {
				cout << stack.back() << '\n';
				stack.pop_back();
			}
		}
		else if (!input.compare("size")) {
			cout << stack.size() << '\n';
		}
		else if (!input.compare("empty")) {
			if (stack.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (!input.compare("top")) {
			if (stack.size() == 0)
				cout << -1 << '\n';
			else
				cout << stack.back() << '\n';
		}
	}
	
}