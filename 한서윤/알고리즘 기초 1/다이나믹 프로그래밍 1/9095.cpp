#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int dp[12] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}