#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    int arr[n][3];
    int dp[n][3];

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
    }

    int min = 3000;
    for (int i = 0; i < 3; i++) {
        if (dp[n - 1][i] < min) {
            min = dp[n - 1][i];
        }
    }
    cout << min;
}