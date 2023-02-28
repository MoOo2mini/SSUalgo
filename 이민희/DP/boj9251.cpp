#include <iostream>
using namespace std;
string s, t;
int dp[1001];

int main() {
    cin >> s >> t;
    if (s.length() > t.length()) {
        string tmp = s;
        s = t;
        t = tmp;
    }

    int i = 0; int j = 0; int idx = 0;
    if (s[0] == t[0]) {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            // cout << s[i] << " " << t[j] << endl;
            i++; j++;
            if (idx != 0) dp[idx] = dp[idx - 1] + 1;
        } else {
            // cout << t[j] << endl;
            j++;
            if (idx != 0) dp[idx] = dp[idx - 1];
        }
        idx++;
    }
    if (i != s.length()) {
        for (i = i; i < s.length(); i++) {
            if (t[j - 1] == s[i]) {
                dp[idx] = dp[idx - 1] + 1;
            } else {
                dp[idx] = dp[idx - 1];
            }
            idx++;
        }
    } else if (j != t.length()) {
        for (j = j; j < t.length(); j++) {
            if (s[i - 1] == t[j]) {
                dp[idx] = dp[idx - 1] + 1;
            } else {
                dp[idx] = dp[idx - 1];
            }
            idx++;
        }
    }
    
    // cout << i << j << endl;
    // for (int i = 0; i < idx; i++) {
    //     cout << dp[i] << endl;
    // }
    cout << dp[idx - 1];
}