#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int card[], int num, int n)
{
	int start = 0;
	int end = n;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (card[mid] == num)
			return (1);
		else if (card[mid] < num)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
	}
	return (0);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	int card[n];
	for (int i = 0; i < n; i++)
		cin >> card[i];
	cin >> m;
	int check[m];
	for (int i = 0; i < m; i++)
		cin >> check[i];
	sort(card, card + n);	//정렬 후 이분 탐색
	for (int i = 0; i < m; i++)
		check[i] = binarySearch(card, check[i], n);
	for (int i = 0; i < m; i++)
		cout << check[i] << " ";
	return (0);
}