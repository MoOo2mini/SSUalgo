#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

long long dp[1000001][4] = { {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}, };
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 4; j <= n; j++) {
			dp[j][1] = (dp[j - 1][2] + dp[j - 1][3]) % 1000000009;
			dp[j][2] = (dp[j - 2][1] + dp[j - 2][3]) % 1000000009;
			dp[j][3] = (dp[j - 3][1] + dp[j - 3][2]) % 1000000009;
		}
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
	}

}