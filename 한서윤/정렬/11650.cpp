#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool compare(pair<int, int> v1, pair<int, int> v2);


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(pair<int, int> (x, y));
	}
	vector<pair<int, int>> ::iterator iter;
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
}

bool compare(pair<int, int> v1, pair<int, int> v2) {
	if (v1.first == v2.first) {
		return v1.second < v2.second;
	}
	else {
		return v1.first < v2.first;
	}
}