#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	stack<char> left; // cursor �������� �¿� ����
	stack<char> right;
	string str;
	int m;
	cin >> str >> m;
	for (int i = 0; i < str.length(); i++) left.push(str[i]); // ���ÿ� �ֱ�
	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;
		switch (command) {
		case 'L':
			if (left.size()) {
				right.push(left.top()); // ���ʿ��� ���������� �ѱ��
				left.pop();
			}
			break;
		case 'D':
			if (right.size()) {
				left.push(right.top()); // �����ʿ��� �������� �ѱ��
				right.pop();
			}
			break;
		case 'B':
			if (left.size()) left.pop();
			break;
		case 'P':
			char ins;
			cin >> ins;
			left.push(ins);
			break;
		}
	}
	while (left.size()) {
		right.push(left.top());
		left.pop();
	}
	while (right.size()) {
		cout << right.top();
		right.pop();
	}
}

/*
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	int m;
	cin >> str >> m;
	int cursor = str.length();
	for (int i = 0; i < m; i++) {
		char command;
		string ins;
		cin >> command;
		switch (command) {
		case 'L' :
			cursor--;
			if (cursor < 0) cursor = 0;
			break;
		case 'D' :
			cursor++;
			if (cursor > str.length()) cursor = str.length();
			break;
		case 'B' :
			if (cursor) {
				str.erase(cursor - 1, 1);
				cursor--;
			}
			break;
		case 'P' :
			cin >> ins;
			str.insert(cursor, ins);
			cursor++;
			break;
		}
	}
	cout << str;
}
*/