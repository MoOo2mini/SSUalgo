#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		cout << n << " * "  << i + 1 << " = " << n * (i + 1);
		if ( i != 8)
			cout << endl;
	}
	return (0);
}