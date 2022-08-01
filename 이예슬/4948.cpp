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
	int count = 0;

	while (1)
	{
		cin >> n;
		count = 0;
		if (n == 0)
			break;
		for (int i = n + 1; i <= n * 2; i++)
		{
			if (i == 0)
				continue;
			if (check_prime(i))
				count++;
		}
		cout << count << "\n";
	}
	return (0);
}