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
    n = n  * 2 - 1;
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
}

int main() {
    cin >> T;

    for (int i = T; i > 0; i--) {
        printSpace(i);
        printStar(i);
        cout << '\n';
    }

    for (int i = 2; i <= T; i++) {
        printSpace(i);
        printStar(i);
        cout << '\n';
    }
}