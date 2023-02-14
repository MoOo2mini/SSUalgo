#include <iostream>
#include <cmath>
using namespace std;

int dp[1000];
bool numbers[100001];

void init() {
    numbers[1] = true;
    for (int i = 2; i * i <= 100000; i++) {
        numbers[i * i] = true;
    }
}
int main() {
    init();

    int n;
    cin >> n;
    for (int i = n; i > 0; i++) {

    }
}