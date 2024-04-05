#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt;
	cin >> n;
	cnt = n;
	int* num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++) {
		if (num[i] == 1) {
			cnt--;
			continue;
		}
		for (int j = 2; j < num[i]; j++) {
			if (num[i] % j == 0) {
				cnt--;
				break;
			}
		}
	}
	cout << cnt;
}