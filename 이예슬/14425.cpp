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
		string s;
		map<string, bool> set;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			set[s] = true;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> s;
			if (set[s])
				count++;
		}
		cout << count;
		return (0);
	}