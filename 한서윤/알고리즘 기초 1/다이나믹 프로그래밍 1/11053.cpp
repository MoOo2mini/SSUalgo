#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001], num[1001];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		cnt = max(cnt, dp[i]);
	}
	cout << cnt + 1;
}