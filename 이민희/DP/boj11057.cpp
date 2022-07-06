#include <iostream>
#define mod 10007
using namespace std;

int dp[1001][10];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if (j == 0)  dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
            }
        }
    }

    int sum = 0;

    for(int i=0; i<=9; i++){
        sum = (sum + dp[n][i]) % mod;
    }

    cout << sum << "\n";
    
    return 0;
}