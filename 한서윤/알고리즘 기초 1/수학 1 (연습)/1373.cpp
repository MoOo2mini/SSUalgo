#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string s;
	vector<int> v;
	int num;
	cin >> s;
	for (int i = 0; !s.empty(); i++) {
		int n = 0, j = 1;
		while(!s.empty() && j <= 4) {
			int l = s.length() - 1;
			n += (s[l] - '0') * j;
			s.pop_back();
			j *= 2;
		}
		v.push_back(n);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i];
}