#include <vector>
#include <iostream>
using namespace std;

int dp(int n)
{
    vector<int> dp(n+1);

    // n은 자연수이기 때문에 1부터 시작하도록 한다.
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]);
    }

    return dp[n];
}

int main(){
    int n;

    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        cout << dp(arr[i]) << '\n';
}