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
	vector<int> v;
	int n, in = 1, check = 1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (!s.size() || s.top() < num) {
			for (; in <= num; in++) {
				s.push(in);
				v.push_back(1);
			}
		}	
		if (s.top() == num) {
			s.pop();
			v.push_back(0);
		}
		else check = 0;
	}
	if (check) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) cout << "+" << '\n';
			else cout << "-" << '\n';
		}
	}
	else cout << "NO";
}