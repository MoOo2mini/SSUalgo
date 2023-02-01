#include <iostream>
using namespace std;

int main() {
    int index = 'z' - 'a' + 1;
    int arr[index];

    for (int i = 0; i < index; i++) {
        arr[i] = 0;
    }

    string c;
    cin >> c;

    for (int i = 0; c[i] != '\0'; i++) {
        int index = c[i] - 'a';
        arr[index]++;
    }

    for (int i = 0; i < index; i++) {
        cout << arr[i];
        if (i + 1 != index) {
            cout << ' ';
        }
    }
}