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
        dp[n] = {
            0,
        };

    for (int i = 0; i < n; i++) {  // 배열에 입력 값 저장.
        int tmp;
        cin >> tmp;
        input[i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        dp[i] = input[i];
        for (int j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                dp[i] = max(dp[i], dp[j] + input[i]);
            }
        }
    }

    int output = 0;
    for (int i = 0; i < n; i++) {
        output = max(output, dp[i]);
    }
    cout << output;
}