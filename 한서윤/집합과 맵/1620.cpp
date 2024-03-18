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

	map<string, int> map;
	int n, m, cnt = 0;
	cin >> n >> m;
	string* name = new string[n + 1]; // value로 key 찾기 어려워서 이름 배열 따로
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		map.insert({ str, i });
		name[i] = str;
	}
	for (int i = 0; i < m; i++) {
		string str;
		int num;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') { // 숫자일 때
			num = stoi(str);
			cout << name[num] << '\n';
		}
		else {
			cout << map.find(str)->second << '\n';

		}
	}
}