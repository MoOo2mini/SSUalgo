#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2, n, cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		for (int j = 0; j < n; j++) {
			int cx, cy, r, sd, fd;
			cin >> cx >> cy >> r;
			sd = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
			fd = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
			r *= r;
			if (sd < r || fd < r) cnt++; // 출발점 || 도착점이 원 안에 있으면 +1
			if (sd < r && fd < r) cnt--; // 출발점과 도착점이 모두 원 안에 있으면 -1
		}
		cout << cnt << '\n';
	}
}