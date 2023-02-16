#include <iostream>
using namespace std;

const int E = 15;
const int S = 28;
const int M = 19;

int e, s, m;

bool check(int a, int b, int c) {
    if (a == e && b == s && c == m) {
        return true;
    }
    return false;
}

int main() {
    int tmpe, tmps, tmpm;
    cin >> e >> s >> m;
    tmpe = 1;
    tmps = 1;
    tmpm = 1;

    int result = 1;
    while (true) {
        if (check(tmpe, tmps, tmpm)) break;
        tmpe++; tmps++; tmpm++; result++;
        if (tmpe > E) {
            tmpe = 1;
        }
        if (tmps > S) {
            tmps = 1;
        }
        if (tmpm > M) {
            tmpm = 1;
        }
    }
    cout << result;
}