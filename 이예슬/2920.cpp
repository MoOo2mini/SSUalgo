#include <iostream>

using namespace std;

int main(void)
{
	int arr[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	if (arr[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != i + 1)
				break;
			if (i == 7)
			{
				cout << "ascending";
				return (0);
			}
		}
	}
	else if (arr[0] == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != 8 - i)
				break;
			if (i == 7)
			{
				cout << "descending";
				return (0);
			}
		}
	}
	cout << "mixed";
	return (0);
}