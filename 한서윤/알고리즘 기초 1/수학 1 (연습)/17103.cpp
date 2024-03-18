#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int num[1000001] = { 0, };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 3; i <= 1000000; i += 2) { // ¼Ò¼ö
		int j = 2;
		if (num[i] == 0 && i * j <= 1000000) {
			while (i * j <= 1000000) {
				num[i * j] = 1;
				j++;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		int n, cnt = 0;
		cin >> n;
		for (int j = 3; j <= n / 2; j+=2)
			if (num[j] == 0 && num[n - j] == 0) cnt++;
		if (n == 4) cnt++;
		cout << cnt << '\n';
	}
}