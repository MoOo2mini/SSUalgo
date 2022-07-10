#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node]=true;
	for (int i=0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=1; i<=n; i++) {		// 사용한 공간 초기화
			a[i].clear();
			check[i]=false;
		}
		for (int i=1; i<=n; i++) {		// 방향 그래프 입력
			int v;
			cin >> v;
			a[i].push_back(v);
		}
		int cnt=0;
		for (int i=1; i<=n; i++) {		// 각 탐색마다 count + 1
			if (!check[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}