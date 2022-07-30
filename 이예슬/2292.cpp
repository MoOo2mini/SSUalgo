#include <iostream>

using namespace std;

int main(void)
{
	int input;
	int i = 1;
	int n = 1;

	cin >> input;
	while (1)
	{
		if (n >= input)
		{
			cout << i;
			return (0);
		}
		n += 6 * i;
		i++;
	}
	return (0);
}