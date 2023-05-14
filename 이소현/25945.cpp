#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n, sum=0;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        v.push_back(tmp);
    }
    int avg = sum/n;
    sort(v.rbegin(), v.rend());
    int first=0;
    int second=0;
    int need=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]>avg) first+=v[i]-(avg+1);
        //else if(v[i]==avg) second+=v[i]-avg;
        else if(v[i]<avg) need+=avg-v[i];
    }
    if(need-first>0) cnt=need;
    else if(need-first<=0) cnt=first;

    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}