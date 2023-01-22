#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < (n - i) * arr[i]) {
            max = (n - i) * arr[i];
        }
    }

    cout << max;
}