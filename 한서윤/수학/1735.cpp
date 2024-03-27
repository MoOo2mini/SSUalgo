#include <bits/stdc++.h>
using namespace std;
int gcd(int, int);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m, n;
    m = b * d;          // 분모
    n = a * d + b * c;  // 분자

    int g = gcd(m, n);
    cout << n / g << " " << m / g;  // 기약분수로 표현하기 위해 최대공약수로 나눠줌.
}

int gcd(int a, int b) {  // 최대공약수 구하기.
    if (a < b) swap(a, b);
    int r;  // 나머지 저장.ㄴ
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}