#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
string check(string str);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; i++) {
		string str;
		getline(cin, str);
		cout << check(str) << '\n';
	}
}

string check(string str) {
		stack<char> s;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') s.push(str[i]);
			else {
				if (s.size()) s.pop();
				else return "NO";
			}
		}
		if (!s.size()) return "YES";
		else return "NO";
}