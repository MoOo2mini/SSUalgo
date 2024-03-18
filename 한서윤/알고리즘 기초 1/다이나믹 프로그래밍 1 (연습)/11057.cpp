#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

long long dp[1001][11];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
		dp[2][i] = 10 - i;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) sum += dp[n][i] % 10007;
	cout << sum % 10007;
}