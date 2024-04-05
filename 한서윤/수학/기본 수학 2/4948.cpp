#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	while (1) {
		int testcase, cnt = 0;
		cin >> testcase;
		bool* check = new bool[testcase * 2 + 2]{ 1, 1, }; // �Ҽ� == false
		if (testcase == 0) break;

		for (int i = 2; i * i <= testcase * 2; i++) { // ���������� ���� ����
			if (!check[i]) {
				for (int j = i * 2; j <= testcase * 2; j += i) // �ռ��� true��
					check[j] = true; 
			}
		}
		for (int i = testcase + 1; i <= testcase * 2; i++)
			if (!check[i]) cnt++;
		cout << cnt << '\n';
	}
}