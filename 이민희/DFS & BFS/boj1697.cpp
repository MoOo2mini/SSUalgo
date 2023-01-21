#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    int second = 0;

    cin >> n >> k;

    queue<int> q;
    int visited[200004] = {0, };

    q.push(n);
    visited[n] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == k) {
            cout << visited[k] - 1;
            return 0;
        }

        if (visited[front + 1] == 0 && front + 1 <= 100000) {
            visited[front + 1] = visited[front] + 1;
            q.push(front + 1);
        }
        if (visited[front - 1] == 0 && front - 1 >= 0) {
            visited[front - 1] = visited[front] + 1;
            q.push(front - 1);
        }
        if (visited[front * 2] == 0 && front * 2 <= 100000) {
            visited[front * 2] = visited[front] + 1;
            q.push(front * 2);
        }
    }
}