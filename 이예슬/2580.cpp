#include <iostream>
#include <cstdlib>

using namespace std;

int arr[9][9];

bool ispromising(int n, int m, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[n][i] == num)
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][m] == num)
			return false;
	}
	int a = n / 3 * 3;
	int b = m / 3 * 3;
	for (int i = a; i < a + 3; i++)
	{
		for (int j = b; j < b + 3; j++)
		{
			if (arr[i][j] == num)
				return false;
		}
	}
	return true;
}

void dfs(int n, int m, int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}
	if (arr[n][m] == 0)
	{
		for (int i = 1; i < 10; i++)
		{
			if (ispromising(n, m, i))
			{
				arr[n][m] = i;
				if (m == 8)
					dfs(n + 1, 0, cnt + 1);
				else
					dfs(n, m + 1, cnt + 1);
			}
			arr[n][m] = 0;
		}
	}
	else
	{
		if (m == 8)
			dfs(n + 1, 0, cnt + 1);
		else
			dfs(n, m + 1, cnt + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}
	dfs(0, 0, 0);
}