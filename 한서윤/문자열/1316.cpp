#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0, idx;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			idx = str.find(str[j], j + 1);
			if (idx != -1) { // 중복 있음
				if (idx - j != 1) {
					cnt--;
					break;
				}
			}
		}
		cnt++;
	}
	cout << cnt;
}