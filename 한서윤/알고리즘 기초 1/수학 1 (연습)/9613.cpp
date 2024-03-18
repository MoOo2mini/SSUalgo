#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int gcd(int a, int b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, sum = 0;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) cin >> v[j]; // ют╥б
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum += gcd(v[j], v[k]);
			}
		}
		cout << sum << '\n';
	}
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}