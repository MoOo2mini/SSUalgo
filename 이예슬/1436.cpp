#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	int i = 665;
	int count = 0;
	string s;

	cin >> n;
	while (count != n)
	{
		i++;
		s = to_string(i);
		if (s.find("666") != string::npos)
			count++;
	}
	cout << i;
	return (0);
}