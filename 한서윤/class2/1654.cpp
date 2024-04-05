#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long k, n, max, mid;
    cin >> k >> n;
    vector<long long> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        if (i == 0) max = v[i];
        if (v[i] > max) max = v[i];
    }

    long long start = 1, end = max;
    while (start <= end) {
        int num = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < k; i++) {
            num += v[i] / mid;
        }
        if (num >= n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}