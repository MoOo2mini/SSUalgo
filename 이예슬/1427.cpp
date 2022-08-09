#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
	string n;

	cin >> n;
	sort(n.begin(), n.end(), greater<>());
	cout << n;
	return (0);
}