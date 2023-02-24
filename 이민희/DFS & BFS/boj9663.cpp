#include <iostream>
using namespace std;

bool visited[16][16];
int n;
int result;

bool canVisited(int y, int x) {
    // 행
    for (int i = 0; i < n; i++) {
        if (visited[y][i]) {
            return false;
        }
    }

    // 열
    for (int i = 0; i < n; i++) {
        if (visited[i][x]) {
            return false;
        }
    }

    // 대각선 오른쪽
    for (int i = 1; (y - i >= 0 && x + i < n); i++) {
        if (visited[y - i][x + i]) {
            return false;
        }
    }

    for (int i = 1; (y - i >= 0 && x - i >= 0); i++) {
        if (visited[y - i][x - i]) {
            return false;
        }
    }
    return true;
}

void dfs(int cnt) {
    if (cnt == n) {
        result++;
        return;
    }
    for (int i = 0; i < n; i++) {
        // 놓을 수 있는가?
        if (!canVisited(cnt, i)) {
            continue;
        }
        visited[cnt][i] = true;
        dfs(cnt + 1);
        visited[cnt][i] = false;
    }
}

int main() {
    cin >> n;
    dfs(0);

    cout << result;
}
