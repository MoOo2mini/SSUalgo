#include <iostream>
using namespace std;
int n;
int arr[15][2];
bool visited[15];
int maxValue = 0;
void dfs(int day, int result) {
    if (day + arr[day][0] > n) {
        if (maxValue < result) maxValue = result;
        return;
    } else if (day + arr[day][0] == n) {
        result += arr[day][1];
        if (maxValue < result) maxValue = result;
        return;
    }
    for (int i = day; i < n; i++) {
        if (i + arr[day][0] >= n) {
            continue;
        }
        visited[i + arr[day][0]] = true;
        // cout << day + 1 << "일 " << arr[day][1] << ", ";
        dfs(i + arr[day][0], result + arr[day][1]);
        visited[i + arr[day][0]] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    dfs(0, 0);
    cout << maxValue;
}