#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, count1, count2;
	int ans = 64;

	cin >> n >> m;
	char arr[n][m];
	char board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				board[i][j] = 'W';
			else
				board[i][j] = 'B';
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			count1 = 0;
			count2 = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (arr[i + k][j + l] == board[k][l])
						count1++;
					else
						count2++;
				}
			}
			if (ans > min(count1, count2))
				ans = min(count1, count2);
		}
	}
	cout << ans;
	return (0);
}