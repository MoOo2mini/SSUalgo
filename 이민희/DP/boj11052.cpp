#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];

    int max_tmp = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            max_tmp = max(arr[i], dp[i - j] + arr[j]);
            if (max_tmp > dp[i]) {
                dp[i] = max_tmp;
            }
        }
    }

    cout << dp[n];
}