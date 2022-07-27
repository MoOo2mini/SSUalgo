#include <iostream>

using namespace std;

int main(void)
{
	int t, k, n;
	int ans;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k >> n;
		int arr[k + 1][n];
		ans = 0;
		for (int j = 0; j < n; j++)
		{
			arr[0][j] = j + 1;
		}
		for (int j = 1; j <= k; j++)	//Ãþ¼ö
		{
			for (int l = 0; l < n; l++)	//È£¼ö
			{
				if (l == 0)
					arr[j][0] = arr[j - 1][0];
				else
					arr[j][l] = arr[j][l - 1] + arr[j - 1][l];
			}
		}
		cout << arr[k][n - 1] << "\n";
	}
	return (0);
}