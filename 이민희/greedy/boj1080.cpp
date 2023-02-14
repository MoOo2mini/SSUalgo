#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int arra[51][51];
int arrb[51][51];

bool same() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arra[i][j] != arrb[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void change(int y, int x) {
    for (int i = y; i < y + 3; i ++) {
        for (int j = x; j < x + 3; j++) {
            if (arra[i][j]) {
                arra[i][j] = false;
            } else {
                arra[i][j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arra[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arrb[i][j]);
        }
    }
    // if (n < 3 || m < 3) {
    //     cout << -1;
    //     return 0;
    // }
    
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (arra[i][j] != arrb[i][j]) {
                change(i, j);
                count++;
            }
        }
    }
    if (same()) {
        cout << count; 
    } else {
        cout << -1;
    }
}