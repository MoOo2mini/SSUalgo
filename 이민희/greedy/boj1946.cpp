#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> result;
    int n;
    
    for (int repeat = 0; repeat < t; repeat++) {
        cin >> n;
        vector<pair<int, int> > v;
        pair<int, int> p;
        for (int i = 0; i < n; i++) {
            cin >> p.first >> p.second;
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        int flag = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (v[flag].second > v[i].second) {
                cnt++;
                flag = i;
            }

            // if문에 들어가는 조건을 잘 고려하자.. 마구잡이로 풀면 틀림.
        }

        result.push_back(cnt);
    }

    for (int i = 0; i < t; i++) {
        cout << result[i] << '\n';
    }
}