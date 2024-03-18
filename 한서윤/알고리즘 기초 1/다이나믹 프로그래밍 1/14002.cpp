#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001], num[1001], idx[1001];
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v;
	int n, cnt = 0, c = 0, last = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					idx[i] = j;
				}
			}
		}
		if (cnt < dp[i]) last = i;
		cnt = max(cnt, dp[i]);
	}
	for (int i = 0; i <= cnt; i++) {
		v.push_back(num[last]);
		last = idx[last];
	}
	reverse(v.begin(), v.end());
	cout << cnt + 1 << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}