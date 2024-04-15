#include <bits/stdc++.h>
using namespace std;
bool arr[10000001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long a, b, b2;
    cin >> a >> b;

    b2 = (long long)sqrt(b);  // 루트 b.
    fill_n(arr, b2 + 1, 1);
    arr[0] = 0, arr[1] = 0;

    for (long long i = 2; i <= sqrt(b2); i++) {  // 루트 b까지의 소수 찾기.
        if (arr[i]) {
            for (long long j = 2; j <= b2 / i; j++) {  // 런타임 에러 때문에 i*j <= b -> j <= b2/i.
                arr[i * j] = 0;
            }
        }
    }

    int count = 0;
    for (long long i = 2; i <= b2; i++) {
        int j = 2;
        if (arr[i]) {
            while (pow(i, j) <= b) {
                if (pow(i, j) >= a) count++;
                j++;
            }
        }
    }
    cout << count;
}