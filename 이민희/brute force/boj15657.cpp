#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int result[8];
bool visited[8];
int inputSeq[10];

void dfs(int cnt, int idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < n; i++) {
        if (cnt - 1 >= 0 && result[cnt - 1] > inputSeq[i]) continue;
        result[cnt] = inputSeq[i];
        dfs(cnt + 1, idx);
    }
}

int main() {
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++)
		cin >> inputSeq[i];
    sort(inputSeq, inputSeq + n);

    dfs(0, 0);
}