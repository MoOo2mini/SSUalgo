#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return (0);
}