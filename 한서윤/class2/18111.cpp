#include <bits/stdc++.h>
using namespace std;

int main(void) { // �Էµ� ���� �ƴ� ���� ���� ���̰� �� �� �ִٴ°� ���� �� �ߴ� ... map���� �����ߴ� ..
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
    for (int h = 0; h < 257; h++) {  // �� ����
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
            }  // ���� ���� ũ�� �ٲ��� �ʾƵ� �Ǵµ� �����ؼ� ������ �ſ��� ..
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