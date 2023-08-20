#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void solve(){
    vector<int> v;

    int n,s;
    cin>>n>>s;
    while(n--){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    //sort(v.begin(), v.end());
    auto left = v.begin();
    auto right = v.begin();
     
    int minnum=987654321;
    
    int sum = 0;
    while(left<=right){
        if(sum>=s){
            int num = right-left;
            minnum = min(minnum, num);

            sum-=*left;
            left++;
        }
        
        else if (sum<s&&right>=v.end()){
            break;
        }
        else {
            sum+=*right;
            right++;
        }
    }

    if(minnum==987654321){ cout<<"0"; return;}
    cout<<minnum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}