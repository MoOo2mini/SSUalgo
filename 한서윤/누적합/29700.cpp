#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m, k, count = 0;
    cin >> n >> m >> k;
    vector<vector<int>> seat(n, vector<int>(m, 0));  // 2차원 벡터.

    for (int i = 0; i < n; i++) {  // 입력 받으면서 누적합 저장.
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '0') {
                seat[i][j] = 1;
                if (j) seat[i][j] += seat[i][j - 1];
            }
        }
    }

    // cout << '\n';
    // for (int i = 0; i < n; i++) { // 누적합 배열 확인.
    //     for (int j = 0; j < m; j++) {
    //         cout << seat[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < n; i++) {  // k보다 크거나 같은면 count++.
        for (int j = 0; j < m; j++) {
            if (seat[i][j] >= k) count++;
        }
    }

    cout << count;
}