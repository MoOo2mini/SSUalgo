#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, m = 0;
	cin >> n;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> dp[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
}