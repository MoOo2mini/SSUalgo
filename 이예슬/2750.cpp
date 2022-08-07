#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int minindex;

	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//selection sort
	for (int i = 0; i < n; i++)
	{
		minindex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minindex])
				minindex = j;
		}
			swap(arr[i], arr[minindex]);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
	return (0);
}