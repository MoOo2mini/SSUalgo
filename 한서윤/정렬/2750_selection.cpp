#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, num[1000], minidx;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < n - 1; i++) {
		minidx = i;
		for (int j = i; j < n; j++) {
			if (num[j] < num[minidx]) minidx = j;
		}
		swap(num[i], num[minidx]);
	}
	for (int i = 0; i < n; i++) cout << num[i] << '\n';
}