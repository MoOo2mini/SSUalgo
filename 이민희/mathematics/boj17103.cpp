#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;
bool notprime[MAX];
int t;

void init() {
    notprime[0] = true;
    notprime[1] = true;
    for (int i = 2; i < MAX; i++) {
        if (notprime[i]) continue;
        for (int j = i * 2; j < MAX; j += i) {
            notprime[j] = true;
        }
    }
}

int main() {
    int tmp;
    cin >> t;

    vector<int> v;

    int result = 0;
    init();
    for (int i = 0; i < t; i++) {
        result = 0;
        cin >> tmp;
        for (int i = 2; i <= tmp / 2; i++) {
            if (!notprime[i] && !notprime[tmp - i]) {
                result++;
            }
        }
        v.push_back(result);
    }

    for (int i = 0; i < t; i++) {
        cout << v[i] << endl;
    }
}