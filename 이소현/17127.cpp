#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int mult(int a, int b){
    int cnt=1;
    for(;a<=b;a++){
        cnt*=v[a];
    }
    return cnt;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }


    int cnt=1;
    int sum=0, maxsum=0;
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                    sum = mult(0,i)+mult(i+1,j)+mult(j+1,k)+mult(k+1,l);
                    if(maxsum<sum) maxsum=sum;
                }
            }
        }
    }
    cout<<maxsum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}