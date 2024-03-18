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
	stack<pair<char, int>> s;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
		else {
			int rank;
			switch (str[i]) { // 연산자 우선순위 배정
			case '+':
				rank = 1;
				break;
			case '-':
				rank = 1;
				break;
			case '*':
				rank = 2;
				break;
			case '/':
				rank = 2;
				break;
			}
			if (str[i] == '(') s.push({ str[i], 0 });
			else if (str[i] == ')') {
				while (s.top().first != '(') {
					cout << s.top().first;
					s.pop();
				}
				s.pop();
			}
			else if (s.empty() || s.top().second < rank) s.push({ str[i], rank });
			else {
				while (!s.empty() && s.top().second >= rank) {
					cout << s.top().first;
					s.pop();
				}
				s.push({ str[i], rank });
			}
		}
	}
	while (!s.empty()) {
		cout << s.top().first;
		s.pop();
	}
}