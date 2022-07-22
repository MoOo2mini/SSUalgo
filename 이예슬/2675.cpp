#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	int n, count;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> count >> s;
		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < count; k++)
			{
				cout << s[j];
			}
		}
		cout << "\n";
	}
	return (0);
}