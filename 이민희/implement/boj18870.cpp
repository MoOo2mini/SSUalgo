#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> v, noDup;
    map<int, int> list;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
        noDup.push_back(tmp);
    }
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        list.insert(make_pair(v[i], i));
    }

    for (int i = 0; i < n; i++) {
        cout << list[noDup[i]] << ' ';
    }
}