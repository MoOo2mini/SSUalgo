#include <iostream>
using namespace std;

int solve(int num) {
    int dp[num + 1];

    for (int i = 1; i <= num; i++) {
        if (i == 1) {
            dp[i] = 1;
        } else if (i == 2) {
            dp[i] = 2;
        } else if (i == 3) {
            dp[i] = 4;
        } else if (i - 3 >= 0) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }

    return dp[num];
}

int main() {
    int n;
    cin >> n;

    int tmp[n];
    for (int i = 0; i < n; i++) {
        cin >> tmp[i];
    }
    for (int i = 0; i < n; i++) {
        cout << solve(tmp[i]) << '\n';
    }
}