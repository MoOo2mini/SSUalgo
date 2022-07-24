#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	char a[4];
	char b[4];
	char ans[4];

	cin >> a >> b;
	swap(a[0], a[2]);
	swap(b[0], b[2]);
	if (strcmp(a, b) > 0)
		cout << a;
	else
		cout << b;
	return (0);
}