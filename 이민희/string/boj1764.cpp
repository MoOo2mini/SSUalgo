#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    map<string, bool> hear;
    vector<string> result;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        hear.insert(make_pair(tmp, true));
    }
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        if (hear[tmp]) {
            result.push_back(tmp);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}