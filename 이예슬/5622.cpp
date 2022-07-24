#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	int time = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= 'O')
			time += ((s[i] - 'A') / 3) + 3;
		else if (s[i] >= 'P' && s[i] <= 'S')
			time += 8;
		else if (s[i] >= 'T' && s[i] <= 'V')
			time += 9;
		else
			time += 10;
	}
	cout << time;
	return (0);
}