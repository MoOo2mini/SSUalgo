#include <iostream>
using namespace std;
int n;
int arr[16][2];
bool visited[16];
int dp[16];
int maxValue = 0;
void dfs(int day, int result) {
    if (day > n + 1) {
        return;
    }

    maxValue = max(result, maxValue);
    for (int i = day; i <= n; i++) {
        dfs(i + arr[i][0], result + arr[i][1]);
    }
}

void DP() {
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = max(maxValue, dp[i]);
        if (i + arr[i][0] <= n + 1) {
            dp[i + arr[i][0]] = max(dp[i + arr[i][0]], arr[i][1] + dp[i]);
        }
        maxValue = max(dp[i], maxValue);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i + 1][0] >> arr[i + 1][1];
    }
    /** 
     * dfs style
        dfs(1, 0);
        cout << maxValue;
    */

    DP();
    cout << maxValue;
}