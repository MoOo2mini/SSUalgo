#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arrA[n];
    int arrB[n];

    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arrB[i];
    }

    sort(arrA, arrA + n, greater<int>());
    sort(arrB, arrB + n);

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += arrA[i] * arrB[i];
    }

    cout << result;
}