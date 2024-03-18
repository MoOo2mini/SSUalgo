#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1001] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	int n;
	cin >> n;
	cout << dp[n];
}