#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001], num[100001];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[j * j] = 1;
			int m = dp[j * j] + dp[i - j * j];
			dp[i] = min(m, dp[i]);
		}
	}
	cout << dp[n];
}