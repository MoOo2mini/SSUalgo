#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1001

int n, m, v, from, to;
int map[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; //정점 방문 여부
queue<int> q;
vector<int> e[1001];

void reset() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}

void dfs(int v) {
    visited[v] = 1;
    cout << v << ' ';

    for (int i = 1; i <= n; i++) {
        if (map[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    visited[v] = 1;
    q.push(v);
    
    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= n; w++) {
            if (map[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = 1;
                cout << w << ' ';
            }
        }
    }
}

void DFS(int v)
{
    visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= n; i++){
        if (map[v][i] == 1 && visited[i] == 0) // 인접정점 중 방문하지 않은 것.
            DFS(i); // stack에 함수가 쌓이고 있음.
    }
}

void BFS(int v)
{
    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= n; w++) {
            if (map[v][w] == 1 && visited[w] == 0) { //현재 정점과 인접노드이고 방문되지 않았으면
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
		cin >> from >> to;
		map[from][to] = 1;
        map[to][from] = 1;
	}
 
    reset();
    DFS(v);
    
    cout << '\n';
    
    reset();
    BFS(v);
  
	return 0;
}