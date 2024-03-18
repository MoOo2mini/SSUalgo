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
	vector<int> n(26);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int idx = str[i] - 'a';
		n[idx]++;
	}
	for (int i = 0; i < 26; i++)
		cout << n[i] << " ";
}