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
	int num = 0;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') { // ������
			i++;
			num += s.size();
		}
		else { // �踷���
			s.push(str[i]);
			if (s.top() == ')') {
				s.pop();
				s.pop();
				num++;
			}
		}
	}
	cout << num;
}


/* �ð��ʰ��� ����
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
	int num = 0;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') { // ������
			i++;
			s.push('L');
		}
		else { // �踷���
			int l = 0;
			s.push(str[i]);
			if (s.top() == ')') {
				while (s.top() != '(') {
					if (s.top() == 'L') l++;
					s.pop();
				}
				s.pop();
				num += l + 1;
				for (int i = 0; i < l; i++) s.push('L');
			}
		}
	}
	cout << num;
}
*/