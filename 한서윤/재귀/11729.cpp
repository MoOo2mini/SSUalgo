#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void hanoi(int n, int start, int via, int end);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 1;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cnt = cnt * 2 + 1;
	}
	cout << cnt << '\n';
	hanoi(n, 1, 2, 3);
	
}

void hanoi(int n, int start, int via, int end) {
	if (n == 1) {
		cout << start << " " <<  end << '\n';
	}
	else {
		hanoi(n - 1, start, end, via); // 마지막 빼고 이동
		cout << start << " " <<  end << '\n'; // 가장 큰 것 이동
		hanoi(n - 1, via, start, end); // 위에 쌓기
	}
}