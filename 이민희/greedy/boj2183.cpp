#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int minValue = 2147483647;

bool check(int* arr, int* goal) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != goal[i]) {
            return false;
        }
    }
    return true;
}

void change(int* arr, int idx) {
    if (idx - 1 >= 0) {
        arr[idx - 1] = (arr[idx - 1] == 1) ? 0 : 1;
    }
    arr[idx] = (arr[idx] == 1) ? 0 : 1;
    if (idx + 1 < n) {
        if (arr[idx + 1] == 1) {
            arr[idx + 1] = 0;
        } else {
            arr[idx + 1] = 1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i];
    // }
    // cout << endl;
}

int main() {
    cin >> n;
    int now[n]; int goal[n];
    int tmp[n];

    for (int i = 0; i < n; i++) {
        scanf("%1d", &now[i]);
        tmp[i] = now[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &goal[i]);
    }

    // 0번을 누르는 경우
    int cnt = 0;
    change(tmp, 0); cnt++;
    for (int i = 1; i < n; i++) {
        if (tmp[i - 1] != goal[i - 1]) {
            change(tmp, i);
            cnt++;
        }
    }
    // cout << cnt;
    if (minValue > cnt) {
        if (check(tmp, goal))
            minValue = cnt;
        else
            minValue = -1;
    }

    // 0번을 누르지 않는 경우
    cnt = 0;
    for (int i = 0; i < n; i++) {
        tmp[i] = now[i];
    }
    for (int i = 1; i < n; i++) {
        if (tmp[i - 1] != goal[i - 1]) {
            change(tmp, i);
            cnt++;
        }
    }
    if (minValue > cnt || minValue == -1) {
        if (check(tmp, goal))
            minValue = cnt;
        else if (minValue == -1)
            minValue = -1;
    }

    cout << minValue;
}