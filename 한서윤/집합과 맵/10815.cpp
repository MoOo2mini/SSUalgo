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

	set<int> s;
	int n, m;
	vector<int> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (s.find(num) != s.end())
			cout << "1" << " ";
		else
			cout << "0" << " ";
	}
}

/* ㅇㅎ 집합으로 하는거였네
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, m;
	vector<int> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		v2.push_back(num);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < m; i++) {
		if (binary_search(v1.begin(), v1.end(), v2[i]))
			cout << "1" << " ";
		else
			cout << "0" << " ";
	}
}
*/