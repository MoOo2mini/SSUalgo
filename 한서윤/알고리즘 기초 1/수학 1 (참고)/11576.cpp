#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v;
	int a, b, m, ten = 0;
	cin >> a >> b >> m;
	for (int i = m; i > 0; i--) { // A������ 10������ ��ȯ
		int x = 1, num;
		cin >> num;
		for (int j = 0; j < i - 1; j++) x *= a;
		ten += num * x;
	}
	while (ten) { // 10������ B������ ��ȯ
		v.push_back(ten % b);
		ten /= b;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}