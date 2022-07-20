#include <iostream>

using namespace std;

int main(void)
{
	int n, max, min, input;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (i == 0)
		{
			max = input;
			min = input;
		}
		if (max < input)
			max = input;
		if (min > input)
			min = input;
	}
	cout << min << " " << max;
	return (0);
}