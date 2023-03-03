#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> v[100001];
bool visited[100001];
int ans[100001];

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < v[parent].size(); i++) {
            int child = v[parent][i];
            if (visited[child]) continue;
            visited[child] = true;
            q.push(child);
            ans[child] = parent;
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    bfs();

    for(int i = 2; i <= n; i++) 
        cout << ans[i] << "\n"; 
}
