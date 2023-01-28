#include <iostream>
using namespace std;

int main() {
    char arr[101];
    int c;

    cin >> c;
    cin >> arr;

    int result = 0;
    for (int i = 0; i < c; i++) {
        result += arr[i] - '0';
    }

    cout << result;
}