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
	while (getline(cin, str)) {
		int num[4] = { 0, };
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') num[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') num[1]++;
			else if (str[i] >= '0' && str[i] <= '9') num[2]++;
			else if (str[i] == ' ') num[3]++;
		}
		for (int i = 0; i < 4; i++) cout << num[i] << " ";
		cout << '\n';
	}
}