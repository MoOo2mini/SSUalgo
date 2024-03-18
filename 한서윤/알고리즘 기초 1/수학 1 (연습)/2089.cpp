#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> change(int num);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v;
	int num;
	cin >> num;
	v = change(num);
	for (int i = 0; i < v.size(); i++) cout << v[i];
}

vector<int> change(int num) {
	vector<int> v;
	while(num) {
		if (num % (-2) == 0) {
			v.push_back(0);
			num /= -2;
		}
		else {
			v.push_back(1);
			num = (num - 1) / -2;
		}
	}
	while (!v.empty() && v.back() == 0) v.pop_back();
	if (v.empty()) v.push_back(0);
	reverse(v.begin(), v.end());
	return v;
}