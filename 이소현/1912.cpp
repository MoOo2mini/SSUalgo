#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[100001]={0,};
    int dp[100001]={0,};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=arr[0];
    int ans=dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}