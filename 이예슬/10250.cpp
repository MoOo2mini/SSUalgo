#include <iostream>

using namespace std;

int main(void)
{
	int t, h, w, n;
	int room;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;
		room = (n % h) * 100 + (n / h + 1);
		if (n % h == 0)
			room += h * 100 - 1;
		cout << room << "\n";
	}
	return (0);
}