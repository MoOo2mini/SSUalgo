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

	vector<string> v;
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j <= s.length() - i; j++) {
			string sub = s.substr(j, i);
			v.push_back(sub);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size();
}