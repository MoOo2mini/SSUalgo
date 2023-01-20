#include <iostream>
#include <vector>

using namespace std;
int arr[101];
long long dp[101];

long long solve(int n) {
    if (n < 10) {
        return dp[n - 1];
    }

    for (int i = 10; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    return dp[n - 1];
}

int main() {

    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 4;
    dp[7] = 5;
    dp[8] = 7;
    dp[9] = 9;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << solve(arr[i]) << endl;
    }
}

// dp 문제의 경우 수가 급격히 커지므로 자료형을 Long long으로 해야한다.