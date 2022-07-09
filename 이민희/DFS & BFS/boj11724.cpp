#include <vector>
#include <iostream>
using namespace std;

#define MAX 1001

int N, M;
int map[MAX][MAX];
bool visited[MAX]; //정점 방문 여부

void DFS(int v)
{
    visited[v] = 1;

    for (int i = 1; i <= N; i++){
        if (map[v][i] == 1 && visited[i] == 0) // 인접정점 중 방문하지 않은 것.
            DFS(i);
    }
}

int Components(int count){
    fill(visited, visited + N, false);

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            count++;
        }
    }
    return count;
}

int main(){

    int from, to;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        cin >> from >> to;
        map[from][to] = 1;
        map[to][from] = 1;
    }

    cout << Components(0);
}