#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
int GCD(int a, int b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		v.push_back(r);
	}
	for (int i = 1; i < v.size(); i++) {
		int gcd = GCD(v[0], v[i]);
		cout << v[0] / gcd << "/" << v[i] / gcd << '\n';
	}
	
}

int GCD (int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else return GCD(a % b, b);
}