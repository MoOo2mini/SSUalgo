#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    // 배열 초기화.
    int input[n] =
        {
            0,
        },
        up[n] =
            {
                0,
            },
        down[n] = {
            0,
        };

    for (int i = 0; i < n; i++) {  // 배열에 입력 값 저장.
        int tmp;
        cin >> tmp;
        input[i] = tmp;
    }

    for (int i = 0; i < n; i++) {  // 오름차순 확인
        up[i] = 1;
        for (int j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {  // 내림차순 확인
        down[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (input[j] < input[i]) {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }

    int output = 1;
    for (int i = 0; i < n; i++) {
        output = max(output, up[i] + down[i] - 1);
    }
    cout << output;
}