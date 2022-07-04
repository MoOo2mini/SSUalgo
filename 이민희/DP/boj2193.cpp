#include <iostream>
#define mod 1000000000
using namespace std;

long long dp[91][2];

int main(){

    int n;
    cin >> n;
	
    dp[1][0] = 0;
	dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j <= 1; j++){
            if (j == 0) dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			else dp[i][1] = dp[i - 1][0];
        }
    }

    long long sum = 0;

    for(int i=0; i<=1; i++){
        sum = (sum + dp[n][i]);
    }

    cout << sum;

    return 0;
}