#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, m;
int arr[8];
bool visited[8];
vector<int> answer;

void dfs(int cnt, int idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
        return;
    }
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        if (tmp != arr[i] && !visited[i]) {
            tmp = arr[i];
            visited[i] = true;
            answer.push_back(arr[i]);
            dfs(cnt + 1, i);
            visited[i] = false;
            answer.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    dfs(0, 0);
}