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

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (((dp[i - 3] % 1000000009) + (dp[i - 2] % 1000000009) % 1000000009) + (dp[i - 1] % 1000000009)) % 1000000009;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}