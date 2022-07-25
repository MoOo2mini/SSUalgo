#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
bool visited[101][101];
int result[101][101];

int n, m; // n = height, m = width

int height[] = {0, 0, -1, 1};
int width[] = {1, -1, 0, 0};

int main(){
    cin >> n >> m;

    for (int i=0; i<n; ++i){            // 미로 입력

        string row;                     // 행 입력
        cin >> row;

        for (int j=0; j<m; ++j){        // 행 별 좌표값 저장
            map[i][j] = row[j]-'0';    // 행 별 좌표값들은 문자 형태이기 때문에, 숫자로 변환
        }
    }

    int y = 0;
    int x = 0;
    visited[y][x] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    result[y][x]++;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int y_new = y + height[i];
            int x_new = x + width[i];
            if ((0 <= x_new && x_new < m) && (0 <= y_new && y_new < n) && (!visited[y_new][x_new] && map[y_new][x_new] == 1 )) {
                visited[y_new][x_new] = true;
                q.push(make_pair(y_new, x_new));
                result[y_new][x_new] = result[y][x] + 1;
            }
        }
    }

    cout << result[n-1][m-1];
}