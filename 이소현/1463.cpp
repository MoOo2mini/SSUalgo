#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    while(n--){
    int dp[12]={0,};
    int x;
    cin>>x;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;//111 21 3 12

    for(int i=4;i<=x;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[x]<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}