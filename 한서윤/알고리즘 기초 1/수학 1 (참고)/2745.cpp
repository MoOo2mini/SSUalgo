#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string n;
	int b, result = 0;
	vector<char> v;
	cin >> n >> b;
	int l = n.length();
	for (int i = 0; i < l; i++) {
		int num, idx = n.length() - 1, x = 1;
		for (int j = 1; j <= i; j++) x *= b;
		if (n[idx] >= 'A' && n[idx] <= 'Z') num = n[idx] - 'A' + 10;
		else num = n[idx] - '0';
		result += num * x;
		n.pop_back();
	}
	cout << result;
}