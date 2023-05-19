#include <bits/stdc++.h>
//하하하모르겠음
using namespace std;
int n,m;
int* sum;
int ans;
vector<int> cow;

void mult(){
    for(int k=0;k<n;k++){
        int mul=1;
        for(int i=0;i<4;i++){
            if(k+i<n){
                mul*=cow[k+i];
            }
            else{
                mul*=cow[k+i-n];
            }
        }
        sum[k]=mul;
    }
}

void attack(int num){
    for(int i=num-3;i<=num;i++){
        if(i<0){
            ans-=(sum[n+i]);
        }
        else
            ans-=(sum[i]);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        cow.push_back(tmp);
    }
    
    sum = new int[n]; 
    mult();
    ans=0;
    for(int i=0;i<n;i++){
        ans+=sum[i];
    }

    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        attack(tmp-1);
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}