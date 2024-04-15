#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int matA[n][m];
    int matB[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            matA[i][j] = input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            matB[i][j] = input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int output;
            output = matA[i][j] + matB[i][j];
            cout << output << " ";
        }
        cout << '\n';
    }
}