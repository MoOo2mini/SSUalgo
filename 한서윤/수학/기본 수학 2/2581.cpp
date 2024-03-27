#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int m, n, cnt, num, sum = 0, min = 0;
	cin >> m >> n;
	cnt = n - m + 1;
	for (int i = 0; i < cnt; i++) {
		num = m + i;
		if (num == 1) continue;
		else if (num == 2) {
			sum += num;
			min = num;
		}
		for (int j = 2; j < num; j++) {
			if (num % j == 0) break;
			if (j == num - 1) {
				sum += num;
				if (min == 0) min = num;
			}
		}
	}
	if (sum == 0) {
		cout << -1;
		return 0;
	}
	cout << sum << endl;
	cout << min;
}