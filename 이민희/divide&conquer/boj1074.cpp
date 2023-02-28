#include <iostream>
using namespace std;
int n, r, c;
int answer;
void divide(int y, int x, int size) {
    if (r == y && c == x) {
        cout << answer;
        return;
    } else if (c < x + size && r < y + size && c >= x && r >= y) {
        divide(y, x, size / 2);
        divide(y, x + size / 2, size / 2);
        divide(y + size / 2, x, size / 2);
        divide(y + size / 2, x + size / 2, size / 2);
    } else {
        answer += size * size;
    }
}

int main() {
    cin >> n >> r >> c;
    int size = 1;
    for (int i = 0; i < n; i++) {
        size *= 2;
    }

    divide(0, 0, size);
}