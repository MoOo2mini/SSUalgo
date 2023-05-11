#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    int cnt=0;
    for(int i=0;i<n;i++){
        while(k-v[i]>=0){
            cnt++;
            k-=v[i];
        }
    }
    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}