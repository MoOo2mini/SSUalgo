#include <iostream>
#include <deque>
using namespace std;
int n, k;
bool visited[200001];

int main() {
    cin >> n >> k;
    deque<pair<int, int> > q;

    q.push_back(make_pair(n, 0));
    visited[n] = true;

    pair<int, int> front;
    while (!q.empty()) {
        front = q.front();
        q.pop_front();
        if (front.first == k) {
            cout << front.second;
        }

        if (front.first * 2 < 200001 && !visited[front.first * 2]) {
            visited[front.first * 2] = true;
            q.push_front(make_pair(front.first * 2, front.second));
        }
        if (front.first + 1 < 200001 && !visited[front.first + 1]) {
            visited[front.first + 1] = true;
            q.push_back(make_pair(front.first + 1, front.second + 1));
        }
        if (front.first - 1 >= 0 && !visited[front.first - 1]) {
            visited[front.first - 1] = true;
            q.push_back(make_pair(front.first - 1, front.second + 1));
        }
    }
}