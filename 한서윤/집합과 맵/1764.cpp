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

	vector<string> v, re;
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		v.push_back(name);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (binary_search(v.begin(), v.end(), name)) {
			cnt++;
			re.push_back(name);
		}
	}
	sort(re.begin(), re.end());
	cout << cnt << '\n';
	for (int i = 0; i < re.size(); i++)
		cout << re[i] << '\n';
}