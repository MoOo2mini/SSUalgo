#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int t;
    cin >> t;

    vector<long long> v;
    for (int w = 0; w < t; w++) {
        long long n;
        cin >> n;

        long long arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long result = 0;

        for (int i = 0; i < (n - 1); i++) {
            for (int j = (i + 1); j < n; j++) {
                if (arr[i] > arr[j]) {
                    result += gcd(arr[j], arr[i]);
                } else {
                    result += gcd(arr[i], arr[j]);
                }
            }
        }

        v.push_back(result);
    }

    for (int i = 0; i < t; i++) {
        cout << v[i] << endl;
    }
}