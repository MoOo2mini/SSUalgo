#include <iostream>

using namespace std;

int digit_count(int num)
{
	int digit = 0;

	while (num > 0)
	{
		digit++;
		num = num / 10;
	}
	return (digit);
}

int main(void)
{
	int n, d, digit;
	int count = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		digit = digit_count(i);
		if (digit < 3)
			count++;
		else
		{
			d = i / 100 - (i / 10 - (i / 100) * 10);
			if ( d == (i / 10 - (i / 100) * 10 - i % 10))
				count++;
		}
	}
	cout << count;
	return (0);
}