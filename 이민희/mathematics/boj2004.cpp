#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long m, n;
    cin >> m >> n;

    long long up = 1;
    long long down = 1;
    for (int i = m; i < n; i++) {
        up *= i;
    } 
    for (int i = 1; i <= n; i++) {
        down *= i;
    }

    long long tmp = up / down;
    while
}