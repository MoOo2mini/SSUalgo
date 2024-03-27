#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    // 배열 초기화.
    int input[n] = {
        0,
    };

    for (int i = 0; i < n; i++) {  // 배열에 입력 값 저장.
        int tmp;
        cin >> tmp;
        input[i] = tmp;
    }

    vector<int> lis = {
        input[0],
    };

    for (int i = 1; i < n; i++) {  // 확인
        int start = 0, end = lis.size(), mid, idx;
        if (input[i] <= lis.back()) {  // 마지막 값보다 작거나 같으면 위치 찾아서 넣기.
            idx = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
            lis[idx] = input[i];
        } else {  // 크면 맨 뒤에 삽입.
            lis.push_back(input[i]);
        }
    }
    cout << lis.size();
}