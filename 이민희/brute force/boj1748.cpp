#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int result = 0;
    for (int i = 1; i <= n; i *= 10) {
        result += n - i + 1;
    }

    cout << result;
}