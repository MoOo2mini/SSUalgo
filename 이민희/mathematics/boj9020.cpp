#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool notprime[10001];

void init() {
    notprime[0] = true;
    notprime[1] = true;
    for (int i = 2; i <= 10000; i++) {
        if (notprime[i]) {
            continue;
        }
        for (int j = i*2; j <= 10000; j += i) {
            notprime[j] = true;
        }
    }
}

pair<int, int> getPartition(int num) {
    int tmp = 10000;
    pair<int, int> result;
    for (int i = 2; i <= num; i++) {
        if (!notprime[i] && !notprime[num - i]) {
            int large = max(num - i, i);
            int small = min(num - i, i);
            if (tmp > (large - small)) {
                tmp = large - small;
                result = make_pair(small, large);
            }
        }
    }

    return result;
}

int main() {
    int n, a;
    cin >> n;

    init();
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(getPartition(a));
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}