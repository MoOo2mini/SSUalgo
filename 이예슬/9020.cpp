#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	int a, b;
	int prime[10000];

	cin >> n;
	fill_n(prime, 10000, 1);
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i - 1] == 0)
			continue;
		for (int j = 2 * i; j <= 10000; j+=i)
			prime[j - 1] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 2; j <= num / 2; j++)
		{
			if (prime[j - 1] == 1 && prime[num - j - 1] == 1)
			{
				a = j;
				b = num - j;
			}
		}
		cout << a << " " << b << "\n";
	}
}