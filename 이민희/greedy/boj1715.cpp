#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, tmp; cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int answer = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top(); 
        pq.pop();

        pq.push(a + b);
        answer += a + b;
        // cout << a << " " << b << endl;
    }
    cout << answer;
}