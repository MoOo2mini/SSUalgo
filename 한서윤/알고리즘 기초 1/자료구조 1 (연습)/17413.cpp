#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	stack<char> s;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') { // 태그일 때
			while (str[i] != '>') {
				cout << str[i];
				i++;
			}
			cout << '>';
		}
		else { // 단어일 때
			s.push(str[i]);
			if (s.top() == ' ' || str[i + 1] == '<' || i == str.length() - 1) {
				if (s.top() == ' ' || s.top() == '<') s.pop();
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				if (str[i] == ' ')cout << ' ';
			}
		}

	}
}