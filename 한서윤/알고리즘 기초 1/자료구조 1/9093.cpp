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
	int n;
	cin >> n;
	cin.get(); // getchar()¶û °°Àº°Å
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		for (int i = 0; i <= str.length(); i++) {
			s.push(str[i]);
			if (str[i] == ' ' || str[i] == '\0') {
				s.pop();
				while(s.size()) {
					cout << s.top();
					s.pop();
				}
				if (str[i] != '\0')cout << " ";
			}
		}
		cout << '\n';
	}
}