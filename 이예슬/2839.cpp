#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int ans = -1;

	cin >> n;
	for (int i = 0; 1; i++)
	{
		if (n < 5 * i)
			break;
		if ((n - i * 5) % 3 == 0)
			ans = i + (n - i * 5) / 3;
	}
	cout << ans;
	return (0);
}