#include <iostream>
using namespace std;

int main() {
    long long tmp, answer;
    answer = 0;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        answer += tmp;
    }
    cout << answer;
}