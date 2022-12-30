#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int testcase;
    vector<int> v;

    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        v.clear();
        int n, m, print = 0;
        cin >> n >> m;
        int front = 0, rear = n - 1;
        for (int j = 0; j < n; j++) {
            int imp;
            cin >> imp;
            v.push_back(imp);
        }

        while (m != -1) {
            if (n == 1) {
                print++;
                break;
            }
            for (int j = 0; j < n; j++) {
                if (j != front && v[j] > v[front]) {  // 중요도가 높은 문서가 있으면 가장 뒤로 재배치
                    rear = front;
                    front++;
                    if (front > n - 1) front -= n;
                    if (m == 0) m += n;
                    m--;
                    break;
                }

                if (j == n - 1) {  // 끝까지 다 돌았으면 인쇄
                    v[front] = 0;
                    print++;
                    rear = front;
                    front++;
                    if (front > n - 1) front -= n;
                    if (m == 0)
                        m = -1;  // m을 인쇄하는 경우
                    else
                        m--;
                }
            }
        }
        cout << print << '\n';
    }
}