#include <bits/stdc++.h>
using namespace std;
void dfs(int cur);

vector<int> graph[101];
bool visited[101];
vector<int> virus;  // 방문한 노드 저장.

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    cout << virus.size() - 1;
}

void dfs(int cur) {
    visited[cur] = true;
    virus.push_back(cur);
    for (int next : graph[cur]) {
        if (!visited[next]) dfs(next);
    }
}