#include <iostream>
using namespace std;
int arr[10001 - 1000];
int main() {
    for (int i = 1000; i < 10000; i++) {
        arr[i - 1000] = i;
    }

    for (int i = 2; i < 10000; i++) {
        for (int j = i * 2; j < 10000; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = 1000; i < 10000; i++) {
        if (arr[i - 1000] != 0) cout << arr[i - 1000] << endl;
    }
}