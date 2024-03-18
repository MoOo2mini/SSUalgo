#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int dp[1001][1001] = { 0, }; // 스택 오버플로나서 여기로 이동 . . .
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	dp[1][1] = 1, dp[1][0] = 1;
	for (int i = 2; i <= n; i++) { // 재귀는 시간초과라서 이렇게 해야하나보다...
		for (int j = 0; j <= k; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k] % 10007;
}