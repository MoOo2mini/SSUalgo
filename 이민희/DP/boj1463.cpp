#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    
    cin >> N;
    vector<int> dp(N + 1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1; // 방법 1
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1); // 방법 1과 방법 2를 비교하여 둘 중 작은 걸 선택
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1); // 방법 1과 방법 2를 비교하여 둘 중 작은 걸 선택
    }

    cout << dp[N];
}