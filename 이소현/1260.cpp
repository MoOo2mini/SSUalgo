#include <bits/stdc++.h>

using namespace std;

vector<int> vec[10002];
bool visited[1002];

void dfs(int v){
    visited[v]=true;
    cout<<v<<" ";

    for(int i=0;i<vec[v].size();i++){
        if(!visited[vec[v][i]]){
            dfs(vec[v][i]);
        }
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v]=true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        for(int i=0;i<vec[x].size();i++){
            if(!visited[vec[x][i]]){
                q.push(vec[x][i]);
                visited[vec[x][i]]=true;
            }
        }
    }
}

void solve(){
    int n, m, v, a, b;
    cin>>n>>m>>v;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        vec[a].push_back(b); //양방향 간선처리
        vec[b].push_back(a); //양방향 간선처리
    }
    for (int i = 1; i <= n;i++){
        sort(vec[i].begin(), vec[i].end()); // 낮은 숫자부터 탐색.
    }

    memset(visited,false,sizeof(visited));
    dfs(v);
    memset(visited,false,sizeof(visited));
    cout<<'\n';
    bfs(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}