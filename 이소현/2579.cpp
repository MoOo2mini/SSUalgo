#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int stair[301];
    for(int i=1;i<=n;i++){
        cin>>stair[i];
    }
    int dp[301]={0,};
    dp[0]=0;
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];
    dp[3]=max(dp[1]+stair[3],stair[2]+stair[3]);
    for(int i=4;i<=n;i++){
        dp[i] = max(dp[i-2]+stair[i],dp[i-3]+stair[i-1]+stair[i]);
    }
    cout<<dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}