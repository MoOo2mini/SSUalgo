#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 1;
    int sum = 0;
    while (sum <= n) {
        sum += result;
        result++;
    }

    cout << result - 2;
}

// 자꾸 틀렸다고 할 때는.. 숫자의 크기를 보자. long long을 쓸지 int를 쓸지 판별하기