// n이 짝수면 정렬했을 때 중간 두 값의 사이에 있는 모든 값.
// n이 홀수면 정렬했을 때 정가운데 있는 값.

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, a, b, output;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(b - a);
    }
    sort(v.begin(), v.end());

    if (n % 2) {  // n이 홀수일 때
        output = 1;
    } else {
        output = v[n / 2] - v[n / 2 - 1] + 1;
    }

    cout << output;
}