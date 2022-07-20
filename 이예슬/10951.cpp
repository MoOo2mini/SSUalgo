#include <iostream>

using namespace std;

int main(void)
{
	int a, b;

	while (1)
	{
		cin >> a >> b;
		if (cin.eof())
			break;
		cout << a + b << "\n";
	}
	return (0);
}