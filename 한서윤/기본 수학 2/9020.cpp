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
		int tc;
		cin >> tc;
		bool* check = new bool[tc + 2]{ 1,1, }; // �Ҽ� == false
		for (int i = 2; i <= tc; i++) { // �Ҽ� ã��
			if (!check[i])
				for (int j = i * 2; j <= tc; j += i) check[j] = true;
		}
		for (int i = tc / 2; i <= tc; i++) { // ���̰� ������ �����ؾ��ϴϱ� �߰����� �˻�
			if (!check[i]) {
				tc -= i;
				if (!check[tc]) {
					cout << tc << " " << i << '\n';
					break;
				}
				tc += i;
			}
		}
	}
}