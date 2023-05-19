#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int house[1001][n];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    for(int i=1;i<=n;i++){
        int r, g, b;
        cin>>r>>g>>b;
        house[i][0] = min(house[i-1][1],house[i-1][2])+r;
        house[i][1] = min(house[i-1][0],house[i-1][2])+g;
        house[i][2] = min(house[i-1][0],house[i-1][1])+b;
    }
    cout<<min(house[n][0],min(house[n][1],house[n][2]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}