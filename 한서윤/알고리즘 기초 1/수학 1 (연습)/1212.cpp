#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> change(string s);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v;
	string s;
	cin >> s;
	v = change(s);
	for (int i = 0; i < v.size(); i++) cout << v[i];
}

vector<int> change(string s) {
	vector<int> v;
	while (!s.empty()) {
		int l = s.length() - 1;
		int num = s[l] - '0';
		for (int i = 0; i < 3; i++) {
			v.push_back(num % 2);
			num /= 2;
		}
		s.pop_back();
	}
	while (!v.empty() && v.back() == 0) v.pop_back();
	if (v.empty()) v.push_back(0);
	reverse(v.begin(), v.end());
	return v;
}