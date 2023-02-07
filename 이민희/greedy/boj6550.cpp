#include <iostream>
#include <string>
using namespace std;

void func(string a, string b) {
    int idx = 0;
    bool isSub = false;
    for (int i = 0; i < b.length(); i++) {
        if (a[idx] == b[i]) {
            idx++;
        }
        if (idx == a.length()) {
            isSub = true;
            break;
        }
    }
    
    if (isSub) {
        cout << "YES" << '\n';
        return;
    } else {
        cout << "NO" << '\n';
        return;
    }
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        func(a, b);
    }
}