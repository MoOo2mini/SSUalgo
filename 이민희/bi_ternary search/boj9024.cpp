#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 100000001

int n, k;

int find_logic(vector<int> v) {
    sort(v.begin(), v.end());
    int cnt = 0;
    int li = 0;
    int ri = n - 1;
    int l, r;
    int minV = INF;
    while (li < ri) {
        l = v[li];
        r = v[ri];
        if (k == l + r) {
            li++;
            ri--;
        } else if (k < l + r) {
            ri--;
        } else {
            li++;
        }

        if (abs(k - (l + r)) < minV) {
            minV = abs(k - (l + r));
            cnt = 1;
        } else if (abs(k - (l + r)) == minV) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int T, tmp;
    cin >> T;
    vector<int> answer;

    while (T--) {
        vector<int> v;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }

        // find logic
        answer.push_back(find_logic(v));
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}