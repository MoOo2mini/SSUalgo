#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, k, index = -1;
    vector<int> v, result;
    cin >> n >> k;

    for (int i = 1; i < n + 1; i++) v.push_back(i);
    while (v.size() > 1) {
        index += k;
        while (index >= v.size()) {
            index -= v.size();
        }
        result.push_back(v[index]);
        v.erase(v.begin() + index);
        index--;
    }
    result.push_back(v[0]);

    cout << '<';
    for (int i = 0; i < n - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result[n - 1] << '>';
}