#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x;
    int y;
};
int n,m;
int** matrix;
int visited[3000][3000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int mincnt=INT_MAX;

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
            if(matrix[nx][ny]==1) continue; //장애물 무시
            if(!visited[nx][ny]){
                visited[nx][ny]=visited[a.x][a.y]+1;

                if(matrix[nx][ny]==3||matrix[nx][ny]==4||matrix[nx][ny]==5){
                    if(mincnt>visited[a.x][a.y]){
                        mincnt = visited[a.x][a.y];
                    }
                }
                Node v;
                v.x=nx; v.y=ny;
                q.push(v);
            }
        }
    }
    if(mincnt==INT_MAX){
        cout<<"NIE"; return;
    }
    cout<<"TAK"<<endl;
    cout<< mincnt+1;
}

void solve(){
    int x,y;
    cin>>n>>m;
    matrix = new int*[n];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        matrix[i] = new int[m];
        char* str = new char [m+1];
        cin>>str;
        for(int j=0;j<m;j++){
            matrix[i][j] = str[j]-'0';
            if(matrix[i][j]==2){
                x=i;
                y=j;
            }
        }
    }
    bfs(x,y); //2가 있는 좌표에서 시작

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}