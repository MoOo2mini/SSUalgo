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

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > s) v[i] -= s;
		else v[i] = s - v[i];
	}
	int g = v[0];
	for (int i = 1; i < n; i++)
		g = gcd(g, v[i]);
	cout << g;
}

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}