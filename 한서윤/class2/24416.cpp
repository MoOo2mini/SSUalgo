#include <bits/stdc++.h>
using namespace std;

int fib(int);
int fibonacci(int);
int num1 = 1, num2 = 0;
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    fib(n);
    fibonacci(n);

    cout << num1 << " " << num2;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        num1++;
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n) {
    vector<int> f(40);
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        num2++;
    }
    return f[n];
}