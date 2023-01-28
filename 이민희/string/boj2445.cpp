#include <iostream>
using namespace std;
int T;

void printSpace(int n) {
    n = (T - n) * 2;
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
}

void printLeftStar(int n) {
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
}

void printRightStar(int n) {
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
}

int main() {
    cin >> T;

    for (int i = 1; i <= T; i++) {
        printLeftStar(i);
        printSpace(i);
        printRightStar(i);
        cout << '\n';
    }

    for (int i = (T - 1); i > 0; i--) {
        printLeftStar(i);
        printSpace(i);
        printRightStar(i);
        cout << '\n';
    }
}