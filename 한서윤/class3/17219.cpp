#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    map<string, string> map;

    for (int i = 0; i < n; i++) {  // 사이트 주소, 비밀번호 입력.
        string address, password;
        cin >> address >> password;
        map.insert(pair<string, string>(address, password));
    }

    for (int i = 0; i < m; i++) {  // 비밀번호 찾기.
        string add;
        cin >> add;

        cout << map.find(add)->second << '\n';
    }
}