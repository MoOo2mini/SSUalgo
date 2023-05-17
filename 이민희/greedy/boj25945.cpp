#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    int n, tmp;
    int sum = 0;
    vector<int> m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        m.push_back(tmp);
    }

    sort(m.begin(), m.end(), comp);

    int average = sum / n;
    int maxV = sum % n;
    int i = 0;

    int answer = 0;
    while (m[i] > average) {
        if (maxV) {
            answer += abs(average + 1 - m[i]);
            maxV--;
        } else {
            answer += abs(average - m[i]);
        }
        i++;
    }

    cout << answer;
}