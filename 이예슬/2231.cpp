#include <iostream>

using namespace std;

int main(void)
{
	int num;
	int n;
	int sum = 0;

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		sum = i;
		num = i;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return (0);
		}
	}
	cout << "0";
	return (0);
}