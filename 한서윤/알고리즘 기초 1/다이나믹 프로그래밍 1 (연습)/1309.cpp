#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

long long dp[1000001];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	dp[1] = 3, dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] = ((dp[i - 1] * 2) % 9901 + dp[i - 2]) % 9901;
	}
	cout << dp[n];
}