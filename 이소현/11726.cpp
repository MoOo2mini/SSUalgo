#include <bits/stdc++.h>

using namespace std;

void solve(){
    int dp[1001];
    int n;
    cin>>n;

    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}