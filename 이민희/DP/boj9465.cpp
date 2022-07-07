#include <iostream>
using namespace std;

int main()
{
	int T;
	int n;

	cin >> T;
	cin >> n;

	int dp[2][n+1];
	int a[2][n+1];

	// input
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	dp[0][0] = dp[0][1] = 0;
	dp[0][1] = a[0][1];
	dp[1][1] = a[1][1];

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + a[0][i];
		dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + a[1][i];
	}

	return max(dp[0][n], dp[1][n]);
}

//참고 링크 : https://m.blog.naver.com/occidere/220786307316