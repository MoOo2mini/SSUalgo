#include <iostream>
using namespace std;

int main() {
	int N, result = 0;
	int temp, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int div = 2; div * div <= temp; div++) {
            // 최적화. 자신의 제곱근까지만 확인하면 된다.
			if (temp%div == 0)
				cnt++;
		}
        if (!cnt && temp != 1) result++;
		cnt = 0;
	}
	cout << result << '\n';
}