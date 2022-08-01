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
	int n, num;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 1)
			continue;
		if (check_prime(num))
			count++;
	}
	cout << count;
	return (0);
}