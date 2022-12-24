#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int len;
	set<string> list;

	cin >> s;
	len = s.length();
	while (len)
	{
		for (int i = 0; i + len - 1 < s.length(); i++)
			list.insert(s.substr(i, len));
		len--;
	}
	cout << list.size();
	return (0);
}