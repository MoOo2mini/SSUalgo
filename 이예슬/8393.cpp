#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int sum = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << sum;
	return (0);
}