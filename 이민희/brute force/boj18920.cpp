#include <iostream>
using namespace std;

int arr[10][10];
bool visited[10][10];
int n, m, k;
int maxValue = -987654321;

void dfs(int cnt, int result) {
    if (cnt == k) {
        if (maxValue < result) {
            maxValue = result;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            if (i + 1 < n && visited[i + 1][j]) continue;
            if (i - 1 >= 0 && visited[i - 1][j]) continue;
            if (j + 1 < m && visited[i][j + 1]) continue;
            if (j - 1 >= 0 && visited[i][j - 1]) continue;
            
            visited[i][j] = true;
            dfs(cnt + 1, result + arr[i][j]);
            visited[i][j] = false;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);
    cout << maxValue;
}