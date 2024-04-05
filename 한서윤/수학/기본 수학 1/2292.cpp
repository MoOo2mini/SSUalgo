#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int num, cnt = 0, p = 0;
	cin >> num;
	if (num == 1) {
		cout << 1;
		return 0;
	}
	while (num > 1) {
		num -= p;
		p += 6;
		cnt++;
	}
	cout << cnt;
}