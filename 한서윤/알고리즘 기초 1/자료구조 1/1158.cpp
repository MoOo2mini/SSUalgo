#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (q.size() - 1) {
		for (int j = 1; j < k; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}