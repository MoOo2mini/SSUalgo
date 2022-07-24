#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	int n;
	int alphabet[26] = {0};
	int count = 0;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		memset(alphabet, 0, sizeof(alphabet));
		for (int j = 0; j < s.length(); j++)
		{
			if (alphabet[s[j] - 'a'] == 0)
				alphabet[s[j] - 'a'] = 1;
			else
			{
				if (s[j - 1] != s[j])
					break;
			}
			if (j == s.length() - 1)
				count++;
		}
	}
	cout << count;
	return (0);
}