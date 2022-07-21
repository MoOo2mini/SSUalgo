#include <iostream>

using namespace std;

int d(int n)
{
	int ret;

	ret = n;
	while (n > 0)
	{
		ret += n % 10;
		n = n / 10;
	}
	return (ret);
}

int main(void)
{
	int self_num[10000] = {0};
	int num;

	for (int i = 1; i <= 10000; i++)
	{
		num = d(i);
		if (num <=  10000)
			self_num[num - 1] = 1;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (self_num[i] == 0)
			cout << i + 1 << "\n";
	}
	return (0);
}