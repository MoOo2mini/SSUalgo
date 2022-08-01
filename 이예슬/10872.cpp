#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}

int main(void)
{
	int n;

	cin >> n;
	cout << factorial(n);
	return (0);
}