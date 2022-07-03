#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10];

int main(){

    int n;
    cin >> n;

    // 1자리 일 때, 1개 이므로 1로 set
    // 0은 올수 없기때문에 0은 제외
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % mod; // '0' 일 때, '1' 만 가능
            } else if(j == 9){
                dp[i][j] = dp[i-1][j-1] % mod; // '9' 일 때, '8' 만 가능
            } else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
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