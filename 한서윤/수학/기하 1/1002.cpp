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

	int t, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, r1, x2, y2, r2, d, rd, rdd;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		rd = (r1 + r2) * (r1 + r2);
		rdd = (r1 - r2) * (r1 - r2);
		if (x1 == x2 && y1 == y2 && r1 == r2) num = -1;
		else if (rdd < d && d < rd) num = 2;
		else if (d == rd || d == rdd) num = 1;
		else num = 0;
		cout << num << '\n';
	}
}