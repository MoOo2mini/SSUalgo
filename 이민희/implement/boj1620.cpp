#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    string tmp;
    map<string, int> m;
    vector<string> name, result;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        m.insert(make_pair(tmp, i + 1));
        name.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        if (tmp[0] >= 'A' && tmp[0] <= 'Z') {
            result.push_back(to_string(m[tmp]));
        } else {
            result.push_back(name[stoi(tmp) - 1]);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}