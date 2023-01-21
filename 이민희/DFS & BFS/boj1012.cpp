#include <iostream>
#include <queue>
using namespace std;

int arr[51][51];
int visited[51][51];

int height[] = {0, 0, -1, 1};
int width[] = {1, -1, 0, 0};

void reset() {
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            arr[i][j] = 0; visited[i][j] = 0;
        }
    }
}

void DFS(int x, int y) {
    visited[x][y] = 5;

    for (int i = 0; i < 4; i++) {
        int new_width = x + width[i];
        int new_height = y + height[i];

        if (arr[new_width][new_height] == 1 && visited[new_width][new_height] == 0) {
            DFS(new_width, new_height);
        }
    }
}

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int result = 0;

        reset();

        int m, n, k;
        cin >> m >> n >> k;

        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int now_point = arr[i][j];
                
                if (now_point == 1 && visited[i][j] == 0) {
                    DFS(i, j);
                    result++;
                }
            }
        }
        cout << result << endl;
    }
}