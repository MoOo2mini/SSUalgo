#include <iostream>

using namespace std;

void recur(int n, int cur, int end)
{
	int a[3] = {0};
	int empty;
	if (n == 1)
	{
		cout << cur << " " << end << "\n";
		return;
	}
	a[cur - 1] = 1;
	a[end - 1] = 1;
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == 0)
		{
			empty = i + 1;
			break;
		}
	}
	recur(n - 1, cur, empty);
	cout << cur << " " << end << "\n";
	recur(n - 1, empty, end);
	return;
}

int main(void)
{
	int n;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		count = count * 2 + 1;
	}
	cout << count << "\n";
	recur(n, 1, 3);
	return (0);
}