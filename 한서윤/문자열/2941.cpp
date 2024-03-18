#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case 'c':
			if (str[i + 1] == '=' || str[i + 1] == '-') i++;
			break;

		case 'd':
			if (str[i + 1] == 'z' && str[i + 2] == '=') i += 2;
			else if (str[i + 1] == '-') i++;
			break;

		case 'l':
		case 'n':
			if (str[i + 1] == 'j') i++;
			break;

		case 's':
		case 'z':
			if (str[i + 1] == '=') i++;
			break;
		}
		cnt++;
	}
	cout << cnt;
}