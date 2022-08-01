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
	int n;

	cin >> n;
	if (n == 1)
		return (0);
	while (!check_prime(n))
	{
		for (int i = 2; i < n; i++)
		{
			if (check_prime(i))
			{
				if (n % i == 0)
				{
					cout << i << "\n";
					n /= i;
					break;
				}
			}
		}
	}
	cout << n;
	return (0);
}