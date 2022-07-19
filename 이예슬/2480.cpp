#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, max;

	cin >> a >> b >> c;
	if (a == b && b == c)
		cout << 10000 + a * 1000;
	else if (a == b || a == c)
		cout << 1000 + a * 100;
	else if (b == c)
		cout << 1000 + b * 100;
	else
	{
		max = a;
		if (b > max)
			max = b;
		if (c > max)
			max = c;
		cout << max * 100;
	}
	return (0);
}