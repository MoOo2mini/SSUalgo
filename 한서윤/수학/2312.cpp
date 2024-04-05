#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        bool arr[n + 1];           // n보다 작거나 같은 소수를 모두 찾는 배열.
        fill_n(arr, n + 1, true);  // true로 초기화.
        arr[0] = 0, arr[1] = 0;
        for (int j = 2; j * j <= n; j++) {
            if (arr[j] == 1) {                      // j가 소수이면
                for (int k = 2; k * j <= n; k++) {  // j의 합성수 제거
                    arr[k * j] = 0;
                }
            }
        }

        for (int j = 2; j <= n; j++) {
            if (arr[j]) {
                int count = 0;
                while (!(n % j)) {
                    n /= j;
                    count++;
                }
                if (count) cout << j << " " << count << '\n';
            }
        }
    }
}