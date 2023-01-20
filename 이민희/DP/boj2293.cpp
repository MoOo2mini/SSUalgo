#include <iostream>
using namespace std;
int arr[10001];
int main() {
    int n, k;
    cin >> n >> k;

    int coin[n];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    arr[0] = 1;


    for (int j = 0; j < n; j++) {
        for (int i = coin[j]; i <= k; i++) { 
            arr[i] += arr[i - coin[j]];
        }
    }

    cout << arr[k];
}

// 배열의 쓰레기 값을 조심하자.