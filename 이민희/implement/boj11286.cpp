#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp {
    bool operator()(pair<int, int> A, pair<int, int> B) {
        if (A.first < B.first)
            return true;
        return false;
    }
};

int main() {
    vector<int> result;
    int n, tmp;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (pq.empty()) {
                // cout << 0 << '\n';
                result.push_back(0);
            } else {
                // cout << pq.top().second << '\n';
                result.push_back(pq.top().second);
                pq.pop();
            }
        } else {
            pq.push(make_pair(abs(tmp), tmp));
        }
    }
    // cout << " ------------- " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    // 놓친 조건 : 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
}
