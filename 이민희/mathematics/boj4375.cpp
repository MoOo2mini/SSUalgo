#include <iostream>
using namespace std;

int main() {
    int one = 1;
    int num;
    int result = 0;
    while (!(cin >> num).eof()) {
        one = 1;
        result = 0;
        while (true) {
            if (one % num == 0) {
                result++;
                break;
            } else {
                result++;
                one = one * 10 + 1;
                one %= num;
            }
        }
        cout << result << endl;
    }
}