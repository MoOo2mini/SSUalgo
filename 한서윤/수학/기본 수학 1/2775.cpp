#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k, n, f[15][15], cnt;
		cin >> k >> n;
		for (int j = 1; j <= n; j++) // 0Ãþ
			f[0][j] = j;
		int j = 1, l = 1;
 		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= n; l++) {
				cnt = 0;
				for (int m = 1; m <= l; m++)
					cnt += f[j - 1][m];
				f[j][l] = cnt;
			}
		}
		cout << cnt << endl;
	}
}