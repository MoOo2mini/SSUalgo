#include <iostream>
#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int minV = 1000000;
bool reachable;

int map[1000][1000];
bool visited[1000][1000];

int bfs() {
    int tmp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = map[i][j];
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    pair<int, int> p;

    while (!q.empty()) {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = p.first + dy[i];
            int x = p.second + dx[i];

            if (y >= 0 && x >= 0 && y < n && x < m && !visited[y][x] && map[y][x] == 0) {
                if (y == n - 1 && x == m - 1) reachable = true;
                visited[y][x] = true;
                tmp[y][x] = tmp[p.first][p.second] + 1;
                if (tmp[y][x] >= minV) return minV;
                q.push(make_pair(y, x));
            }
        }
    }
    return tmp[n - 1][m - 1] + 1;
}

int main() {
    int tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                // 1을 제거하고 돌려!
                map[i][j] = 0;
                tmp = bfs();
                if (tmp < minV && tmp != 1) minV = tmp;
                // 다시 1을 넣어줘
                map[i][j] = 1;
            }
            // map & visited 초기화
            memset(visited, 0, 1000 * 1000 * sizeof(bool));
        }
    }

    if (!reachable) {
        cout << -1;
    } else {
        cout << minV;
    }
}