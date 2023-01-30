#include <iostream>
#define mod 1000000000
using namespace std;

int main(){
    int c;
    cin >> c;

    long long arr[101][10];
    arr[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= c; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                arr[i][j] = arr[i - 1][j + 1];
            } else if (j == 9) {
                arr[i][j] = arr[i - 1][j - 1];
            } else {
                arr[i][j] = arr[i - 1][j + 1] + arr[i - 1][j - 1];
            }
            arr[i][j] %= mod;
        }
    }

    long long result = 0;
    for (int i = 0; i < 10; i++) {
        result += arr[c][i];
    }
    cout << result % mod;
}