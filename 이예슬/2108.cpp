#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	int avg, mid, most, range;
	int max = 0;
	int max_count = 0;
	double sum = 0;

	cin >> n;
	int arr[n];
	int count[8001] = {0};
	for (int i = 0; i < n; i++)	//배열 입력
		cin >> arr[i];
	sort(arr, arr + n);	//배열 정렬
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		count[arr[i] + 4000]++;
	}
	for (int i = 0; i < 8001; i++)
		if (count[i] > max)
			max = count[i];
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == max)
		{
			most = i - 4000;
			max_count++;
		}
		if (max_count == 2)
			break;
	}
	avg = round(sum / n);
	mid = arr[n / 2];
	range = arr[n - 1] - arr[0];
	cout << avg << "\n"
			 << mid << "\n"
			 << most << "\n"
			 << range;
	return (0);
}