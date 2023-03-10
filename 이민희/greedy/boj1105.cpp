#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length()) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i] && a[i] == '8') {
            ans++;
        } else if (a[i] != b[i]) {
            break;
        }
    }
    cout << ans;
}