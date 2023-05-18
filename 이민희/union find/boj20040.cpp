#include <iostream>
#include <vector>
using namespace std;
int parent[500001];

int getParent(int x) {
    if (parent[x] == x) return parent[x];
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else {
        if (a > b) parent[a] = b;
        else parent[b] = a;
    }
    return false;
}

int main() {
    int n, m, a, b;
    int answer = 0;
    vector<pair<int, int> > v;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (unionParent(a, b)) {
            answer = i;
            break;
        }
    }
    cout << answer;

}