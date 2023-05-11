#include <iostream>
#include <cmath>

using namespace std;

void solve(){

    struct Balance{
        long left;
        long right;
    };

    int n;
    cin>>n;

    Balance bal;
    cin>>bal.left;
    cin>>bal.right;

    for(int i=0;i<n-2;i++){
        int x;
        cin>>x;
        if(bal.left==bal.right){
            bal.left+=x;
        }
        else{
            if(bal.left>bal.right)
                bal.right+=x;
            else
                bal.left+=x;
        }
    }
    
    //greedy
    int k = abs(bal.left-bal.right);
    int chu[]={100,50,20,10,5,2,1};
    int cnt=0;
    for(int i=0;i<7;i++){
        while(k-chu[i]>=0){
            cnt++;
            k-=chu[i];
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