#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int T, N;

int main()
{
	cin >> T;
	while (T--) {
		vector<int> v;
		map<string, int> m;
		cin >> N;
		while (N--) {
			string clothes, kind;
			cin >> clothes >> kind;
			m[kind]++;
		}

		int res = 1;
		map<string, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++)
			res *= (iter->second + 1);
		cout << res - 1 << "\n";
	}
}