#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v, sv;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sv = v;
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	for (int i = 0; i < n; i++) // ��ø �ݺ��� �ߴ��� �ð��ʰ����� �̺�Ž������ . . .
		cout << lower_bound(sv.begin(), sv.end(), v[i]) - sv.begin() << " ";
		// iterator ��ȯ�ϹǷ� ���� �ּ� ���� �ε��� ���� �� ����
}