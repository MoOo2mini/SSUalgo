#include <bits/stdc++.h>
using namespace std;

int main(void) { // 입력된 값이 아닌 값도 땅의 높이가 될 수 있다는걸 생각 못 했다 ... map으로 뻘짓했다 ..
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long n, m, b;
    cin >> n >> m >> b;
    int ground[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> ground[i][j];
    }

    int height = 0;
    long long min_time = 999999999;
    for (int h = 0; h < 257; h++) {  // 땅 고르기
        long long time = 0;
        long long inv = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int adj = ground[i][j] - h;
                if (adj > 0) {  // case 1
                    inv += adj;
                    time += 2 * adj;
                } else if (adj < 0) {  // case 2
                    adj = -adj;
                    inv -= adj;
                    time += adj;
                }
            }  // 실제 땅의 크기 바꾸지 않아도 되는데 수정해서 오류난 거였다 ..
        }
        if (inv < 0) continue;
        else if (min_time > time) {
            height = h;
            min_time = time;
        } else if (min_time == time) {
            if (height < h) height = h;
        }
        // cout << iter->first << "/" << iter->second << "/" << inv << '\n';
    }
    cout << min_time << " " << height;
}