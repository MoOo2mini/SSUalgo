#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    char s[100001] = {0};
    cin >> s;

    //check
    bool zz = false;
    int thr = 0;
    int i;
    for (i = 0; s[i] != 0; i++){
        if (s[i] == '0')    zz = true;
        thr += s[i] - '0';
    }
    if (!zz || thr % 3 != 0){
        cout << "-1";
        return 0;
    }

    sort(s, s + i, greater<char>());
    cout << s;
}