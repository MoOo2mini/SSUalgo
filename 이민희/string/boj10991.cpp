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
    for (int i = 0; i < n; i++) {
        cout << '*';
        if ((i + 1) != n) {
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