#include <bits/stdc++.h>
using namespace std;
void dfs(int);

bool visited[1001];
vector<int> graph[1001];
int count;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m, count = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {  // dfs가 한 번 실행되면 연결요소의 개수++.
            dfs(i);
            count++;
        }
    }
    cout << count;
}

void dfs(int cur) {
    visited[cur] = true;
    for (int next : graph[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}