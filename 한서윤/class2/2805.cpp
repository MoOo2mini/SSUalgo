#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long n, m, max, mid, sum;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) max = v[i];
        if (v[i] > max) max = v[i];
    }

    long long start = 1, end = max;
    while (start <= end) {
        sum = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            if (v[i] > mid) sum += v[i] - mid;
        }
        if (sum >= m)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}