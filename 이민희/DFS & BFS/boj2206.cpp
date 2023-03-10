#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
// bool map[1000][1000];
int visited[1000][1000][2];

int bfs(vector<string> map) {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0][1] = 1;
    pair<pair<int, int>, int> p;

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p.first.first == n - 1 && p.first.second == m - 1) {
            return visited[p.first.first][p.first.second][p.second];
        }

        for (int i = 0; i < 4; i++) {
            int y = p.first.first + dy[i];
            int x = p.first.second + dx[i];

            if (y >= 0 && x >= 0 && y < n && x < m) {
                // 벽이 아직 안뚫렸고, 뚫을 수 있음.
                if (map[y][x] == '1' && p.second == 1) {
                    q.push(make_pair(make_pair(y, x), 0));
                    visited[y][x][0] = visited[p.first.first][p.first.second][1] + 1;
                }
                // 다음 칸이 벽이 아니고, 방문 가능함.
                else if (map[y][x] == '0' && visited[y][x][p.second] == 0) {
                    q.push(make_pair(make_pair(y, x), p.second));
                    visited[y][x][p.second] = visited[p.first.first][p.first.second][p.second] + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    int tmp;
    cin >> n >> m;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         scanf("%1d", &map[i][j]);
    //     }
    // }
    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    
    cout << bfs(graph);
}