#include <iostream>
#include <queue>
using namespace std;

#define MAX 1002

struct tomato {
    int y, x;
};

int n, m;
int result;
queue<tomato> q;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(void) {
    while (!q.empty()) {
        // 큐의 현재 원소(익은 토마토(1))를 꺼내기
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
 
        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            // 지도를 벗어나지 않고, 익지않은 토마토(0)라면
            if (IsInside(ny,nx) == 1 && map[ny][nx] == 0) {
                map[ny][nx] = map[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            if (map[i][j] == 1) { // 익은토마토(1) -> 큐
                q.push({i,j});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 익지않은 토마토(0)가 존재할 경우
            if (map[i][j] == 0) { 
                cout << "-1\n";
                return 0;
            }

            // 토마토는 다 익었는데, 얼마만에 익었는지? find max value
            if (result < map[i][j]) {
                result = map[i][j];
            }
        }
    }

    cout << (result - 1);
}