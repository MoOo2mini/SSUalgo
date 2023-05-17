#include <iostream>
using namespace std;

int main() {
    int n, left, right, tmp;
    cin >> n;
    left = 0; right = 0;
    cin >> tmp;
    left += tmp;
    cin >> tmp;
    right += tmp;

    n -= 2;
    while (n--) {
        cin >> tmp;
        // 만약 양팔저울이 평형을 이루는 경우, i번 자갈을 왼쪽에 올려 놓는다.
        // 만약 양팔저울이 평형을 이루지 않는 경우, i번 자갈을 가벼운 쪽에 올려 놓는다.
        if (left == right) {
            left += tmp;
        } else if (left < right) {
            left += tmp;
        } else { 
            right += tmp;
        }
    }

    if (left == right) {
        cout << 0;
    } else {
        int cnt = 0;
        int extraV = abs(left - right);
        
        if (extraV / 100) {
            cnt += extraV / 100;
            extraV %= 100;
        }
        if (extraV / 50) {
            cnt += extraV / 50;
            extraV %= 50;
        }
        if (extraV / 20) {
            cnt += extraV / 20;
            extraV %= 20;
        }
        if (extraV / 10) {
            cnt += extraV / 10;
            extraV %= 10;
        }
        if (extraV / 5) {
            cnt += extraV / 5;
            extraV %= 5;
        }
        if (extraV / 2) {
            cnt += extraV / 2;
            extraV %= 2;
        }
        if (extraV / 1) {
            cnt += extraV / 1;
            extraV %= 1;
        }
        cout << cnt;
    }
}