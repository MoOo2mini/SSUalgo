#include <iostream>
using namespace std;

int main() {
    int a, b;
    char c;
    
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> c >> b;
        cout << a + b << '\n';
    }
}