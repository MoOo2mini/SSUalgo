#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
            } else if (j == i) {
                arr[i][j] += arr[i - 1][j - 1];
            }else {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < arr[n - 1][i]) max = arr[n - 1][i];
    }

    cout << max;
}