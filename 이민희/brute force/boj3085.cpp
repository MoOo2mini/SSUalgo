#include <iostream>
#include <stdio.h>
using namespace std;
char arr[51][51];
int n;

int checkY(char c) {
    bool done = false;
    int tmp = 0;
    // 행 조사
    int max = 0;
    for (int j = 0; j < n; j++) {
        tmp = 0;
        done = false;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == c) {
                tmp++;
            }
            if (i - 1 >= 0 && !done) {
                if (arr[i - 1][j] == c) {
                    tmp++;
                    done = true;
                    break;
                }
            }
            if (i + 1 < n && !done) {
                if (arr[i + 1][j] == c) {
                    tmp++;
                    done = true;
                    break;
                }
            }
            
        }
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}


int checkX(char c) {
    bool done = false;
    int tmp = 0;
    // 행 조사
    int max = 0;
    for (int i = 0; i < n; i++) {
        tmp = 0;
        done = false;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == c) {
                tmp++;
            }
            if (i - 1 >= 0 && !done) {
                if (arr[i - 1][j] == c) {
                    tmp++;
                    done = true;
                    break;
                }
            }
            if (i + 1 < n && !done) {
                if (arr[i + 1][j] == c) {
                    tmp++;
                    done = true;
                    break;
                }
            }
            
        }
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1s", &arr[i][j]);
        }
    }

    // cout << checkX('C');
    // cout << checkX('Y');
    // cout << checkX('P');
    // cout << checkX('Z') << endl;

    // cout << checkY('C');
    // cout << checkY('Y');
    // cout << checkY('P');
    cout << checkY('C') << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
}