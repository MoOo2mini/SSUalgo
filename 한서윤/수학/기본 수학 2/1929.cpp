#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> m >> n;
	bool* check = new bool[n + 1]{ 1, 1, };
	for (int i = 2; i * i <= n; i++) { // 제곱근으로 범위 생각
		if (!check[i]) {
			for (int j = i * 2; j <= n; j += i) // 합성수 true로
				check[j] = true;
		}
	}
	for (int i = m; i <= n; i++)
		if (!check[i]) cout << i << '\n';

}



/* 시간초과나서 알아본 결과 에라토스테네스의 체로 수정 . . .

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> m >> n;
	if (n == 1) return 0;
	for (int i = m; i <= n; i++) {
		if (i == 2) cout << i << '\n';
		for (int j = 1; j < i; j++) {
			if (j == 1) continue;
			if (i % j == 0) break; // 소수 ㄴㄴ
			if (j == i - 1) cout << i << '\n';
		}
	}
}
*/