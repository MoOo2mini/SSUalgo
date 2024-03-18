#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 13;
			if (str[i] > 'Z') str[i] = str[i] - 'Z' + 'A' - 1;
			cout << str[i];
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] <= 'm') str[i] += 13;
			else  str[i] = str[i] - 'm' + 'a' - 1;
			cout << str[i];
		}
		else cout << str[i];
	}
}