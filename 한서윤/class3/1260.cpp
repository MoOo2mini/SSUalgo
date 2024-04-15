#include <bits/stdc++.h>
using namespace std;
void dfs(int);
void bfs(int);

vector<int> graph[1001];
bool visited[1001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);  // u->v 간선 추가.
        graph[v].push_back(u);  // v->u 간선 추가.
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    memset(visited, false, 1001 * sizeof(bool));
    cout << '\n';
    bfs(v);
}

/*
void dfs(int start) { // stack ver.
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout<<start<<' ';

    while(!s.empty()) {
        int cur = s.top();
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                cout<<next<<' ';
                s.push(next);
                visited[next]=true;
                break;
            }
            if(i == graph[cur].size()-1) s.pop();
        }
    }
}
*/

void dfs(int cur) {  // 재귀함수 ver.
    visited[cur] = true;
    cout << cur << ' ';
    for (int next : graph[cur]) {
        if (!visited[next]) dfs(next);
    }
}

void bfs(int cur) {  // queue 사용.
    queue<int> q;
    q.push(cur);
    visited[cur] = true;

    while (!q.empty()) {
        cout << cur << ' ';
        q.pop();
        for (int next : graph[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
        cur = q.front();
    }
}