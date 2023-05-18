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
    
    // cout << "sorting" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << tmp[i].first << " " << tmp[i].second << endl;
    // }

    int room = 0;
    int gap = 0;
    int minGap = 200001;
    int minIdx = -1;
    for (int i = 0; i < tmp.size(); i++) {
        minGap = 200001;
        minIdx = -1;
        gap = 0;
        for (int idx = 0; idx <= room; idx++) {
            gap = tmp[i].first - cr[idx];
            if (gap < minGap && gap >= 0) {
                // cout << "mingap : " << gap << endl;
                minGap = gap;
                minIdx = idx;
            } else {
                // cout << "invalid gap : " << gap << "i : " << i << endl;
            }
        }
        if (minIdx == -1) {
            // cout << "invalid in" << endl;
            room++;
            minIdx = room;
        }

        cr[minIdx] = tmp[i].second;
        // cout << minIdx << ", " << tmp[i].second << endl;
    }

    cout << room + 1 << endl;
}