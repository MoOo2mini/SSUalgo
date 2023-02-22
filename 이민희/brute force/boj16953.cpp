#include <iostream>
#include <queue>
using namespace std;
long long a, b;

int main() {
    cin >> a >> b;
    int cnt = 1;
    bool check = false;
    while (true) {
        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 == 1) {
            b /= 10;
        } else {
            break;
        }
        cnt++;

        if (a == b) {
            check = true;
            break; 
        } else if (a > b) {
            break;
        }
    }

    if (check) {
        cout << cnt;
    } else {
        cout << -1;
    }
}