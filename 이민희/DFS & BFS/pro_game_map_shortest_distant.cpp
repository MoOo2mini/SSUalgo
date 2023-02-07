#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int width[] = {1, -1, 0, 0}; // 동, 서, 남, 북
int height[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); // 세로
    int m = maps[0].size(); // 가로
    
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    dist[0][0] = 1;
    
    pair<int, int> p;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int y = p.first + height[i];
            int x = p.second + width[i];
            if (x < 0 || y < 0 || n <= y || m <= x) {
                continue;
            }
            if (maps[y][x] == 1 && visited[y][x] == false) {
                q.push(make_pair(y, x));
                visited[y][x] = true;
                dist[y][x] = dist[p.first][p.second] + 1;
            }
        }
    }
    
    if (!visited[n - 1][m - 1]) { 
        return -1;
    }
    return dist[n - 1][m - 1];
}