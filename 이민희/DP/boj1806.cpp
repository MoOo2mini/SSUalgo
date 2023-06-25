#include <iostream>
#include <vector>
using namespace std;
long n, s;

int main() {
    cin >> n >> s;
    vector<long> v;
    long minV = n + 1;
    long cnt;
    long tmp;

    long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        if (tmp == s) {
            cout << 1;
            exit(0);
        }
        v.push_back(tmp);
    }
    if (sum < s) {
        cout << 0;
        exit(0);
    } else if (sum == s) {
        cout << n;
        exit(0);
    }

    long num = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        int idx = i;
        while (num < s) {
            // cout << "idx : " << idx << " v[idx] : " << v[idx] << endl;
            num += v[idx];
            idx++;
            cnt++;
        }
        if (num == s) {
            if (cnt < minV && cnt != 0) {  
                minV = cnt;
            }
        }
        if (num > s) {
            // cout << "in" << endl;
            num = 0;
            continue;
        }

        if (minV == 2) {
            cout << 2;
            exit(0);
        }
    }

    if (minV != n + 1) {
        cout << minV;
    } else {
        cout << 0;
    }
}