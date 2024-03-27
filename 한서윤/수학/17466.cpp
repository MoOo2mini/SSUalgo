// 오버플로우 방지를 위해 unsigned long long형 사용.
// 각각의 나머지를 곱하고, 곱한 값의 나머지 구함.

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    unsigned long long n, p, num = 1;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        num *= i % p;
        num %= p;
    }
    cout << num % p;
}