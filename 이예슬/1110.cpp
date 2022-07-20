#include <iostream>

using namespace std;

int main(void)
{
	int n, num;
	int count = 0;

	cin >> n;
	num = n;
	while (1)
	{
		num = (num / 10 + num % 10) % 10 + (num % 10) * 10;
		count++;
		if (num == n)
			break;
	}
	cout << count;
}