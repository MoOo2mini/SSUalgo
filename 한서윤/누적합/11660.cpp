#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int mat[n][n];
    for (int i = 0; i < n; i++) {  // 입력 받으면서 누적합 저장.
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            mat[i][j] = input;
            if (j) mat[i][j] += mat[i][j - 1];
        }
        if (i) {
            for (int j = 0; j < n; j++) {
                mat[i][j] += mat[i - 1][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {  // 연산.
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1--, x2--, y1--, y2--;
        int output = mat[y1][y2];

        if (x1 > 0) output -= mat[x1 - 1][y2];
        if (x2 > 0) output -= mat[y1][x2 - 1];
        if (x1 > 0 && x2 > 0) output += mat[x1 - 1][x2 - 1];
        cout << output << '\n';
    }
}