#include <iostream>
using namespace std;

int solve(int* arr, int n) {
    int dp[n];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = arr[i];
        } else if (i == 1) {
            dp[i] = arr[0] + arr[1];
        } else if (i == 2) {
            dp[i] = max(arr[0] + arr[2], arr[1] + arr[2]);
        } else if (i - 3 >= 0) {   
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
        }
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, n);
    return 0;
}