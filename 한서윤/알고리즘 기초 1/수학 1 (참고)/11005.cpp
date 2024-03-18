#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, b;
	vector<char> v;
	cin >> n >> b;
	while (n) {
		int num = n % b;
		if (num >= 10) v.push_back(num - 10 + 'A');
		else v.push_back(num + '0');
		n /= b;
	}
	while (!v.empty() && v.back() == '0') v.pop_back();
	if (v.empty()) v.push_back('0');
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i];
}