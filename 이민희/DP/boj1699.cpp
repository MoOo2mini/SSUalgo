#include <iostream>
#include <cmath>
using namespace std;

int dp[1000];

int main() {
    int n;
    cin >> n;

    int tmp = n;
    int count = 0;
    for (int i = n; i > 0; i--) {
        double digit = sqrt(i) - (int) sqrt(i);
        if (digit == 0.0) {
            if (tmp - i >= 0) {
                tmp -= i;
                count++;
                cout << i << endl;
            }
        }
    }

    cout << tmp + count;
}