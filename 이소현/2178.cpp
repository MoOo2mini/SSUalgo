#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x;
    int y;
};
int n,m;
int** matrix;
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    Node v;
    v.x=x; v.y=y;
    queue<Node> q;
    q.push(v);

    while(!q.empty()){
        Node a = q.front();
        q.pop();

         for (int i = 0; i < 4; i++)
        {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            // 미로 공간을 벗어난 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(matrix[nx][ny]==0) continue;
            if(matrix[nx][ny]==1){
                matrix[nx][ny]=matrix[a.x][a.y]+1;
                Node v;
                v.x=nx; v.y=ny;
                q.push(v);
            }
        }
    }
    cout<< matrix[n-1][m-1];
}

void solve(){
    cin>>n>>m;
    matrix = new int*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int[m];
        char* str = new char [m+1];
        cin>>str;
        for(int j=0;j<m;j++){
            matrix[i][j] = str[j]-'0';
        }
    }
    bfs(0,0);



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}