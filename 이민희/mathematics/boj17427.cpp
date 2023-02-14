#include <iostream>
using namespace std;

int main() {
    int n;
    long long result = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        result += (n / i) * i;
    }

    cout << result;
}