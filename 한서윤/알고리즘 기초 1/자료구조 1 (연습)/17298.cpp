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
	cin >> n;
	stack<pair<int, int>> s;
	vector<int> input(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++) { // �Է�
		int num;
		cin >> num;
		input[i] = num;
	}

	s.push({ input[0], 0 });
	for (int i = 1; i < n; i++) {
		while (!s.empty() && s.top().first < input[i]) { // ū ���� ������ pop
			result[s.top().second] = input[i];
			s.pop();
		}
		s.push({ input[i], i }); // �ƴϸ� ���ÿ� push
	}
	while (!s.empty()) {
		result[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << result[i];
		if (i != n - 1) cout << " ";
	}
}