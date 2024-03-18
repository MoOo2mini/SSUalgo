#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

long long dp[101][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	long long cnt = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000) % 1000000000;
	}
	for (int i = 0; i <= 9; i++) cnt += dp[n][i] % 1000000000;
	cout << cnt % 1000000000 << '\n';
}