#include <iostream>

using namespace std;

int main(void)
{
	int n, num;
	int sum = 0;
	int max = 0;
	int ans[3];

	cin >> n >> num;
	int card[n];
	for (int i = 0; i < n; i++)
		cin >> card[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= num && sum > max)
					max = sum;
			}
		}
	}
	cout << max;
}