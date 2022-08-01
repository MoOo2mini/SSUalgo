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

	cin >> m >> n;
	if (m == 1)
		m++;
	for (int i = m; i <= n; i++)
	{
		if (check_prime(i))
			cout << i << "\n";
	}
	return (0);
}