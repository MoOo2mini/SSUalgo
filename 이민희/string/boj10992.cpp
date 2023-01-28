#include <iostream>
using namespace std;
int T;

void printSpace(int n) {
    n = T - n;
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
}

void printStar(int n) {
    if (n == T) {
        for (int i = 0; i < (n * 2 - 1); i++) {
            cout << '*';
        }
        return;
    }

    n = n * 2 - 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (i + 1) == n) {
            cout << '*';
        } else {
            cout << ' ';
        }
    }
}

int main() {
    cin >> T;

    for (int i = 1; i <= T; i++) {
        printSpace(i);
        printStar(i);
        cout << '\n';
    }
}