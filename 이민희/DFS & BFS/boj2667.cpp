
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
const int MAX = 25;
int N;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dy[] = { 0,0,1,-1 }; // --> 오 왼 위 아래 순서
int dx[] = { 1,-1,0,0 };
int label = 1;
vector<int> v;
int house = 0;
 
void DFS(int y, int x) {
    visited[y][x] = true;
    map[y][x] = label; // 단지의 개수
    house++; // 단지 안의 집의 개수
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
 
        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            DFS(ny, nx);
        }
    }
}
 
int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
 
        for (int j = 0; j < N; j++) {
            map[i][j] = input.at(j) - '0'; // map에 정수의 형태로 넣어주기
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                DFS(i, j);
                label++;
                v.push_back(house);
                house = 0;
            }
        }
    }
 
    sort(v.begin(), v.end()); // 단지 내 집의 개수 오름차순으로 출력
 
    cout << label - 1 << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
 
}
