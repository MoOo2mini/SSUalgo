#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, d, e, num;

	cin >> a >> b >> c >> d >> e;
	num = (a * a + b * b + c * c + d * d + e * e) % 10;
	cout << num;
	return (0);
}