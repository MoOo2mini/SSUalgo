#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001], num[100001];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	dp[0] = num[0];
	for (int i = 1; i < n; i++) dp[i] = max(num[i], dp[i - 1] + num[i]);
	int m = num[0];
	for (int i = 1; i < n; i++) m = max(m, dp[i]);
	cout << m;
}