#include <iostream>

using namespace std;

int check_prime(int num)
{
	int i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(void)
{
	int m, n;
	int sum = 0;
	int min = -1;

	cin >> m >> n;
	for (int i = n; i >= m; i--)
	{
		if (i == 1)
			continue;
		if (check_prime(i))
		{
			min = i;
			sum += i;
		}
	}
	if (sum == 0)
		cout << "-1";
	else
		cout << sum << "\n" << min;
	return (0);
}