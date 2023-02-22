#include <iostream>
using namespace std;

int n, m, r;
int arr[100][100];

void one() {
    int* tmp;

    for (int i = 0; i < n / 2; i++) {
        // i -> (n - 1) - i;
        tmp = arr[i];
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[n - 1 - i][j];
            arr[n - 1 - i][j] = tmp[j];
        }
    }
}

void two() {
    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[i][m - 1 - j];
            arr[i][m - 1 - j] = tmp;
        }
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int number;
    for (int i = 0; i < r; i++) {
        cin >> number;
        if (number == 1) {
            one();
        } else if (number == 2) {
            two();
        } else if (number == 3) {
            three();
        // } else if (number == 4) {
        //     four();
        // } else if (number == 5) {
        //     five();
        // } else if (number == 6) {
        //     six();
        // }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}