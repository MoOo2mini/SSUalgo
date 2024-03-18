#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	string str;
	cin >> n >> str;
	vector<int> num(n);
	stack<double> s;
	for (int i = 0; i < n; i++) cin >> num[i]; // 입력

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') // 피연산자일 때
			s.push(num[str[i] - 'A']);
		else { // 연산자일 때
			double x, y, z;
			y = s.top();
			s.pop();
			x = s.top();
			s.pop();
			switch (str[i]) {
			case '+' :
				z = x + y;
				break;
			case '-' :
				z = x - y;
				break;
			case '*' :
				z = x * y;
				break;
			case '/' :
				z = x / y;
				break;
			}
			s.push(z);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	s.pop();
}