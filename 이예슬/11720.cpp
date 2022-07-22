#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	int sum = 0;
	string input;

	cin >> n >> input;
	for (int i = 0; i < n; i++)
	{
		sum += input[i] - '0';
	}
	cout << sum;
	return (0);
}