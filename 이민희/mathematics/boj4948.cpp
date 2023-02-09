#include <iostream>
#include <vector>
using namespace std;

bool notprime[123456 * 2];

void init() {
    notprime[1] = true;

    for (int i = 2; i <= 123456 * 2; i++) {
        for (int j = (i * 2); j <= 123456 * 2; j += i) {
            notprime[j] = true;
        }
    }
}

int countPrime(int num) {
    int result = 0;
    for (int i = num + 1; i <= num * 2; i++) {
        if (!notprime[i]) {
            result++;
        }
    }

    return result;
}

int main() {
    init();
    vector<int> v;
    vector<int> result;
    int tmp;

    while (true) {
        cin >> tmp;
        if (tmp == 0) {
            break;
        }
        v.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++) {
        result.push_back(countPrime(v[i]));
    }

    for (int i = 0; i < v.size(); i++) {
        cout << result[i] << endl;
    }
}