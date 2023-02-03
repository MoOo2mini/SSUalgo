#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int dp[n];
    dp[0] = v.front();
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + v[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += dp[i];
    }

    cout << result;
}