#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int check_cnt(string* input);
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, m, cnt, min = 32;
	string input[50], cutInput[8];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> input[i];
	for (int i = 0; i <= n - 8; i++) { // 세로 시작 index
		for (int j = 0; j <= m - 8; j++) { // 가로 자르기
			for (int k = i; k < i + 8; k++) // 세로 자르기
				cutInput[k - i] = input[k].substr(j, 8);
			cnt = check_cnt(cutInput);
			if (cnt < min) min = cnt;
		}
	}
	cout << min;
}

int check_cnt(string* input) {
	int Wcnt = 0, Bcnt = 0, cnt;
	string check[2] = { "WBWBWBWB", "BWBWBWBW" };
	
	for (int i = 0; i < 8; i++) { // W로 시작
		for (int j = 0; j < 8; j++) {
			if (check[i % 2][j] != input[i][j]) Wcnt++;
		}
	}

	for (int i = 0; i < 8; i++) { // B로 시작
		for (int j = 0; j < 8; j++) {
			if (check[1 - i % 2][j] != input[i][j]) Bcnt++;
		}
	}
	Wcnt > Bcnt ? cnt = Bcnt : cnt = Wcnt;
	return cnt;
}