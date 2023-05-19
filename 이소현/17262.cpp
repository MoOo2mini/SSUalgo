#include <iostream>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int firstend=100001;
    int laststart=0;

    struct Line{
        int start;
        int end;
    };

    Line* l = new Line[n];
    int line;

    for(int i=0;i<n;i++){
        cin>>l[i].start>>l[i].end;
        if(l[i].start>=laststart){
            laststart = l[i].start;
        }
        if(l[i].end<=firstend){
            firstend = l[i].end;
        }
        if(laststart==l[i].start&&firstend==l[i].end){
            line = i;
        }
    }
    if(laststart==l[line].start&&firstend==l[line].end){
        cout<<"0";
    }
    else
        cout<<laststart-firstend<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}