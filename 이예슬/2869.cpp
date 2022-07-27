#include <iostream>

using namespace std;

int main(void)
{
	int a, b, v;
	int height = 0;
	int day = 0;

	cin >> a >> b >> v;
	if ((v - a) % (a - b) != 0)
		day++;
	day += (v - a) / (a - b) + 1;
	cout << day;
	return (0);
}