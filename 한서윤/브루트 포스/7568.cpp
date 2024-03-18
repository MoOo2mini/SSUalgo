#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, w[50], h[50], rank[50] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i] >> h[i];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] > w[j] && h[i] > h[j]) rank[j]++;
			else if (w[i] < w[j] && h[i] < h[j]) rank[i]++;
		}
	}
	for (int i = 0; i < n; i++) cout << rank[i] + 1 << " ";
}