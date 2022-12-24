#include <iostream>
using namespace std;

int main() {
    int N, C; // 4 7
    cin >> N >> C;

    N++; C++;
    int K[N][C]; // 5 8

    int arr[N][2];

    for (int i = 0; i < N; i++){ // 0 ~ 4
        K[i][0] = 0;
    }
    for (int i = 0; i < C; i++){
        K[0][i] = 0;
    }

    for (int i = 1; i < N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i < N; i++) {
        for (int w = 1; w < C; w++) {
            if (arr[i][0] > w) { // 물건의 무게가 임시 배낭의 무게보다 크다면,
                K[i][w] = K[i - 1][w];
            } else {
                K[i][w] = max(K[i - 1][w], K[i - 1][w - arr[i][0]] + arr[i][1]);
            }
        }
    }

    cout << K[N - 1][C - 1];
}