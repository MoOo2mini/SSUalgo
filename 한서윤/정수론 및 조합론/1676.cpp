#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt2 = 0, cnt5 = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num % 2 == 0) {
			cnt2++;
			num /= 2;
		}
		while (num % 5 == 0) {
			cnt5++;
			num /= 5;
		}
	}
	if (cnt2 > cnt5) cnt = cnt5;
	else cnt = cnt2;
	cout << cnt;
}