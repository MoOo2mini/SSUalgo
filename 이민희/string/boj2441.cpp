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
    }
}

int main() {
    cin >> T;

    for (int i = T; i > 0; i--) {
        printSpace(i);
        printStar(i);
        cout << '\n';
    }
}