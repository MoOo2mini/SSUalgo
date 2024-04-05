#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	set<string> s;
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (s.find(str) != s.end()) cnt++;
	}
	cout << cnt;
}