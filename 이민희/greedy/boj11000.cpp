#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cr[200000 + 1];

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second <= b.second) {
        return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    int a, b;
    vector<pair<int, int> > tmp;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        tmp.push_back(make_pair(a, b));
    }

    sort(tmp.begin(), tmp.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << tmp[i].first << " " << tmp[i].second << endl;
    }
    // int room = 0;
    // for (int i = 0; i < tmp.size(); i++) {
    //     for (int idx = 0; idx <= room; idx++) {
    //         if (cr[idx] <= tmp[i].first) {
    //             cr[idx] = tmp[i].second;
    //             cout << "class " << idx + 1 << endl;
    //             break;
    //         } else {
    //             room++;
    //         }
    //     }
    // }
    // cout << room  + 1 << endl;
}