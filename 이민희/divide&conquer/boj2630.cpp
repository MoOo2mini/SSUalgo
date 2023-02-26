#include <iostream>
using namespace std;
int n;
bool map[128][128];
int white, blue;

void divide(int y, int x, int size) {
    bool full = true;
    bool standard = map[y][x];
    if (size == 0) {
        return;
    }
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (map[i][j] != standard) {
                //divide
                full = false;
                divide(y, x, size / 2);
                divide(y, x + (size / 2), size / 2);
                divide(y + (size / 2), x, size / 2);
                divide(y + (size / 2), x + (size / 2), size / 2);
                return;
            }
        }
    }
    if (full) {
        if (standard == 0) {
            white++;
        } else if (standard == 1) {
            blue++;
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    divide(0, 0, n);
    // divide(n / 2, 0, n / 2);
    // divide(0, n / 2, n / 2);
    // divide(n / 2, n / 2, n / 2);

    cout << white << endl << blue << endl;
}