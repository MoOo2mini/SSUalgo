#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ft_print(int i, int j, vector<int> v) {
    for (int m = 0; m < 9; m++) {
        if (m == i || m == j) {
            continue;
        }
        cout << v[m] << endl;
    }
}

int main() {
    vector<int> v;

    int sum = 0;
    int tmp;
    for (int i = 0; i < 9; i++) {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int flag = sum - 100;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (v[i] + v[j] == sum - 100) {
                ft_print(i, j, v);
                return 0;
            }
        }
    }
}