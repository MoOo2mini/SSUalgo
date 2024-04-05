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
	for (int i = 2; i * i <= n; i++) { // ���������� ���� ����
		if (!check[i]) {
			for (int j = i * 2; j <= n; j += i) // �ռ��� true��
				check[j] = true;
		}
	}
	for (int i = m; i <= n; i++)
		if (!check[i]) cout << i << '\n';

}



/* �ð��ʰ����� �˾ƺ� ��� �����佺�׳׽��� ü�� ���� . . .

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
			if (i % j == 0) break; // �Ҽ� ����
			if (j == i - 1) cout << i << '\n';
		}
	}
}
*/