#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, idx;
    cin >> n;

    map<int, int> m;

    for (int i = 0; i < n; i++) {  // 배열에 입력 값 저장.
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        m.insert(pair<int, int>(tmp1, tmp2));
    }

    vector<int> lis = {m.begin()->second};

    for (auto const &pair : m) {          // map의 B전봇대 값을 순서대로 확인.
        if (lis.back() >= pair.second) {  // 작거나 같으면 대체.
            idx = lower_bound(lis.begin(), lis.end(), pair.second) - lis.begin();
            lis[idx] = pair.second;
        } else  // 크면 맨 뒤에 삽입.
            lis.push_back(pair.second);
    }

    int output = n - lis.size();
    cout << output << '\n';
}