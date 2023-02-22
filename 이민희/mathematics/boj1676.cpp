#include <iostream>
using namespace std;

int n, two, five;

int getTwo(int n) {
    int result = 0;
    while (n % 2 == 0 && n != 0) {
        n /= 2;
        result++;
    }

    return result;
}

int getFive(int n) {
    int result = 0;
    while (n % 5 == 0 && n != 0) {
        n /= 5;
        result++;
    }

    return result;
}

int main() {
    cin >> n;
    // cout << " " << getTwo(n) << " " << getFive(n) << endl;
    for (int i = 1; i <= n; i++) {
        two += getTwo(i);
        five += getFive(i);
    }

    cout << min(two, five);
}