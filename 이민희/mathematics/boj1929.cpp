#include <iostream>
using namespace std;

int is_prime(int num) {
    for (int i = 2; (i * i) <= num; i++) {
        if (num % i == 0) {
            return -1;
        }
    }
    return num;
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        if (i > 1) {
            int tmp = is_prime(i);
            if (tmp != -1) {
                cout << is_prime(i) << '\n';
            }
        }
    }
}
