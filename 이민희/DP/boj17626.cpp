#include <iostream>
using namespace std;
bool notprime[50001];

void init() {
    notprime[1] = true;
    for (int i = 2; i * i < 50001; i++) {
        notprime[i * i] = true;
    }
}

int main() {
    init();
    int n; cin >> n;
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for (int i = 4; i <= n; i++) {
        dp[i] = i;
        if (notprime[i]) {
            dp[i] = 1;
            continue;
        }
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
}