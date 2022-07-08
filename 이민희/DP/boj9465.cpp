#include <iostream>
using namespace std;

int main()
{
	int result;
	int T;
	int n;

	cin >> T;

	for (int k = 0; k < T; k++)
	{
		//input
		cin >> n;

		int dp[2][n+1];
		int a[2][n+1];

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + a[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + a[1][i];
		}

		result = max(dp[0][n], dp[1][n]);

		cout << result << '\n';
	}

}

//참고 링크 : https://m.blog.naver.com/occidere/220786307316