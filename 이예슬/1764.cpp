#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int count = 0;
	map<string, int> list;
	map<string, int> ans;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		list[s]++;
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (list[s] != 0)
		{
			count++;
			ans[s];
		}
	}
	cout << count << "\n";
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << it->first << "\n";
	return (0);
}