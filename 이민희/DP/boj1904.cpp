#include <iostream>
using namespace std;

int dp[1000000];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    if (n <= 3)
    {
        cout << dp[n];
        return 0;
    }
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] * 2 - 2;

    cout << dp[n];
}