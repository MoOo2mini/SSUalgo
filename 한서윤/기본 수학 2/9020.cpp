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
		bool* check = new bool[tc + 2]{ 1,1, }; // 소수 == false
		for (int i = 2; i <= tc; i++) { // 소수 찾기
			if (!check[i])
				for (int j = i * 2; j <= tc; j += i) check[j] = true;
		}
		for (int i = tc / 2; i <= tc; i++) { // 차이가 작은거 선택해야하니까 중간부터 검사
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