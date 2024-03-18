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

	vector<int> v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num, l, u;
		cin >> num;
		l = lower_bound(v.begin(), v.end(), num) - v.begin();
		u = upper_bound(v.begin(), v.end(), num) - v.begin();
		cout << u - l << " ";
	}
}