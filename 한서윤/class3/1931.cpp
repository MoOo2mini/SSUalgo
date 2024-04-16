#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    multiset<pair<int, int>> m;  // multiset에 pair 형식으로 저장.

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        m.insert(pair<int, int>(e, s));  // 종료시간, 시작시간 순으로 저장.
    }

    multiset<pair<int, int>>::iterator iter;  // 종료시간이 빠른 순, 시작시간이 빠른 순으로 선택.
    int finish = m.begin()->first, count = 1;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter == m.begin()) continue;
        if (iter->second >= finish) {
            finish = iter->first;
            count++;
        }
    }
    cout << count;
}