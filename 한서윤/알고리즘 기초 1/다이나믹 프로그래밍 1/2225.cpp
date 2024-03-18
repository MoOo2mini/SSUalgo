#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[201][201], num[201]; // [n][k] k개로 n만들기
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	for (int j = 1; j <= k; j++) {
		dp[1][j] = j;
	}
	dp[0][1] = 1, dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= k; j++) {
			dp[i][j] += ((dp[i][j - 1] % 1000000000) + (dp[i - 1][j] % 1000000000) % 1000000000);
		}
	}
	cout << dp[n][k] % 1000000000;
}