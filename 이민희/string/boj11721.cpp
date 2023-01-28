#include <iostream>
using namespace std;

int main() {
    char arr[101];
    cin >> arr;

    for (int i = 0; arr[i] != '\0'; i++) {
        cout << arr[i];
        
        if ((i + 1) % 10 == 0) {
            cout << '\n';
        }
    }
}