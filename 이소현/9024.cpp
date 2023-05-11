#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<long> v;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int x=0;
        int cnt=0;
        while(cnt==0){
            auto left = v.begin();
            auto right = v.end()-1;
            while(left<right){
                //cout<<*left<<" "<<*right<<'\n';
                int num = *left+*right;
                //cout<<"num: "<<num<<"\n";
                if(num==(k+x)||num==(k-x)){
                    cnt++;
                    if(*(left+1)+*(right)==k+x||*(left+1)+*(right)==k-x)
                        cnt++;
                    else if(*(left)+*(right-1)==k+x||*(left)+*(right-1)==k-x)
                        cnt++;
                    left++; right--;
                }
                else if(num<(k+x)||num<(k-x))
                    left++;
                else
                    right--;
            }
            x++;
        }
        cout<<cnt<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}