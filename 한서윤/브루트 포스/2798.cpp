#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, m, card[100], sum, result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum == m) {
					result = m;
					cout << m;
					return 0;
				}
				else if (sum <= m && result < sum) result = sum;
			}
		}
	}
	cout << result;
}