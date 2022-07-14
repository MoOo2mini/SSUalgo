#include <iostream>
using namespace std;

#define MAX 51

int n, m;
int map[MAX][MAX];
int visit[MAX][MAX];
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void mem_clear(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            map[i][j] = 0;
            visit[i][j] = 0;
        }
}

void dfs(int y, int x){
    visit[y][x] = 1;

    for (int i = 0; i < 8; i++)
    {
        int ny = y + dy[i]; // now y
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;

        if (map[ny][nx] == 1 && visit[ny][nx] == 0)
            dfs(ny, nx);
    }
}

int main(){
    int count;
    while (1)
    {
        count = 0;
        cin >> m >> n;
        if (n==0 && m==0)   break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> map[i][j];
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] && !visit[i][j])
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << '\n';
        mem_clear();
    }
}