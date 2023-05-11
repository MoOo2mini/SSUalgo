#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long getMax(int n) {
    long long answer = 0;
    for (int i = 0; i < n + 1; i++) {
        answer += (long long) pow(2, i);
    }   

    return (answer * (n + 1) + n);
}

int main() {
    vector<long long> v;
    long long n;

    cin >> n;

    long long tmp = 0;
    long long answer = 1;
    while (tmp < n) {
        tmp = getMax(answer++);
        // cout << tmp << " " << answer << endl;
    }

    cout << answer - 1;
}