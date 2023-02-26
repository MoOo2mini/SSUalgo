#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[8][8];
bool visited[8][8];
int minValue = 70;
int ud[] = {1, 0, -1, 0};
int rl[] = {0, 1, 0, -1};

void test() {
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    pair<int, int> p;
    while (!q.empty()) {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = p.first + ud[i];
            int x = p.second + rl[i];

            if (y < 0 || y >= n) {
                continue;
            }
            if (x < 0 || x >= m) {
                continue;
            }

            if (map[y][x] == 0) {
                map[y][x] = -1;
                q.push(make_pair(y, x));
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                count++;
            }
            if (map[i][j] == -1) {
                count++;
                map[i][j] = 0;
            }
        }
    }
    if (count < minValue) minValue = count;
    // cout << "count : " << count << endl;
}

void dfs(int cnt) {
    if (cnt == 3) {
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        test();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] == 0) {
                visited[i][j] = true;
                map[i][j] = 1;
                dfs(cnt + 1);
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int answer = n * m - 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                answer--;
            }
        }
    }

    dfs(0);

    cout << answer - minValue;
}