#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) { // �ð� ���� ������ �ݺ������� �� ǯ . . .
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int a, b, c, cnt = 1;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1;
		return 0;
	}
	cnt = a / (c - b) + 1;
	cout << cnt;
}