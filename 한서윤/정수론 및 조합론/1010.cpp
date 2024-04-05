#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t, dp[31][31] = { 0, };
	dp[1][0] = 1, dp[1][1] = 1;
	for (int i = 2; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		cout << dp[m][n] << '\n';
	}
}