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
	int n, m, acnt = 0, bcnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		acnt++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		if (binary_search(v.begin(), v.end(), b))
			acnt--;
		else bcnt++;
	}
	cout << acnt + bcnt;
}