#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool compare(pair<int, string> v1, pair<int, string> v2);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back(pair<int, string>(age, name));
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}

bool compare(pair<int, string> v1, pair<int, string> v2) {
	return v1.first < v2.first;
}