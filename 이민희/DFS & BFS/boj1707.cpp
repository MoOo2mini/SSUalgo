#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_SIZE 20001
#define RED  1
#define BLUE 2

int K, V, E; // 테스트 케이스, 노드, 링크 선언
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];

void bfs(int start);
bool isBipartiteGraph();

void bfs(int start)
{
    queue<int> q;
    int color = RED;

    visited[start] = color;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (visited[now] == RED) // 현재 노드의 색
            color = BLUE; // 반대로 바꾸기
        else if (visited[now] == BLUE)
            color = RED;
        
        int gsize = graph[now].size();
        for (int i = 0; i < gsize; i++){
            // 현재 노드의 인접 노드를 칠하기
            int next = graph[now][i];
            if (!visited[next]) // 인접 노드가 칠해져 있지 않다면
            {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

bool isBipartiteGraph()
{
    for (int i = 1; i <= V; i++)
    {
        int gsize = graph[i].size();
        for (int j = 0; j < gsize; j++)
        {
            int next = graph[i][j];
            if (visited[i] == visited[next]) // 현재 노드 색== 인접 노드 색
                return 0; // return false 
        }
    }
    return 1;
}

int main(){

    int from, to;
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
                bfs(i);
        }

        if (isBipartiteGraph())
            cout << "YES\n";
        else
            cout << "NO\n";

        for (int i = 1; i <= V; i++) {
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
}