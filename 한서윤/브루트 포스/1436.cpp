#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0, result = 665, tmp;
	cin >> n;
	while (result++) {
		tmp = result;
		while (tmp) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}
		if (cnt == n) break;
	}
	cout << result;
}