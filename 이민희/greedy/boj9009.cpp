#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp, maxV;
    maxV = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);

        if (tmp > maxV) maxV = tmp;
    }

    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);

    int idx = 0;
    if (maxV > 2) {
        for (idx = 2; idx <= maxV; idx++) {
            dp.push_back(dp[idx - 1] + dp[idx - 2]);
            if (dp[idx] >= maxV) {
                dp.push_back(0);
                break;
            }
        }
    }

    // for (int i = idx; i >= 0; i--) cout << dp[i] << " ";
    for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        // cout << "num" << num << endl;
        vector<int> v;
        for (int j = idx; j >= 0; j--) {
            if (num >= dp[j]) {
                num -= dp[j];
                v.push_back(dp[j]);
            } else {
                continue;
            }

            if (num == 0) {
                for (int i = v.size() - 1; i >= 0; i--) {
                    cout << v[i] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
}