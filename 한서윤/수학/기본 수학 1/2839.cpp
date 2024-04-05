#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0;
	cin >> n;
	cnt += n / 5;
	n %= 5;
	while (1) {
		if (n % 3 == 0) {
			cnt += n / 3;
			break;
		}
		else {
			n += 5;
			cnt--;
		}
		if (cnt == -1)break;
	}
	cout << cnt;
}