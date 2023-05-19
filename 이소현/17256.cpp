#include <iostream>

using namespace std;

void solve(){
    struct dot{
        int x;
        int y;
        int z;
    };
    dot a,b,c;
    cin>>a.x>>a.y>>a.z>>c.x>>c.y>>c.z;
    b.x = c.x-a.z;
    b.y = c.y/a.y;
    b.z = c.z-a.x;
    cout<<b.x<<" "<<b.y<<" "<<b.z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}