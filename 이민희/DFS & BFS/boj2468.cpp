#include <iostream>
using namespace std;

int arr[100 + 1][100 + 1];
int visited[100 + 1][100 + 1];
int n;
int width[] = { 0,0,1,-1 };
int height[] = { 1,-1,0,0 };

void reset(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            visited[i][j] = 0;
        }
    }
}

void DFS(int x, int y, int flag) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int new_width = x + width[i];
        int new_height = y + height[i];

        if (new_width < 0 || new_width >= n || new_height < 0|| new_height >= n)
		{
			continue;
		}

        if (arr[new_width][new_height] >= flag && visited[new_width][new_height] == 0) {
            DFS(new_width, new_height, flag);
        }
    }
}

int main() {
    cin >> n;

    int min = 100;
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }

    int ans = 1;
    
    for (int flag = min; flag <= max; flag++) {
        int count = 0;
        reset(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && arr[i][j] >= flag) {
                    count++;
                    DFS(i, j, flag);
                }
            }

            if (count > ans)
            {
                ans = count;
            }
        }
    }

    cout << ans;
}

// 미로찾기는 bfs로 하는 것이 효율적.