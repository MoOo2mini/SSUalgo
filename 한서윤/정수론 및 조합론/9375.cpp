#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		map<string, int> m;
		int n, result = 1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			string name, item;
			cin >> name >> item;
			auto temp = m.insert({ item, 1 });
			if(!temp.second) // 중복일 때
				m.find(item)->second++;
		}
		
		map<string, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++)
			result *= iter->second + 1;
		cout << result - 1 << '\n'; // 알몸인 경우 빼고
	}
}