#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> v;
    
    long long tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long count = 0;
    long long max = 0;
    long long result = v[0];
    if (n == 1) {
        cout << v[0];
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            count++;
            if (max < count) {
                max = count;
                result = v[i];
            }
        } else {
            count = 0;
        }

    }

    cout << result;
}
