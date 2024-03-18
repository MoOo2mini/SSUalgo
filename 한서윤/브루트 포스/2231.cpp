#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int sum = i;
		int idx = i;
		while (idx) {
			sum += idx % 10;
			idx /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}