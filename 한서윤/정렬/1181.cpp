#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool compare(string s1, string s2);


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && !v[i].compare(v[i + 1]))
			continue;
		cout << v[i] << '\n';
	}
}

bool compare(string s1, string s2) {
	if (s1.length() == s2.length()) {
		int check = s1.compare(s2);
		if (check < 0) return true;
		else return false;
	}
	else {
		return s1.length() < s2.length();
	}
}