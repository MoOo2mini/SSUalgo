#include <iostream>
using namespace std;
int arr[500000 + 1];
int dp[500000 + 1];

int trace(int idx, int height) {
    if (idx < 0) {
        return 0;
    }
    if (dp[idx] == 0) {
        return 0;
    }
    if (arr[dp[idx] - 1] >= height) {
        return dp[idx];
    } else {
        return trace(dp[idx] - 1, height);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) { // 이전 것보다 작은가?
            dp[i] = i;
        } else if (arr[i] > arr[i - 1]) { // 이전 것보다 큰가?
            dp[i] = trace(i - 1, arr[i]);
        } else { // 이전 것과 같은가?
            dp[i] = dp[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}