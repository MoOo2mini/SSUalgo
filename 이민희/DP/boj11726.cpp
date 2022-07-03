#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> dp(n+1);

    // n은 자연수이기 때문에 1부터 시작하도록 한다.
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];
}