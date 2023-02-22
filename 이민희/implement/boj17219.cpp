#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    string site, name;
    cin >> n >> m;

    vector<string> v;
    map<string, string> list;
    for (int i = 0; i < n; i++) {
        cin >> site >> name;
        list.insert(make_pair(site, name));
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        v.push_back(list[site]);
    }

    for (int i = 0; i < m; i++) {
        cout << v[i] << endl;
    }
}