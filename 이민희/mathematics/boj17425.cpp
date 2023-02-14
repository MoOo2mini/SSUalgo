#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    vector<int> v;
    long long result = 0;

    cin >> t;
    while (t--) {
        result = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            result += (n / i) * i;
        }

        v.push_back(result);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}