#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, i;
	cin >> n;
	if (n == 1) return 0;

	for (i = 1; i < n; i++) {
		if (i == 1) continue;
		while (n % i == 0) {
			cout << i << endl;
			n /= i;
		}
	}
	if (i == n) cout << n;
}