#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, a, b = 0;
	vector<int> v(1000001, 0);
	for (int i = 3; i < 1000000; i += 2) { // 소수 찾기
		if (v[i] != -1) {
			for (int j = 2; i * j <= 1000000; j++)
				v[i * j] = -1;
		}
	}
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 3; i <= n / 2; i += 2) {
			if (v[i] != -1 && v[n - i] != -1) {
				a = i;
				b = n - i;
				break;
			}
		}
		if (b == 0) cout << "Goldbach's conjecture is wrong." << '\n';
		else cout << n << " = " << a << " + " << b << '\n';
	}
}