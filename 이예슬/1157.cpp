#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	int alpha[26] = {0};
	int max_index;
	int max = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
			alpha[s[i] - 97]++;
		else
			alpha[s[i] - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (max <= alpha[i])
		{
			max = alpha[i];
			max_index = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (max == alpha[i])
		{
			if (max_index != i)
				cout << "?";
			else
				cout << (char)(max_index + 65);
			break;
		}
	}
	return (0);
}